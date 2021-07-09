import serial
from time import sleep
import sys
import time
import math
import csv

from datetime import date

COM  = 'COM4'
BAUD = 115200

from project_lib import Project
try:
    project = Project(sc,"<ProjectId>", "<ProjectToken>")
except:
    print("No connection to the cloud")

try:
    ser = serial.Serial(COM, BAUD, timeout = .1)
except: 
    print("Connection lost.")

temperature = 0
pressure = 0
mineral_level = 0
soil = 0 
humidity = 0

today = date.today()

header = ['Date and Time', 'Temperature', 'Mineral Level', 'Soil', 'Humidity']
data = [today, temperature, soil, humidityty]

given_time = time.time() + 30 #second
with open('data.csv', 'w', encoding='UTF8', newline='') as f:
    while time.time() < given_time:
        header = ['Date and Time', 'Temperature', 'Mineral Level', 'Soil', 'Humidity']
        data = [today, temperature, soil, humidityty]
        writer = csv.writer(f)
        writer.writerow(header)
        writer.writerows(data)

project.save_data("file_name.csv", pandas_df.to_csv(index=False))
