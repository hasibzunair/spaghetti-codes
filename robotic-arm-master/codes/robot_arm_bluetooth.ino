#include<Servo.h>
char val;
Servo servo1, servo2, servo3;
int orange = 8;
int yellow = 9;
int pink = 10;
int blue = 11;
void setup() {
  
  
  Serial.begin(9600);
  pinMode(orange,OUTPUT);
pinMode(yellow,OUTPUT);
pinMode(pink,OUTPUT);
pinMode(blue,OUTPUT);
  
  servo1.attach(5); 
  servo2.attach(6);
  servo3.attach(7);
  
  servo1.write(50);
  

}

void loop() {


   // serial read from bluetooth hc05  
  if ( Serial.available()>0 )
  {
    val = Serial.read();
    
   Serial.print("Value = ");
   Serial.println(val);
    delay(100);
    
    //servo.write(degrees); control servo
    
    
   if (val == 'o')
    {
     servo1.write(160);
      Serial.println('o');
     delay(100);
    
    
    }
    
    if(val == 'c')
    {
     servo1.write(50);
      Serial.println('c');
      delay(100);
    }
  if(val == 'u')
    {
     servo2.write(0);
      Serial.println('u');
      delay(100);
    }
                
if(val == 'd')
    {
     servo2.write(50);
      Serial.println('d');
      delay(100);
    }
    if(val == 'l')
    {
      stepperaclock();
      delay(10);
    }
if(val == 'r')
    {
      stepperclock();
      delay(10);
    }
if(val == 't')
    {
     servo3.write(90);
      Serial.println('t');
      delay(100);
    }
    if(val == 'x')
    {
     servo3.write(30);
      Serial.println('x');
      delay(100);
    }
    }
}

void stepperclock()
{
  digitalWrite(orange,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,LOW);
  digitalWrite(blue,LOW);
  delay(5);

  digitalWrite(orange,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,LOW);
  digitalWrite(blue,HIGH);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,LOW);
  digitalWrite(blue,HIGH);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,HIGH);
  digitalWrite(blue,HIGH);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,HIGH);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(pink,HIGH);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(pink,LOW);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,HIGH);
  digitalWrite(yellow,HIGH);
  digitalWrite(pink,LOW);
  digitalWrite(blue,LOW);
  delay(5);
}

void stepperaclock()
{
  digitalWrite(orange,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,LOW);
  digitalWrite(blue,LOW);
  delay(5);

  digitalWrite(orange,HIGH);
  digitalWrite(yellow,HIGH);
  digitalWrite(pink,LOW);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(pink,LOW);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(pink,HIGH);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,HIGH);
  digitalWrite(blue,LOW);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,HIGH);
  digitalWrite(blue,HIGH);
  delay(5);
  
  digitalWrite(orange,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,LOW);
  digitalWrite(blue,HIGH);
  delay(5);
  
  digitalWrite(orange,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(pink,LOW);
  digitalWrite(blue,HIGH);
  delay(5);
}
