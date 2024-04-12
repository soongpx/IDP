import cv2
import time

# Load your image
image = cv2.imread('/home/px/arduino_ws/src/arduino_control/arduino_control/ML/detected_frame.jpg')

while True:
    # Display the image
    cv2.imshow('Image', image)
    
    # Wait for 3 seconds
    start_time = time.time()
    while time.time() - start_time < 3:
        if cv2.waitKey(1) & 0xFF == ord('q'):  # Press 'q' to quit
            break
    
    # Destroy the window
    cv2.destroyWindow('Image')
    
    # Wait for 1 second
    time.sleep(1)
