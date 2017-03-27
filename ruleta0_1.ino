#include <Servo.h>

int incomingByte = 0;   // for incoming serial data
Servo servo1;

//Limits
int angle   = 0;     
int limIni  = 0;
int limFin  = 180;

//Flags
#define    _RIGHT  '1'
#define    _LEFT   '2'

void setup() 
{
  Serial.begin(9600);     // opens serial port, sets data rate to 9600 bps
  servo1.attach(9);
  servo1.write(angle);
}

void loop() 
{
  char byteRec;
  if( Serial.available() > 0 )
  {
      //Read serial
      byteRec = Serial.read();
      if( byteRec == _RIGHT )//Rotating to the right
      {
          angle++;
          angle = (angle > limFin)?limFin:angle;
          servo1.write(angle);     
      }
      else if( byteRec == _LEFT )//Rotating to the left
      {
          angle--;
          angle = (angle < limIni)?limIni:angle;
          servo1.write(angle);
      }
  }
        
}

