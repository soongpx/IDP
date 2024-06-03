import glob
import os
import shutil

offline_img_dir = 1
offline_img__dir_str = ""
internet_availability = True

def upload_images(uploaded_file_path):
    global internet_availability, offline_img_dir, offline_img_dir_str

    directory = "detected_pics"
    jpeg_files = glob.glob(directory + "/*.jpg")
    for file in jpeg_files:
        offline_img_dir_str = directory + "/" + uploaded_file_path
        uploaded_file_path = directory + "/" + uploaded_file_path + "/" + file.split("\\")[1]

        if not os.path.exists(offline_img_dir_str): os.makedirs(offline_img_dir_str)
        shutil.copy2(file, offline_img_dir_str)
        offline_img_dir += 1

    if internet_availability:
        items = os.listdir(directory)
        dates = [item for item in items if os.path.isdir(os.path.join(directory, item))]

        for date in dates :
            date_path = os.path.join(directory, date)
            location = os.listdir(date_path)
            for loc in location:
                location_path = os.path.join(date_path, loc)
                jpeg_files = glob.glob(location_path + "/*.jpg")
                for file in jpeg_files:
                    print(file)
                    try:
                        os.remove(file)
                    except Exception as e:
                        print(f"Failed to delete {file}. Reason: {e}")
                os.rmdir(location_path)
            os.rmdir(date_path)

data_path = "2024-06-04" + "/" + "location01"

upload_images(data_path)

detected_img_path = "detected_pics/3.jpg"
print(detected_img_path.split("/"))