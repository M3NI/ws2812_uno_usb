import serial
import time
ser1 = serial.Serial('COM10', 9600)
print("Connecting to serial...")
color = input("Enter color code : ") 
ser1.write(color.encode())
