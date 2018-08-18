#include<Servo.h>

Servo myservo_shold;
Servo myservo_claw;
Servo myservo_wrist;
Servo myservo_base; 

int pos = 0;
int pos1 = 0;
int pos2 = 0;
int pos3 = 0;

void setup()

{
  myservo_shold.attach(9);
  myservo_shold.write(0); //reset to inital position
  
  
  myservo_base.attach(10);
  myservo_base.write(180);
  
  
  myservo_claw.attach(7);
  myservo_claw.write(180);
  
  
  myservo_wrist.attach(6);
  myservo_wrist.write(180);
}

void loop()

{
  
  
  
  for( pos = 180; pos>=100; pos-=1)
  
  {
    
    myservo_base.write(pos);
    delay(60);
    
  }
  
  delay(400);
  
  
  
   for( pos1 = 0; pos1<=100; pos1+=1)
  
  {
    
    myservo_shold.write(pos1);
    delay(60);
    
  }
  
  delay(400);
  
 
    for( pos2 = 180; pos2>=120; pos2-=1)
  
  {
    
    myservo_wrist.write(pos2);
    delay(60);
    
  }
  
  delay(400);
  
   for( pos3 = 180; pos3>=0; pos3-=1)
  
  {
    
    myservo_claw.write(pos3);
    delay(60);
    
  }
  
  delay(200);
  

   for( pos2 = 120; pos2<=180; pos2+=1)
  
  {
    
    myservo_wrist.write(pos2);
    delay(60);
    
  }
  
  delay(200);
  
  
     for( pos1= 100; pos1>=0; pos1-=1)
  
  {
    
    myservo_shold.write(pos1);
    delay(60);
    
  }
  
  delay(200);
     for( pos = 100; pos<=180; pos+=1)
  
  {
    
    myservo_base.write(pos);
    delay(60);
    
  }
  
  delay(400);
  
    for( pos1 = 0; pos1<=100; pos1+=1)
  
  {
    
    myservo_shold.write(pos1);
    delay(60);
    
  }
  
  delay(400);
     for( pos2 = 180; pos2>=120; pos2-=1)
  
  {
    
    myservo_wrist.write(pos2);
    delay(60);
    
  }
  
  delay(400);
  
     for( pos3 = 0; pos3<=180; pos3+=1)
  
  {
    
    myservo_claw.write(pos3);
    delay(60);
    
  }
  
  delay(400);
     for( pos2 = 120; pos2<=180; pos2+=1)
  
  {
    
    myservo_wrist.write(pos2);
    delay(60);
    
  }
  
  delay(400);
     for( pos1 =100; pos1>=0; pos1-=1)
  
  {
    
    myservo_shold.write(pos1);
    delay(60);
    
  }
  
  delay(600);
  
 

  
}
