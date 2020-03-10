import cv2
import numpy as np
import dlib
import serial
import sys
import time


arduino = serial.Serial('/dev/ttyACM0', 9600)
time.sleep(2)
print("Connection to arduino...")

video = cv2.VideoCapture(2)
detector = dlib.get_frontal_face_detector()

while True:
    ret,frame = video.read()
    #print(np.shape(frame))
    gray  = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)    
    face_coordinates = detector(gray)
    for face in face_coordinates:
        x,y = face.left(),face.top()
        w,h = face.right(),face.bottom()
        print("rectangle corner coordinates",(x,y),(w,h))
        cv2.rectangle(frame,(x,y),(w,h),(255,0,0),3)
        
        
        x_center = int((x+w)/2)
        y_center = int((y+h)/2)      
        
        
        face_center = (x_center,y_center)
        
        print(face_center)
        data = "X{0:d}Y{1:d}Z".format(x_center,y_center)
        print ("output = '" +data+ "'")
        arduino.write(str.encode(data))
        #time.sleep(1);
    frame_flipped = cv2.flip(frame,1)
    cv2.imshow('screen', frame_flipped)
    key = cv2.waitKey(1)
    if key == ord('q'):
        break
video.release()
cv2.destroyAllWindows()