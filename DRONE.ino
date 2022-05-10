#include <AFMotor.h>
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
int a;
void setup()  {Serial.begin(9600);
   motor2.setSpeed(255);
   motor3.setSpeed(255);
   pinMode(5,OUTPUT);
   pinMode(9,OUTPUT);
}

void loop() {
  if(Serial.available()>0){a=Serial.read()-48; Serial.println(a);}
   if(a==1){motor2.run(FORWARD);motor2.setSpeed(255);motor3.run(FORWARD);motor3.setSpeed(255);digitalWrite(5,1);digitalWrite(9,1);}
   if(a==2){motor2.run(BACKWARD);motor2.setSpeed(255);motor3.run(BACKWARD);motor3.setSpeed(255);}
    if(a==3){motor2.run(FORWARD);motor2.setSpeed(255);motor3.run(BACKWARD);motor3.setSpeed(255);}
 if(a==4){motor3.run(FORWARD);motor3.setSpeed(255);motor2.run(BACKWARD);motor2.setSpeed(255);}
   if(a==0){motor2.run(RELEASE);motor3.run(RELEASE);digitalWrite(5,0);digitalWrite(9,0);}
 }
