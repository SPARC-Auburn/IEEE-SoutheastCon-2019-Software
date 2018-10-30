# Organization: Student Projects and Research Committee
# School: Auburn University
# Project: IEEE Southeastcon 2019
# Description: Utilizes OpenCV to identify objects that have a dominant color of blue, yellow, green, or red.
# It displays rectangle outlines on objects on one window and shows four respective color filter windows.
# Derived from: https://github.com/aquibjaved/Multiple-Color-Tracking-using-opencv-and-python-in-Real-Time

import cv2
import numpy as np
import time
# Constants
MIN_AREA = 300

class Application():
    def __init__(self, master=None):
        # capturing video through webcam
        # run "sudo modprobe bcm2835-v4l2" if using pi camera
        self.cap = cv2.VideoCapture(0)      

    def findObjects(self):
        # definig the range of red color
        red_lower = np.array([120, 87, 60], np.uint8)
        red_upper = np.array([180, 255, 255], np.uint8)

        # defining the Range of Blue color
        blue_lower = np.array([80, 100, 75], np.uint8)
        blue_upper = np.array([110, 255, 255], np.uint8)

        # defining the Range of yellow color
        yellow_lower = np.array([22, 130, 200], np.uint8)
        yellow_upper = np.array([55, 255, 255], np.uint8)

        # defining the Range of green color
        green_lower = np.array([40, 70, 80], np.uint8)
        green_upper = np.array([80, 255, 255], np.uint8)
        kernal = np.ones((5, 5), "uint8")
        
        _, img = self.cap.read()
        h,w,d = img.shape
        start = time.time()
        frames = 0
        while(1):
            _, img = self.cap.read()
            # converting frame(img i.e BGR) to HSV (hue-saturation-value)
            hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)



            # finding the range of red,blue,yellow, and green color in the image
            red = cv2.inRange(hsv, red_lower, red_upper)
            blue = cv2.inRange(hsv, blue_lower, blue_upper)
            yellow = cv2.inRange(hsv, yellow_lower, yellow_upper)
            green = cv2.inRange(hsv, green_lower, green_upper)

            # Morphological transformation, Dilation


            red = cv2.dilate(red, kernal)
            #res = cv2.bitwise_and(img, img, mask=red)

            blue = cv2.dilate(blue, kernal)
            #res1 = cv2.bitwise_and(img, img, mask=blue)

            yellow = cv2.dilate(yellow, kernal)
            #res2 = cv2.bitwise_and(img, img, mask=yellow)

            green = cv2.dilate(green, kernal)
            #res3 = cv2.bitwise_and(img, img, mask=green)

            # Tracking the Red Color
            (_, contours, hierarchy) = cv2.findContours(
                red, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            for pic, contour in enumerate(contours):
                self.drawOutline(contour,img,"RED",(0,0,255))

            # Tracking the Blue Color
            (_, contours, hierarchy) = cv2.findContours(
                blue, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            for pic, contour in enumerate(contours):
                self.drawOutline(contour,img,"BLUE",(255,0,0))

            # Tracking the yellow Color
            (_, contours, hierarchy) = cv2.findContours(
                yellow, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            for pic, contour in enumerate(contours):
                self.drawOutline(contour,img,"YELLOW",(0,160,255))

            # Tracking the green Color
            (_, contours, hierarchy) = cv2.findContours(
                green, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
            for pic, contour in enumerate(contours):
                self.drawOutline(contour,img,"GREEN",(0,255,0))

            #cv2.imshow("Redcolour",red)
            frames += 1
            cv2.putText(img, str(int(frames/(time.time()-start))), (0, h), cv2.FONT_HERSHEY_SIMPLEX, 2, (0,0,0), 2)
            cv2.imshow("Color Tracking", img)
            #cv2.imshow("red",res)
            #cv2.imshow("blue",res1)
            #cv2.imshow("yellow",res2)
            #cv2.imshow("green",res3)
            char = cv2.waitKey(1)
            if  char == ord('q'):
                self.cap.release()
                cv2.destroyAllWindows()
                return
            elif char == ord('r'):
                frames = 0
                start = time.time()

    def drawOutline(self,contour,img,colorName,colorValues):
        area = cv2.contourArea(contour)
        if area > MIN_AREA:
            # get box points
            #rect = cv2.minAreaRect(contour)
            #box = cv2.boxPoints(rect)
            #box = np.intc(box)
            # draw rectangle
            cv2.drawContours(img, [contour], 0, colorValues, 3)
            # get center coordinates of each object
            #boxcentre = rect[0]  
            #boxcentrex = int(boxcentre[0])
            #boxcentrey = int(boxcentre[1])
            # draw a circle at center point of object
            #cv2.circle(img, (boxcentrex, boxcentrey), 5, colorValues, -1)
            # draw text of color name
            #x, y, w, h = cv2.boundingRect(contour)
            #cv2.putText(img, colorName, (x, y), cv2.FONT_HERSHEY_SIMPLEX, 1.0, colorValues)

def main():
    app = Application()
    app.findObjects()

if __name__ == "__main__":
    main()
