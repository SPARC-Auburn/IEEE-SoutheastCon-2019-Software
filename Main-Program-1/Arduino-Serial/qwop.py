import serial
import sys, pygame
pygame.init()

size = width, height = 320, 240
ser = serial.Serial("/dev/ttyUSB0",9600)
speed = 30

screen = pygame.display.set_mode(size)

def getString(dir1, speed1, dir2, speed2):
    return str.encode('['+str(dir1)+','+str(speed1)+','+str(dir2)+','+str(speed2))

while 1:
    while ser.in_waiting:
        print(ser.read())

    for event in pygame.event.get():
        if event.type == pygame.QUIT: sys.exit()
        elif event.type == pygame.KEYDOWN:
            if event.key == 97: #a
                ser.write(bytes([0,20,1,20,41]))
            elif event.key == 100: # d
                ser.write(bytes([1,20,0,20,41]))
            elif event.key == 119: # w
                ser.write(bytes([0,20,0,20,40]))
            elif event.key == 115: # s
                ser.write(bytes([1,20,1,20,42]))				
            #elif event.key == 113: # q
            #     ser.write(bytes([3,192]))
            #elif event.key == 101: #e
            #     ser.write(bytes([3,64]))
        elif event.type == pygame.KEYUP:
            if event.key == 97 or event.key == 100:
                ser.write(bytes([0,0,0,0,0]))
            elif event.key == 119 or event.key == 115:
                ser.write(bytes([0,0,0,0,0]))
            elif event.key == 113 or event.key == 101:
                ser.write(bytes([0,0,0,0,0]))           

