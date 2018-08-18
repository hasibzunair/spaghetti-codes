#include <Servo.h>
Servo myservo1; // 7 3 4 10 6 // vb nm uj yh tg
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 
Servo myservo5;  

int a = 20;
int b = 175;
int c = 60;
int d = 90;
int e = 170;

// vb nm uj yh tg
int pos1 = a;   //claw 30
int pos2 = b;   //base 90
int pos3 = c;   //first a 170
int pos4 = d;   //second a 100
int pos5 = e;   //rotater 20

int slider1 = 1;
int slider2 = 1;
int slider3 = 1;
int slider4 = 1;
int slider5 = 1;


int p1 = 46;
int p2 = 48;//claw

int p3 = 42;
int p4 = 44;//base

int p5 = 38;
int p6 = 40;//first a

int p7 = 34;
int p8 = 36;//second a

int p9 = 30;
int p10 = 32;//rotater

//states for the input pins set to zero
int s1 = 0;
int s2 = 0;

int s3 = 0;
int s4 = 0;

int s5 = 0;
int s6 = 0;

int s7 = 0;
int s8 = 0;

int s9 = 0;
int s10 = 0;



void setup() {

   pinMode(p1, INPUT);
   pinMode(p2, INPUT);
   pinMode(p3, INPUT);
   pinMode(p4, INPUT);
   pinMode(p5, INPUT);
   pinMode(p6, INPUT);
   pinMode(p7, INPUT);
   pinMode(p8, INPUT);
   pinMode(p9, INPUT);
   pinMode(p10, INPUT);


   
  myservo1.attach(7); //claw // attaches the servo on pin 9 to the servo object
   myservo2.attach(3);//base
    myservo3.attach(4);//first a
     myservo4.attach(10);//second a
      myservo5.attach(6);//rot a
      
  Serial.begin(9600);
  myservo1.write(pos1);
  myservo2.write(pos2);
  myservo3.write(pos3);
  myservo4.write(pos4);
  myservo5.write(pos5);



  
  delay(100);
}

void loop() {

  s1 = digitalRead(p1);
  s2 = digitalRead(p2);
  s3 = digitalRead(p3);
  s4 = digitalRead(p4);
  s5 = digitalRead(p5);
  s6 = digitalRead(p6);
  s7 = digitalRead(p7);
  s8 = digitalRead(p8);
  s9 = digitalRead(p9);
  s10 = digitalRead(p10);

  
    Serial.print(s1);
    Serial.print("  ");
    Serial.print(s2);
    Serial.print("  ");

    Serial.print(s3);
    Serial.print("  ");
    Serial.print(s4);
    Serial.print("  ");

    Serial.print(s5);
    Serial.print("  ");
    Serial.print(s6);
    Serial.print("  ");

    Serial.print(s7);
    Serial.print("  ");
    Serial.print(s8);
    Serial.print("  ");

    Serial.print(s9);
    Serial.print("  ");
    Serial.print(s10);
    Serial.println("  ");

    if (s1 == HIGH)
    {
      pos1 += slider1;  // p = p + 1
       Serial.println("MOVE UP");
      if (pos1 < 1) pos1 = 1;
      myservo1.write(pos1);
      delay(15);
    }

    if (s2 == HIGH)
    {
      pos1 -= slider1;
      Serial.println("MOVE DOWN");
      if (pos1 > 179) pos1 = 179;
      myservo1.write(pos1);
      delay(15);
    }// v b

 if (s3 == HIGH)
    {
      pos2 += slider2;
       Serial.println("MOVE UP");
      if (pos2 < 1) pos2 = 1;
      myservo2.write(pos2);
      delay(15);
    }

    if (s4 == HIGH)
    {
      pos2 -= slider2;
      Serial.println("MOVE DOWN");
      if (pos2 > 179) pos2 = 179;
      myservo2.write(pos2);
      delay(15);
    }// n m

     if (s5 == HIGH)
    {
      pos3 += slider3;
       Serial.println("MOVE UP");
      if (pos3 < 1) pos3 = 1;
      myservo3.write(pos3);
      delay(15);
    }

    if (s6 == HIGH)
    {
      pos3 -= slider3;
      Serial.println("MOVE DOWN");
      if (pos3 > 179) pos3 = 179;
      myservo3.write(pos3);
      delay(15);
    }//u j
//---------------------
   if (s7 == HIGH)
    {
      pos4 += slider4;
       Serial.println("MOVE UP");
      if (pos4 < 1) pos4 = 1;
      myservo4.write(pos4);
      delay(15);
    }

    if (s8 == HIGH)
    {
      pos4 -= slider4;
      Serial.println("MOVE DOWN");
      if (pos4 > 179) pos4 = 179;
      myservo4.write(pos4);
      delay(15);
    }// y h

    //---------------
     if (s9 == HIGH)
    {
      pos5 += slider5;
       Serial.println("MOVE UP");
      if (pos5 < 1) pos5 = 1;
      myservo5.write(pos5);
      delay(15);
    }

    if (s10 == HIGH)
    {
      pos5 -= slider5;
      Serial.println("MOVE DOWN");
      if (pos5 > 179) pos5 = 179;
      myservo5.write(pos5);
      delay(15);
    }// t g

    
    else {}


}

