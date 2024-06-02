import csv
from firebase_mod.firebase_helper import FirebaseHelper
from firebase_mod.firebase_config import firebaseConfig, service_account_path
import glob
import os
import time
from datetime import datetime
import threading
import random
csv_path = "Palm_oil_Harvesting_Data_Record.csv"

#GET MACHINE DATA
def update_machine_location(queue):
    while True:
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        machine_latitude = random.uniform(-90, 90)
        machine_longitude = random.uniform(-180, 180)

        # Enqueue data
        queue.put(('machine_location', timestamp, machine_latitude, machine_longitude))
        time.sleep(20)  # Sleep for 20 seconds





# UPLOADING DATA TO FIREBASE
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


def upload_robot_images():
    directory = "robot_location"
    jpeg_files = glob.glob(directory + "/*.jpg")
    for file in jpeg_files:
        uploaded_file_path = file.replace("\\", "/")
        firebase_helper.upload_image(file, uploaded_file_path)


def upload_images():
    directory = "detected_pics"
    entries = os.listdir(directory)

    # Filter the entries to include only directories
    folders = [entry for entry in entries if os.path.isdir(os.path.join(directory, entry))]

    for folder in folders:
        subfolder = os.path.join(directory, folder)
        entries = os.listdir(subfolder)
        JPEG_folders = [entry for entry in entries if os.path.isdir(subfolder)]

        for dir in JPEG_folders:
            target = os.path.join(subfolder, dir)
            jpeg_files = glob.glob(target + "/*.jpg")
            for file in jpeg_files:
                uploaded_file_path = file.replace("\\", "/")
                firebase_helper.upload_image(file, uploaded_file_path)


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

        example_location = day + "/" + coordinate['name']
        # Call upload_data function
        firebase_helper.upload_data(example_data, example_location)


if __name__ == "__main__":
    # offlinesync()
    firebase_helper = FirebaseHelper(firebaseConfig, service_account_path)
    coordinates = read_csv(csv_path)

    upload_data(coordinates)
    upload_images()
    upload_robot_images()