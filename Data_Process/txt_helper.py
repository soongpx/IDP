class txt_data:
    def __init__(self, txt_filepath):
        self.data = self.read_txt().splitlines()
        self.detected_fruits = int(self.data[0].split(":")[1])
        self.harvested_fruits = int(self.data[1].split(":")[1])

    def write_txt(self, detected, harvested):
        with open('/home/px/Documents/GitHub/IDP/Data_Process/fruit_data.txt', 'a') as file:
            file.write(f"detected:{detected}")
            file.write(f"harvested:{harvested}")

    def read_txt(self):
        # Open the file in read mode
        with open('/home/px/Documents/GitHub/IDP/Data_Process/fruit_data.txt', 'r') as file:
            # Read the entire content of the file
            data = file.read()
            # Print the content
            return data

