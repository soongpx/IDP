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

#GLOBAL VARS
total_harvested_fruits = 0
total_detected_fruits = 0
csv_path = "data.csv"

#LOGGER CFG
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


#GET MACHINE DATA
def update_location_and_fruit_data(queue):
    global total_harvested_fruits, total_detected_fruits
    while True:
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')

        # change to read from GPS
        machine_latitude = random.uniform(-90, 90)
        machine_longitude = random.uniform(-180, 180)

        # change to read from txt file
        harvested_fruits = total_harvested_fruits
        detected_fruits = total_detected_fruits
        total_detected_fruits += 1
        total_harvested_fruits += 1

        # Enqueue data
        queue.put((timestamp, machine_latitude, machine_longitude, detected_fruits, harvested_fruits))
        time.sleep(20)  # Sleep for 20 seconds
#
# def update_robot_image():
#


#WRITE TO CSV FILE
def clear_csv_file():
    df_csv = pd.DataFrame(columns=['Timestamp', 'Machine_Latitude', 'Machine_Longitude', 'Detected_Fruits', 'Harvested_Fruits'])
    df_csv.to_csv(csv_path, index=False)


def write_to_csv(queue):
    while True:
        data = queue.get()
        if data:
            # Read DataFrame
            dataframe = pd.read_csv(csv_path)
            if data[0].find("-"):
                lst = data[0].split(" ")[0].split("-")
                date = lst[-1] + "/" + lst[1] + "/" + lst[0] + " " + data[0].split(" ")[1]
            else: date = data[0]
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
        return response.status_code == 200
    except requests.ConnectionError:
        logger.error("Connection error occurred while trying to reach www.google.com")
        return False
    except requests.Timeout:
        logger.error("Timeout occurred while trying to reach www.google.com")
        return False


def read_csv(filepath):
    location_name ="location"
    location_idx = 1
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
        print(coordinates)
        return coordinates


def upload_robot_images(uploaded_file_path):
    directory = "robot_location"
    jpeg_files = glob.glob(directory + "/*.jpg")
    for file in jpeg_files:
        uploaded_file_path = file.replace("\\", "/")
        firebase_helper.upload_image(file, uploaded_file_path)


def upload_images(uploaded_file_path):
    directory = "detected_pics"
    jpeg_files = glob.glob(directory + "/*.jpg")
    for file in jpeg_files:
        uploaded_file_path = directory + "/" + uploaded_file_path + "/" + file.split("\\")[1]
        firebase_helper.upload_image(file, uploaded_file_path)

#UPLOAD ALL DATA TO FIREBASE
def upload_data(coordinates):
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

        # Call upload_data function
        firebase_helper.upload_data(example_data, data_path)
        upload_images(data_path)
        upload_robot_images(data_path)


def upload_to_firebase():
    while is_internet_available():
         coordinates = read_csv(csv_path)
         upload_data(coordinates)
         print("data uploaded to firebase")
         time.sleep(20)


def open_cam():
    cap = cv2.VideoCapture(0)  # or cap = cv2.VideoCapture(0) for webcam

    if not cap.isOpened():
        print("Error: Could not open video.")
    else:
        while True:
            ret, frame = cap.read()
            if not ret:
                print("Error: Failed to capture image.")
                break

            cv2.imshow('Video Frame', frame)

            if cv2.waitKey(1) & 0xFF == ord('q'):
                break

        cap.release()
        cv2.destroyAllWindows()

if __name__ == "__main__":
    firebase_helper = FirebaseHelper(firebaseConfig, service_account_path)

    clear_csv_file()

    # Initialize the queue
    queue = Queue()

    # Create and start the threads
    thread1 = Thread(target=update_location_and_fruit_data, args=(queue,))
    thread2 = Thread(target=write_to_csv, args=(queue,))
    thread3 = Thread(target=upload_to_firebase)
    thread4 = Thread(target=open_cam)

    thread1.start()
    thread2.start()
    thread3.start()
    thread4.start()


    # Join threads
    thread1.join()
    thread2.join()
    thread3.join()
    thread4.join()

