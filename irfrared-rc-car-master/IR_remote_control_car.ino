#include <IRremote.h>
#include <IRremoteInt.h>

#include <IRremote.h>
#include <Servo.h>


#define moveb    0xFF4AB5  
#define movef    0xFF18E7  
#define movel    0xFF5AA5 
#define mover    0xFF10EF
#define moves    0xFF38C7 
#define moveUp   0xFF6897 
#define moveDown 0xFFB04F


int recvPin = 6;
Servo myservo1;  
Servo myservo2;
int pos = 0;

IRrecv irrecv(recvPin);

decode_results results;

const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;
const int Motor2Pin2 =10;
const int Motor2Pin1 = 11;


int ledPin1 = 2;
int ledPin2 = 12;
int ledPin3 = 1;
int ledPin4 = 7;
int ledPin5 = 0;
int ledPin6 = 4;


void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); //Start recv
  
   myservo1.attach(3);
   myservo2.attach(5);
  
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
  
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
}

void loop()
{
 
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin6, HIGH);
  
  if(irrecv.decode(&results))
  {
    Serial.println(results.value, HEX);
   irrecv.resume(); //Recv next value
    
    if (results.value == movef){ moveForward();} 
       
    if(results.value == moveb) {moveBackward();}
   
    if(results.value == movel) {moveLeft();}
  
    if(results.value == mover) {moveRight();}
  
    else if(results.value == moves) {moveStop();}
    
    
    if(results.value == moveUp)
    {
       myservo1.write(170);
       myservo2.write(110);
       delay(500);
    
    }
    
    if(results.value == moveDown)
     {   myservo2.write(170) ;                
         myservo1.write(110);
         delay(500); 
    }
      else{}
   
  }
  //delay(20);
}

void moveBackward(){
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveForward(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveRight(){
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor1Pin1, LOW);//
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH); 
}

void moveLeft(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, LOW);//
  digitalWrite(Motor2Pin2, LOW);
}

void moveStop(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}
