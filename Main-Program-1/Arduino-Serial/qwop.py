import serial
import sys, pygame
pygame.init()

size = width, height = 320, 240
ser = serial.Serial("/dev/ttyACM0")
speed = 30

screen = pygame.display.set_mode(size)

while 1:
    while ser.in_waiting:
        print(ser.read())

    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == 97: #a
                ser.write(getString(0,speed,1,speed))
            elif event.key == 100: # d
                ser.write(getString(1,speed,0,speed))
            elif event.key == 119: # w
                ser.write(getString(1,speed,1,speed))
            elif event.key == 115: # s
                ser.write(getString(0,speed,0,speed))   				
            # elif event.key == 113: # q
            #     ser.write(bytes([3,192]))
            # elif event.key == 101: #e
            #     ser.write(bytes([3,64]))
        elif event.type == pygame.KEYUP:
            if event.key == 97 or event.key == 100:
                ser.write(getString(1,0,1,0))
            elif event.key == 119 or event.key == 115:
                ser.write(getString(1,0,1,0))
            elif event.key == 113 or event.key == 101:
                ser.write(getString(1,0,1,0))

def getString(dir1, speed1, dir2, speed2):
    return str.encode('['+str(dir1)+','+str(speed1)+','+str(dir2)+','+str(speed2))