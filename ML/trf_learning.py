from ultralytics import YOLO
from config.data_config import data_config
model_path = 'model/7_jan_palm_oil.pt'
# Load a pre-trained YOLOv8 model
model = YOLO(model_path)

# Freeze all layers except the last linear layer
for name, param in model.model.named_parameters():
    print(f"name: {name}")
    # if 'head' not in name:  # Assuming 'head' in the name indicates the final layer
    #     param.requires_grad = False

