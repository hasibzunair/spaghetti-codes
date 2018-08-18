#include <Servo.h> 
 
Servo myservo_shold;
Servo myservo_claw;
Servo myservo_wrist;
Servo myservo_base;  // create servo object to control a servo 
 
int potpin1 = 0;  // analog pin used to connect the potentiometer
int potpin2 = 1;
int potpin3 = 2;
int potpin4 = 3;


int val = 0;    // variable to read the value from the analog pin 
int val2 = 0;  
int val3 = 0;
int val4 = 0;




void setup() 
{ 
  myservo_shold.attach(9);  // attaches the servo on pin 9 to the servo object (2 servos)
  myservo_claw.attach(10);
  myservo_wrist.attach(7);
  myservo_base.attach(6);



} 
 
 
 
 
void loop() 
{ 
  val = analogRead(potpin1);            // reads the value of the potentiometer (value between 0 and 1023) 
  val = map(val, 10, 1000, 15, 170);     // scale it to use it with the servo (value between 0 and 180) 
  myservo_shold.write(val);                  // sets the servo position according to the scaled value 
  delay(15);                           // waits for the servo to get there 


val2 = analogRead(potpin2);            // reads the value of the potentiometer (value between 0 and 1023) 
  val2 = map(val2, 10, 1000, 170, 15);     // scale it to use it with the servo (value between 0 and 180) 
  myservo_claw.write(val2);                  // sets the servo position according to the scaled value 
  delay(15);                        

val3 = analogRead(potpin3);            // reads the value of the potentiometer (value between 0 and 1023) 
  val3 = map(val3, 10, 1000, 170, 15);     // scale it to use it with the servo (value between 0 and 180) 
  myservo_wrist.write(val3);                  // sets the servo position according to the scaled value 
  delay(15);                        

val4 = analogRead(potpin4);            // reads the value of the potentiometer (value between 0 and 1023) 
  val4 = map(val4, 1000, 10, 15, 170);     // scale it to use it with the servo (value between 0 and 180) 
  myservo_base.write(val4);                  // sets the servo position according to the scaled value 
  delay(15);                        




} 
