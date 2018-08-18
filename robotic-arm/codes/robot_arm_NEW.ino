#include <Servo.h> 
 
Servo myservowrist1;
Servo myservowrist2;
Servo myservoarm;
Servo myservoclaw;
Servo myservobase;
 
int potpin1 = 0;
int potpin2 = 1;
int potpin3 = 2;
int potpin4 = 3;

int val = 0; 
int val1 = 0;  
int val2 = 0;
int val3 = 0;

void setup() 
{ 
  
  myservowrist1.attach(8);
  myservowrist2.attach(9);
  myservoarm.attach(10);
  myservoclaw.attach(11);
  myservobase.attach(12);

} 
 
void loop() 
{ 

  
    val = analogRead(potpin1);
    myservowrist1.write(map(val, 0, 1023, 0, 180));
    myservowrist2.write(map(val, 0, 1023, 180, 0));

    val1 = analogRead(potpin2);
    myservoarm.write(map(val1, 0, 1023, 0, 180));
    
    val2 = analogRead(potpin3);
    myservoclaw.write(map(val2, 0, 1023, 0, 180));

    val3 = analogRead(potpin4);
    myservobase.write(map(val3, 0, 1023, 0, 180));
    
    
} 
