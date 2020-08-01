# Face-Detection-And-Tracking
This project is basically a face detection and tracking system using OpenCV and Arduino

We've used one Arduino Uno, Two servo motors to operate the pan tilt mechanism, and one USB webcam.
For the face detection part, we coded on python3, and with openCV library. First we tried using Haarcascade Classifier but the performance was not stable, so then we've used Dlib for face detection

The Tracking part was coded on Arduino IDE, Using openCV we calculated the face centre coordinates, and we sent those coordinates using Serial port to the Arduino UNO. The Arduino code has the logic implemnted as how much angle should the camera rotate based on the face coordinates

Project Was done by

1. Swapnadeep Sarkar
2. Subidita Maity
3. Srinyantu Chatterjee
4. Pradyumna Mukherjee
5. Subham Sharma
6. Pranjoli Basak
