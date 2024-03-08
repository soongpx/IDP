import serial
import ydlidar


ports = ydlidar.lidarPortList()

port = list(ports.values()).pop(-1)

ser = serial.Serial(port, 115200)
integer = 3
while True:
    ser.write(integer.to_bytes(1,'big'))