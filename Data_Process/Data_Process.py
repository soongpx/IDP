import pandas as pd
import threading
import time
import random
from datetime import datetime
from queue import Queue
from firebase_admin import credentials, firestore, initialize_app
import requests
import logging


# Initialize Firebase app
cred = credentials.Certificate("idpi1-8815a-firebase-adminsdk-65yzj-21c96e5135.json")
app = initialize_app(cred)
db = firestore.client(app)

# Logger configuration
logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)

# Global lock for DataFrame modification
df_lock = threading.Lock()

# Global variable to track total harvested fruits
total_harvested_fruits = 1

# CSV path
csv_path = 'Palm_oil_Harvesting_Data_Record.csv'
last_uploaded_index = 0


def clear_csv_file():
    df_csv = pd.DataFrame(columns=['Timestamp', 'Machine_Latitude', 'Machine_Longitude', 'Harvested_Fruits',
                                   'Fruit_Location_Latitude', 'Fruit_Location_Longitude'])
    df_csv.to_csv(csv_path, index=False)


def clear_firestore_database():
    # Clear the 'Palm_oil_Harvesting_Data_Record' collection
    collection_ref = db.collection('Palm_oil_Harvesting_Data_Record')
    docs = collection_ref.stream()
    for doc in docs:
        doc.reference.delete()

    logger.info("All documents are deleted from Firestore.")


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


def update_machine_location(queue):
    while True:
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        machine_latitude = random.uniform(-90, 90)
        machine_longitude = random.uniform(-180, 180)

        # Enqueue data
        queue.put(('machine_location', timestamp, machine_latitude, machine_longitude))
        time.sleep(20)  # Sleep for 20 seconds


def update_fruit_data(queue):
    global total_harvested_fruits

    while True:
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        harvested_fruits = total_harvested_fruits
        total_harvested_fruits += 1
        fruit_location_latitude = random.uniform(-90, 90)
        fruit_location_longitude = random.uniform(-180, 180)

        # Enqueue data
        queue.put(('fruit_data', timestamp, harvested_fruits, fruit_location_latitude, fruit_location_longitude))
        time.sleep(random.uniform(5, 10))


def write_to_csv(queue):
    while True:
        data = queue.get()

        with df_lock:
            # Read DataFrame
            dataframe = pd.read_csv(csv_path)

            # Update DataFrame
            if data[0] == 'machine_location':
                new_row = pd.DataFrame([[data[1], data[2], data[3], None, None, None]],
                                       columns=['Timestamp', 'Machine_Latitude', 'Machine_Longitude',
                                                'Harvested_Fruits',
                                                'Fruit_Location_Latitude', 'Fruit_Location_Longitude'])
            elif data[0] == 'fruit_data':
                new_row = pd.DataFrame([[data[1], None, None, data[2], data[3], data[4]]],
                                       columns=['Timestamp', 'Machine_Latitude', 'Machine_Longitude',
                                                'Harvested_Fruits',
                                                'Fruit_Location_Latitude', 'Fruit_Location_Longitude'])

            # Handle None values before converting data types
            new_row = new_row.fillna(value={'Harvested_Fruits': 0})  # Replace None with 0 for Harvested_Fruits

            # Ensure that the DataFrame dtypes are consistent
            new_row = new_row.astype(dataframe.dtypes)

            # Concatenate DataFrames
            dataframe = pd.concat([dataframe, new_row], ignore_index=True)

            # Write DataFrame back to CSV
            dataframe.to_csv(csv_path, index=False)

            logger.info("Data written to CSV")


def upload_to_firebase():
    global last_uploaded_index
    while True:
        with df_lock:
            # Read data from the file
            dataframe = pd.read_csv(csv_path)

            # Check if there is data to upload and there is an internet connection
            if not dataframe.empty and is_internet_available():
                data_to_upload = dataframe.iloc[last_uploaded_index:].to_dict("records")

                try:
                    if data_to_upload:
                        # Upload data to Firebase
                        for data in data_to_upload:
                            db.collection('Palm_oil_Harvesting_Data_Record').add(data)

                            logger.info(f"Data Uploaded to Firebase: {data}")

                        last_uploaded_index = dataframe.index[-1] + 1
                    else:
                        logger.info("No data is uploaded")

                except Exception as e:
                    logger.error(f"Error uploading data to Firebase: {e}")

        time.sleep(5)  # Sleep for 5 seconds


def offlinesync():
    # Clear Firestore database
    clear_firestore_database()

    # Clear CSV file
    clear_csv_file()

    # Queue for communication between threads
    data_queue = Queue()

    # Run the update_machine_location, update_fruit_data, write_to_csv, and upload_to_firebase threads concurrently
    machine_location_thread = threading.Thread(target=update_machine_location, args=(data_queue,))
    fruit_data_thread = threading.Thread(target=update_fruit_data, args=(data_queue,))
    write_thread = threading.Thread(target=write_to_csv, args=(data_queue,))
    upload_thread = threading.Thread(target=upload_to_firebase)

    machine_location_thread.start()
    fruit_data_thread.start()
    write_thread.start()
    upload_thread.start()

    machine_location_thread.join()
    fruit_data_thread.join()
    write_thread.join()
    upload_thread.join()


if __name__ == "__main__":
    offlinesync()
