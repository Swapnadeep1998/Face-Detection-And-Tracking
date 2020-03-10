/*
  # Face tracking using arduino - Code #
  # Code by Harsh Dethe
  # 09 Sep 2018.
*/

#include<Servo.h>

Servo servoVer; //Vertical Servo
Servo servoHor; //Horizontal Servo

int x;
int y;

int prevX;
int prevY;

void setup()
{
  Serial.begin(9600);
  servoVer.attach(5); //Attach Vertical Servo to Pin 5
  servoHor.attach(6); //Attach Horizontal Servo to Pin 6
  servoVer.write(70);
  servoHor.write(120);
}

void Pos()
{
  if(prevX != x || prevY != y)
  {
    int servoX = map(x, 640, 0, 80, 140);
    int servoY = map(y, 480, 0, 100, 60);

    servoX = min(servoX, 140);
    servoX = max(servoX, 80);
    servoY = min(servoY, 100);
    servoY = max(servoY, 60);
        
    servoHor.write(servoX);    
    servoVer.write(servoY);
    delay(200);
  }
}

void loop()
{
  if(Serial.available() > 0)
  {
    if(Serial.read() == 'X')
    {
      x = Serial.parseInt();
      if(Serial.read() == 'Y')
      {
        y = Serial.parseInt();
       Pos();
      }
    }
    while(Serial.available() > 0)
    {
      Serial.read();
    }
  }
}
  
