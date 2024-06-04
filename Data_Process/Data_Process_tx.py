import csv
from firebase_mod.firebase_helper import FirebaseHelper
from firebase_mod.firebase_config import firebaseConfig, service_account_path
import glob
import os
import time
from datetime import datetime
from queue import Queue
from threading import Thread
import requests
import logging
import random
import pandas as pd
import cv2
from txt_helper import txt_data
import shutil

#GLOBAL VARS
total_harvested_fruits = 0
total_detected_fruits = 0
csv_path = "/home/px/Documents/GitHub/IDP/Data_Process/data.csv"
location_idx = 1
sleep_time = 10
internet_availability = True
offline_img_dir = 1
offline_img__dir_str = ""
offline_location_idx = location_idx
detected_img_path = "/home/px/Documents/GitHub/IDP/Data_Process/detected_pics/detected.jpg"

#LOGGER CFG
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


#GET MACHINE DATA
def update_location_and_fruit_data(queue):
    global total_harvested_fruits, total_detected_fruits, sleep_time
    while True:
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

        # change to read from GPS
        machine_latitude = 3.11638+random.uniform(-0.00005, 0.00005)
        machine_longitude = 101.65590 + random.uniform(-0.00005, 0.00005)

        # change to read from txt file
        fruit_data = txt_data('/home/px/Documents/GitHub/IDP/Data_Process/fruit_data.txt')

        glob_directory = "/home/px/Documents/GitHub/IDP/Data_Process/detected_pics"
        jpeg_files = glob.glob(glob_directory + "/*.jpg")
        if len(jpeg_files) > 0:
            fruit_data.detected_fruits = 0
            fruit_data.harvested_fruits = 0

        # Enqueue data
        queue.put((timestamp, machine_latitude, machine_longitude, fruit_data.detected_fruits, fruit_data.harvested_fruits))
        time.sleep(sleep_time)  # Sleep for 10 seconds


#WRITE TO CSV FILE
def clear_csv_file():
    df_csv = pd.DataFrame(columns=['Timestamp', 'Machine_Latitude', 'Machine_Longitude', 'Detected_Fruits', 'Harvested_Fruits'])
    df_csv.to_csv(csv_path, index=False)


def write_to_csv(queue):
    while True:
        data = queue.get()
        print(data)
        if data:
            # Read DataFrame
            dataframe = pd.read_csv(csv_path)
            date = data[0]
            new_row = pd.DataFrame([[date, data[1], data[2], data[3], data[4]]],
                                   columns=['Timestamp', 'Machine_Latitude', 'Machine_Longitude', 'Detected_Fruits', 'Harvested_Fruits'])


            # Ensure that the DataFrame dtypes are consistent
            new_row = new_row.astype(dataframe.dtypes)

            # Concatenate DataFrames
            dataframe = pd.concat([dataframe, new_row], ignore_index=True)

            # Write DataFrame back to CSV
            dataframe.to_csv(csv_path, index=False)

            logger.info("Data written to CSV")


# UPLOADING DATA TO FIREBASE
def is_internet_available():
    try:
        response = requests.get('http://www.google.com', timeout=5)
        return True if response.status_code == 200 else False
    except requests.ConnectionError:
        logger.error("Connection error occurred while trying to reach www.google.com")
        return False
    except requests.Timeout:
        logger.error("Timeout occurred while trying to reach www.google.com")
        return False


def read_csv(filepath):
    location_name ="location"
    global location_idx, offline_location_idx
    coordinates = []
    with open(filepath, mode='r', newline='') as file:
        csv_reader = csv.reader(file)

        # Optionally, get the header
        headers = next(csv_reader, None)

        # Read each row of the CSV file
        for row in csv_reader:
            if row[1] != "":
                new_location = location_name + str(location_idx)
                date_time = row[0].split()
                new_coordinates = {"date": date_time[0], "time": date_time[1], "name": new_location,
                                   "lat": float(row[1]), "lon": float(row[2]), "detected": int(row[3]),
                                   "harvested": int(row[4])}
                coordinates.append(new_coordinates)
                location_idx += 1
                offline_location_idx = location_idx

        return coordinates


def read_csv_last(filepath):
    location_name ="location"
    global offline_location_idx, location_idx
    coordinates = []
    with open(filepath, mode='r', newline='') as file:
        csv_reader = csv.reader(file)

        # Optionally, get the header
        headers = next(csv_reader, None)

        # Read each row of the CSV file
        for row in csv_reader:
            if row[1] != "":
                new_location = location_name + str(offline_location_idx)
                date_time = row[0].split()
                new_coordinates = {"date": date_time[0], "time": date_time[1], "name": new_location,
                                   "lat": float(row[1]), "lon": float(row[2]), "detected": int(row[3]),
                                   "harvested": int(row[4])}

        offline_location_idx+= 1
        return [new_coordinates]


