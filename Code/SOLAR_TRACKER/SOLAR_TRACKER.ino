#include <Servo.h>

int sensorPin = A0;
int sensorPin2 = A1;
int servoPin  = 9;
int servoPin2  = 10;

int sensorValue = 0;
int sensorValue2 = 0;
int servoGrad = 180;
int servoGrad2 = 90;
int tolerance = 40;

Servo myservo;
Servo myservo2;

void setup() {
  pinMode( sensorPin, INPUT);
  pinMode( sensorPin2, INPUT);
  myservo.attach( servoPin );
    myservo2.attach( servoPin2 );
  myservo.write( servoGrad );
    myservo2.write( servoGrad2 );
    delay(1000);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  sensorValue2 = analogRead(sensorPin2);
  if ( sensorValue > (512-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  
    if ( sensorValue2 > (512-tolerance) )
  {
    if (servoGrad2 < 180) servoGrad2++;
  }



  if ( sensorValue < (512+tolerance) )
  {
    if (servoGrad > 80) servoGrad--;
  }
  if ( sensorValue2 < (512+tolerance) )
  {
    if (servoGrad2 > 0) servoGrad2--;
  }

  myservo.write( servoGrad ); 
 myservo2.write( servoGrad2 ); 
  delay(100);
}
