#include <QTRSensors.h>



const int motorRight1 = 10;
const int motorRight2 = 9;

const int motorLeft1 = 5;
const int motorLeft2 = 6;


int x = 10; // delay value!!!

int led1 = 2;

int sPeed = 255;

float Kp = 5;
float Kd = 1;
float Ki =0;

//
int preverror = 0;
int error = 0;
int derror = 0;
int ierror = 0;

int U;


#define NUM_SENSORS   8    // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) { A5, A4, A2, A0, 13, 11,  7, 4 }, //{A5, A4, A3, A2, A1, A0, 5, 7, 8, 11, 12 , 13},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


void setup()
{
  pinMode(led1,OUTPUT); // ledPin
  pinMode(motorRight1, OUTPUT);   
  pinMode(motorRight2, OUTPUT);   
  pinMode(motorLeft1, OUTPUT);   
  pinMode(motorLeft2, OUTPUT);  

  calibration();

}


void loop()
{
  readIR();
  computePID();
  moveForward();
  if ( sensorValues[1] > 500 && sensorValues[2] > 500 && sensorValues[3] > 500 && sensorValues[4] > 500 && sensorValues[5] > 500 && sensorValues[6] > 500  ) leftHandEnd();
  if (sensorValues[0] > 500 && sensorValues[3] < 500) leftHandLeft();
  else if(sensorValues[0] > 500 && sensorValues[3] > 500)leftHandLeft2();
  else if (sensorValues[7] > 500 && sensorValues[3] > 500)leftHandRightStraight();
  else if (sensorValues[7] > 500) leftHandRight();
  else if ( sensorValues[1] < 500 && sensorValues[2] < 500 && sensorValues[3] < 500 && sensorValues[4] < 500 && sensorValues[5] < 500 && sensorValues[6] < 500  ) leftHandUturn();
  

  

}


void calibration()
{
  //delay(500);
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
  delay(100); //delay(1000);
  
}

void readIR()
{
  // read calibrated sensor values and obtain a measure of the line position from 0 to 5000
  // To get raw sensor values, call:
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);
  unsigned int position = qtrrc.readLine(sensorValues);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum reflectance and
  // 1000 means minimum reflectance, followed by the line position
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  Serial.println(); // uncomment this line if you are using raw values
  //Serial.print('   ');
  //Serial.print(position); // comment this line out if you are using raw values


}


void computePID()
{
  error =    (-3*sensorValues[1]) + (-2*sensorValues[2]) + (-1*sensorValues[3]) + (1*sensorValues[4]) + (2*sensorValues[5]) + (3*sensorValues[6]);
  derror = error - preverror;
  ierror += error; 
  U = Kp * error + Kd * derror + Ki * ierror;  
  preverror = error;

  U = U/100;
  Serial.print("            ");
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

void moveLeftSharpTurn(){
  
  analogWrite(motorRight1, 0);
  analogWrite(motorRight2, sPeed);
  analogWrite(motorLeft1, sPeed);
  analogWrite(motorLeft2, 0);
}


void moveRightSharpTurn(){
  
  analogWrite(motorRight1, sPeed);
  analogWrite(motorRight2, 0);
  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, sPeed);
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
    delay(x);
    
    
    while( sensorValues[0] > 500 )
    { 
      moveForward();
      readIR();
    }  
    
    //delay(100);

    while( sensorValues[3] < 500 ) 
    {
      moveLeftSharpTurn();
      readIR();
    }  
}



void leftHandLeft2()
{
    moveStop();
    delay(x);
    
    
    while( sensorValues[0] > 500 )
    { 
      moveForward();
      readIR();
    }  
    
    //delay(100);

    while( sensorValues[3]>500)
    {
      moveLeftSharpTurn();
      readIR();
    }
    
    while( sensorValues[3] < 500 ) 
    {
      moveLeftSharpTurn();
      readIR();
    }  
}


void leftHandRight()  ///////////////////////////////////////////////////////////////
{
    moveStop();
    delay(x);
    
    
    while( sensorValues[7] > 500 )
    { 
      moveForward();
      readIR();
    }  
    
    
    
    
    while( sensorValues[4] < 500 ) 
    {
      moveRightSharpTurn();
      readIR();
    }  
}


 void leftHandRightStraight()
{
   while(sensorValues[7] > 500) 
   {   
      moveForward();
      readIR();
   }
   
}



void leftHandUturn()
{
  while (sensorValues[2] < 500)
  {
    moveLeftSharpTurn();
    readIR();
  }

}

void leftHandEnd()
{
  moveStop();
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  delay(1000);
  digitalWrite(led1, HIGH);
  delay(1000);
}

