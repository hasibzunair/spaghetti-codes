#include <NewPing.h>  
#define TRIGGER_PIN  3  
#define ECHO_PIN     2   
#define MAX_DISTANCE 100

const int Motor1Pin1 = 8;
const int Motor1Pin2 = 9;
const int Motor2Pin2 =10;
const int Motor2Pin1 = 11;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

unsigned int time;            
int distance;                 
int triggerDistance = 30;    
int fDistance;                
int lDistance;
int rDistance;


void setup()
{
  pinMode(Motor1Pin1, OUTPUT);   
  pinMode(Motor1Pin2, OUTPUT);   
  pinMode(Motor2Pin1, OUTPUT);   
  pinMode(Motor2Pin2, OUTPUT);
}

void loop()
{
  scan();                                
  fDistance = distance;                  
  if(fDistance < triggerDistance){    
    moveBackward();                      
    delay(1000);
    moveRight();                         
    delay(500);
    moveStop();                          
    scan();                             
    rDistance = distance;                
    moveLeft();
    delay(1000);                         
    moveStop();                         
    scan();                             
    lDistance = distance;               
    if(lDistance < rDistance){           
      moveRight();                      
      delay(200);
      moveForward();                    
    }
    else{
      moveForward();                     
    }
  }
  else{
    moveForward();                      
  }
}

void scan(){
  time = sonar.ping();                  
  distance = time / US_ROUNDTRIP_CM;   
  if(distance == 0){                    
    distance = 100;                     
  }
  delay(10);
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
  digitalWrite(Motor1Pin1, HIGH);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, HIGH);
}

void moveLeft(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, HIGH);
  digitalWrite(Motor2Pin1, HIGH);
  digitalWrite(Motor2Pin2, LOW);
}

void moveStop(){
  digitalWrite(Motor1Pin1, LOW);
  digitalWrite(Motor1Pin2, LOW);
  digitalWrite(Motor2Pin1, LOW);
  digitalWrite(Motor2Pin2, LOW);
}