def upload_robot_images(uploaded_file_path):
    directory = "/home/px/Documents/GitHub/IDP/Data_Process/robot_location"
    jpeg_files = glob.glob(directory + "/*.jpg")
    for file in jpeg_files:
        uploaded_file_path = r"robot_location/POV.jpg"
        firebase_helper.upload_image(file, uploaded_file_path)


def upload_images(uploaded_file_path, internet):
    # global internet_availability
    # directory = "detected_pics"
    # jpeg_files = glob.glob(directory + "/*.jpg")
    # for file in jpeg_files:
    #     uploaded_file_path = directory + "/" + uploaded_file_path + "/" + file.split("\\")[1]
    #     firebase_helper.upload_image(file, uploaded_file_path)
    #     try:
    #         os.remove(file)
    #         print(f"Deleted file: {file}")
    #     except Exception as e:
    #         print(f"Failed to delete {file}. Reason: {e}")
    global offline_img_dir, offline_img_dir_str, detected_img_path

    directory = "detected_pics"
    glob_directory = "/home/px/Documents/GitHub/IDP/Data_Process/detected_pics"
    jpeg_files = glob.glob(glob_directory + "/*.jpg")
    if len(jpeg_files) > 0:
        print(uploaded_file_path)
        offline_img_dir_str = directory + "/" + uploaded_file_path
        uploaded_file_path = directory + "/" + uploaded_file_path + "/" + detected_img_path.split("/")[-1]

        if not os.path.exists(offline_img_dir_str): os.makedirs(offline_img_dir_str)
        shutil.copy2(detected_img_path, offline_img_dir_str)
        os.remove(detected_img_path)
        offline_img_dir += 1
    
        if internet:
            items = os.listdir(directory)
            dates = [item for item in items if os.path.isdir(os.path.join(directory, item))]

            for date in dates:
                date_path = os.path.join(directory, date)
                location = os.listdir(date_path)
                for loc in location:
                    location_path = os.path.join(date_path, loc)
                    jpeg_files = glob.glob(location_path + "/*.jpg")
                    for file in jpeg_files:
                        firebase_helper.upload_image(file, uploaded_file_path)
                        try:
                            os.remove(file)
                        except Exception as e:
                            print(f"Failed to delete {file}. Reason: {e}")
                    os.rmdir(location_path)
                os.rmdir(date_path)
    else:
        with open('/home/px/Documents/GitHub/IDP/Data_Process/fruit_data.txt', 'w') as file:
            file.write(f"detected:0\n")
            file.write(f"harvested:0")
            file.close()

#UPLOAD ALL DATA TO FIREBASE
def upload_data(coordinates, internet=True):
    for coordinate in coordinates:
        day = coordinate['date'].replace("/", "")
        example_data = {
            "timestamp" : coordinate['time'],
            "latitude": coordinate['lat'],
            "longitude": coordinate['lon'],
            "palm oils detected": coordinate['detected'],
            "palm oils harvested": coordinate['harvested']
        }
        location = coordinate['name']
        word_to_split_by = "location"
        split_strings = location.split(word_to_split_by)
        if int(split_strings[1])<10:
            split_strings[1] = "0" + split_strings[1]
        coordinate['name'] = "location" + split_strings[1]

        data_path = day + "/" + coordinate['name']

        if internet:
            # Call upload_data function, multhreading to increase upload speed
            upload_data_thread = Thread(target=firebase_helper.upload_data, args=(example_data, data_path))
            upload_img_thread = Thread(target=upload_images, args=(data_path, internet))
            upload_robot_img_thread = Thread(target=upload_robot_images, args=(data_path,))

            upload_data_thread.start()
            upload_img_thread.start()
            upload_robot_img_thread.start()

            upload_data_thread.join()
            upload_img_thread.join()
            upload_robot_img_thread.join()
        else:
            upload_img_thread = Thread(target=upload_images, args=(data_path, internet))
            upload_img_thread.start()
            upload_img_thread.join()
        # firebase_helper.upload_data(example_data, data_path)
        # upload_images(data_path)
        # upload_robot_images(data_path)


def upload_to_firebase():
    global internet_availability
    while True:
        logger.info("Uploading to Firebase")
        internet_availability = is_internet_available()
        if internet_availability:
            internet_availability = True
            coordinates = read_csv(csv_path)
            upload_data(coordinates)
            print("data uploaded to firebase")
            clear_csv_file()
            time.sleep(sleep_time)
            # break
        else:
            internet_availability = False
            coordinates = read_csv_last(csv_path)
            print(coordinates)
            upload_data(coordinates, False)
            time.sleep(sleep_time)


if __name__ == "__main__":
    firebase_helper = FirebaseHelper(firebaseConfig, service_account_path)

    clear_csv_file()

    # Initialize the queue
    queue = Queue()

    # Create and start the threads
    thread1 = Thread(target=update_location_and_fruit_data, args=(queue,))
    thread2 = Thread(target=write_to_csv, args=(queue,))
    thread3 = Thread(target=upload_to_firebase)

    thread1.start()
    thread2.start()
    thread3.start()


    # Join threads
    thread1.join()
    thread2.join()
    thread3.join()


