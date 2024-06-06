# from ultralytics import YOLO
#
# model_path = "yolov8-architecture/yolov8l-large.yaml"
# data_config = "data.yaml"
#
# # Load a model
# # model = YOLO(model_path)  # build a new model from scratch
# model = YOLO("yolov8n.yaml")  # load a pretrained model (recommended for training)
#
#
# # # Use the model
# model.train(data=data_config, workers=2, batch=4, epochs=100, patience=50, name="yolov8_obb_FFB")  # train the model
# metrics = model.val()  # evaluate model performance on the validation set
# # results = model("https://ultralytics.com/images/bus.jpg")  # predict on an image
# path = model.export()  # export the model to ONNX format

from ultralytics import YOLO

# Load the model (YOLOv8 architecture)
model = YOLO('yolov8n.pt')  # 'yolov8n' for YOLOv8 nano model, you can choose 'yolov8s', 'yolov8m', 'yolov8l', or 'yolov8x'

# Train the model
model.train(data='dataset/data.yaml', workers=2, batch=5, epochs=200, patience=50, name='yolov8_one_class', single_cls=True)
