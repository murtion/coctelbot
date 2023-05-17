import time
from adafruit_servokit import ServoKit
kit = ServoKit(channels=16)
#kit._pca.frequency = 60

kit.servo[0].angle = 90
time.sleep(1)
kit.servo[0].angle = 0
time.sleep(1)
kit.servo[1].angle = 90
time.sleep(1)
kit.servo[1].angle = 0
time.sleep(1)
kit.servo[2].angle = 90
time.sleep(1)
kit.servo[2].angle = 0
time.sleep(1)
kit.servo[3].angle = 90 
time.sleep(1)
kit.servo[3].angle = 0

