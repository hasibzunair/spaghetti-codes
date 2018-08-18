#include <QTRSensors.h>

const int crit = 1000;

int surface = 1; //0=follow white line  and 1=follow black line

const int motorRight1 = 10;
const int motorRight2 = 9;

const int motorLeft1 = 5;
const int motorLeft2 = 6;

int sPeed=255;

float Kp = 100;
float Kd =0;
float Ki =0;

//
int preverror = 0;
int error = 0;
int derror = 0;
int ierror = 0;

int U;


int irValues[12];

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2crit microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A5, A4, A3, A2, A1, A0, 13, 12, 11,  8, 7, 4 },
   NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


void setup()
{
  
  pinMode(motorRight1, OUTPUT);   
  pinMode(motorRight2, OUTPUT);   
  pinMode(motorLeft1, OUTPUT);   
  pinMode(motorLeft2, OUTPUT);  
  
  delay(crit);
  sensor();
  if (sensorValues[3]>crit) surface = 1;
  else surface = 0;
   
  Serial.begin(9600); // set the data rate in bits per second for serial data transmission
  delay(1000);
}


void loop()
{
  sensor();
  computePID();
  moveForward();
  //if (sensorValues[0] > crit) leftHandLeft();
  //else if (sensorValues[7] > crit) leftHandRight();
}


void sensor()
{
  // read raw sensor values
  qtrrc.read(sensorValues);

  // print the sensor values as numbers from 0 to 2crit, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    if (sensorValues[i] > 1000) irValues[i] = 1;
    else irValues[i] = 0;

    Serial.print(irValues[i]);
    Serial.print(' ');
    Serial.print(sensorValues[i]);
    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
  //Serial.println();
  
  delay(250);
}

void computePID()
{
  error =    (-5*irValues[1]) + (-4*irValues[2]) + (-3*irValues[3]) + (-2*irValues[4]) + (-1*irValues[5]) + (1*irValues[6]) + (2*irValues[7]) + (3*irValues[8]) + (4*irValues[9]) + (5*irValues[10]);
  derror = error - preverror;
  ierror += error; 
  U = Kp * error + Kd * derror + Ki * ierror;  
  preverror = error;

  if(U>sPeed) U=sPeed;
  else if(U<-sPeed) U=-sPeed; 
  
  Serial.print("         ");
  Serial.print(U);
    
}




void moveForward()
{
  
 
  
  if(U>=0)
  {
    analogWrite(motorRight1, sPeed);
    analogWrite(motorRight2, 0);
    analogWrite(motorLeft1, sPeed-U);
    analogWrite(motorLeft2, 0);
    Serial.print("                  ");
    Serial.print(sPeed);
    Serial.print("   ");
    Serial.println(sPeed-U);
    
  }  

  else if(U<0)
  {
    analogWrite(motorRight1, sPeed+U);
    analogWrite(motorRight2, 0);
    analogWrite(motorLeft1, sPeed);
    analogWrite(motorLeft2, 0);
    Serial.print("                  ");
    Serial.print(sPeed+U);
    Serial.print("   ");
    Serial.println(sPeed);
  }  
  
}

void moveLeftUturn(){
  
  analogWrite(motorRight1, 0);
  analogWrite(motorRight2, 255);
  analogWrite(motorLeft1, 255);
  analogWrite(motorLeft2, 0);
}


void moveRightUturn(){
  
  analogWrite(motorRight1, 255);
  analogWrite(motorRight2, 0);
  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, 255);
}



void moveStop(){
  
  analogWrite(motorRight1, 0);
  analogWrite(motorRight2, 0);
  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, 0);
}


void leftHandLeft()
{
    moveStop();
    delay(crit);
    
    /*
    while( sensorValues[0] > crit )
    { 
      moveForward();
      sensor();
    }  
    
    delay(100);
    */
    while( sensorValues[2] < crit ) 
    {
      moveLeftUturn();
      sensor();
    }  
}






void leftHandRight()  ///////////////////////////////////////////////////////////////
{
    moveStop();
    delay(crit);
    
    while( sensorValues[7] > crit )
    { 
      moveForward();
      sensor();
    }  
    
    delay(crit);
    
    
    while( sensorValues[5] < crit ) 
    {
      moveRightUturn();
      sensor();
    }  
}
 
