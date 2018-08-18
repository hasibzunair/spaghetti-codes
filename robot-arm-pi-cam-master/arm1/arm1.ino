#include <Servo.h>
Servo myservo1; 

int pos1 = 90;   //claw

int slider = 1;

int p1 = 46;
int p2 = 48;//claw

//states for the input pins set to zero
int s1 = 0;
int s2 = 0;


void setup() {

   pinMode(p1, INPUT);
   pinMode(p2, INPUT);
  myservo1.attach(7); //base // attaches the servo on pin 9 to the servo object
     
  Serial.begin(9600);
  myservo1.write(pos1);


  
  delay(100);
}

void loop() {

  s1 = digitalRead(p1);
  s2 = digitalRead(p2);

  
    Serial.print(s1);
    Serial.print("  ");
    Serial.print(s2);
    Serial.println("  ");

    if (s1 == HIGH)
    {
      pos1 += slider;
       Serial.println("MOVE UP");
      if (pos1 < 1) pos1 = 1;
      myservo1.write(pos1);
      delay(15);
    }

    if (s2 == HIGH)
    {
      pos1 -= slider;
      Serial.println("MOVE DOWN");
      if (pos1 > 179) pos1 = 179;
      myservo1.write(pos1);
      delay(15);
    }//


    
    else {}


}

