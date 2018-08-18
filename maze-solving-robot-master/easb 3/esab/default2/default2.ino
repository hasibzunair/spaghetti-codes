#include <QTRSensors.h>


const int motorRight1 = 10;
const int motorRight2 = 9;

const int motorLeft1 = 5;
const int motorLeft2 = 6;





int sPeed=255;

float Kp =20;
float Kd =1000;
float Ki =1.5;

//
int preverror = 0;
int error = 0;
int derror = 0;
int ierror = 0;

int U;

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {A5, A4, A2, A0, 13, 11,  7, 4 },
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];




void setup()
{
  
  pinMode(motorRight1, OUTPUT);   
  pinMode(motorRight2, OUTPUT);   
  pinMode(motorLeft1, OUTPUT);   
  pinMode(motorLeft2, OUTPUT);  

  //calibration();

}


void loop()
{
  readIR();
  computePID();
  moveForward();
  //if (sensorValues[0] > 500) leftHandLeft();
  if (sensorValues[7] > 500) leftHandRight();

  

}


void calibration()
{
  delay(500);
  //pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode
  for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
  }
  //digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  Serial.begin(9600);
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
  
}

void readIR()
{
  // read raw sensor values
  qtrrc.read(sensorValues);

  // print the sensor values as numbers from 0 to 2500, where 0 means maximum reflectance and
  // 1023 means minimum reflectance
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t'); // tab to format the raw data into columns in the Serial monitor
  }
  Serial.println();
  
  delay(250);

}


void computePID()
{
  error =    (-3*sensorValues[1]) + (-2*sensorValues[2]) + (-1*sensorValues[3]) + (1*sensorValues[4]) + (2*sensorValues[5]) + (3*sensorValues[6]);
  derror = error - preverror;
  ierror += error; 
  U = Kp * error + Kd * derror + Ki * ierror;  
  preverror = error;

  U = U/100;
  Serial.print("         ");
  Serial.println(U);
    
}




void moveForward()
{
  
  
  if(U>=0)
  {
    analogWrite(motorRight1, sPeed);
    analogWrite(motorRight2, 0);
    analogWrite(motorLeft1, sPeed-U);
    analogWrite(motorLeft2, 0);
  }  

  else if(U<0)
  {
    analogWrite(motorRight1, sPeed+U);
    analogWrite(motorRight2, 0);
    analogWrite(motorLeft1, sPeed);
    analogWrite(motorLeft2, 0);
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
    delay(500);
    
    while( sensorValues[0] > 500 )
    { 
      moveForward();
      readIR();
    }  
    
    delay(100);
    
    while( sensorValues[2] < 500 ) 
    {
      moveLeftUturn();
      readIR();
    }  
}






void leftHandRight()  ///////////////////////////////////////////////////////////////
{
    moveStop();
    delay(1000);
    
    /*while( sensorValues[7] > 500 )
    { 
      moveForward();
      readIR();
    }  
    
    delay(500);
    */
    
    while( sensorValues[4] < 500 ) 
    {
      moveRightUturn();
      readIR();
    }  
}
 
