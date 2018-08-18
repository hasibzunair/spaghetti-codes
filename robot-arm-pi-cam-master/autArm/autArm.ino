#include <Servo.h>
Servo myservo1; // 7 3 4 10 6 // vb nm uj yh tg
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 



int a = 20;//base
int b = 60;//sec
int c = 170; //claw
int d = 20;//first a


// vb nm uj yh tg
int pos1 = a;   //claw 30
int pos2 = b;   //base 90
int pos3 = c;   //first a 170
int pos4 = d;   //second a 100

void setup() {

  
  myservo1.attach(3); //claw // attaches the servo on pin 9 to the servo object
   myservo2.attach(5);//base
    myservo3.attach(11);//first a
     myservo4.attach(9);//second a
     
  Serial.begin(9600);
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  

  
  delay(100);
}

void loop() {
//base sec claw first
/*
 int a = 20;//base
int b = 60;//sec
int c = 170; //claw
int d = 20;//first a
 */

 myservo1.write(140);
 delay(1000);
  myservo2.write(20);
  delay(1000);
   myservo4.write(80);
  delay(1000);
 myservo3.write(130);
  delay(1000);

  myservo4.write(60);
  delay(1000);
  myservo2.write(40);
  delay(1000);
   myservo1.write(90);
 delay(1000);
  myservo3.write(160);
  delay(2000);

  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  

  
  



 

  
     
 
}

