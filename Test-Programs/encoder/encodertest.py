import RPi.GPIO as GPIO
A_Pin = 21
B_Pin = 20

GPIO.setmode(GPIO.BCM)
GPIO.setup(A_Pin, GPIO.IN)
GPIO.setup(B_Pin, GPIO.IN)

outcome = [0,1,-1,0,-1,0,0,1,1,0,0,-1,0,-1,1,0]
lastAB = 0b00
counter = 0

while True:
    A = GPIO.input(A_Pin)
    B = GPIO.input(B_Pin)
    currentAB = (A << 1) | B
    position = (lastAB << 2) | currentAB
    counter += outcome[position]
    lastAB = currentAB
    print counter
    
