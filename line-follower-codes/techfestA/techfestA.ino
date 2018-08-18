#include <EEPROM.h>
#include <QTRSensors.h>
//#include <SoftwareSerial.h>// import the serial library

#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   QTR_NO_EMITTER_PIN     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {7, 6, 5, 4, 3, 35, 33, 31},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


//const int rSpeed = 6;
//const int lSpeed = 5 ;
const int motor_a0 = 8;
const int motor_b0 = 9;
const int motor_a1 = 11;
const int motor_b1 = 10;



int baseSpeed = 100;
int maxSpeed = 200;
int minSpeed = -240;

int lastError = 0;
int error = 0;
int p, intg, d;

double kp = 0.032; //80// 0.04
double ki = 0; //0.5//0
double kd = 0.032; //70//0.08

// 0.032, 0,0.032

/*
bs = 120 ms = 240
0.04,0,0.08

bs = 100 , ms = 200
0.032 0 0.032

*/
boolean temp1;




String readText;
int BluetoothData;


void setup()
{
//  setPwmFrequency(5,1024);
 Serial.begin(9600);
  Serial3.begin(9600);
  
  delay(500);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  
  analogWrite(motor_a0, 100);
  analogWrite(motor_b0, LOW);
  analogWrite(motor_a1, LOW);
  analogWrite(motor_b1, 100);

  // turn on Arduino's LED to indicate we are in calibration mode
  for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    qtrrc.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
  }

  stp();
  
  digitalWrite(13, LOW);     // turn off Arduino's LED to indicate we are through with calibration

  // print the calibration minimum values measured when emitters were on
  
  
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMaximumOn[i]);
    Serial.print(' ');
  }
  Serial.println();
  
  // print the calibration maximum values measured when emitters were on
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(qtrrc.calibratedMinimumOn[i]);
    Serial.print(' ');
  }


  Serial.println();
  Serial.println();
  delay(1000);

  
}


void loop()
{
   if(Serial3.available()) BT();

//   Serial.println(kp);
  

//sensor read
  unsigned int position = qtrrc.readLine(sensorValues);
 
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  //Serial.println(); // uncomment this line if you are using raw values
  Serial.println(position); // comment this line out if you are using raw values
  
  //delay(250);


  //Serial.println(kp);
 
  error=position-3500;

  p = error;
  intg += error;
  d = error - lastError;
  lastError = error;

  if (intg > 255) {
    intg = 255;
  };
  if (intg < -255) {
    intg = -255;
  };

  double correction = (kp * p) + (ki * intg) + (kd * d);

  int  rightMotorSpeed = baseSpeed + correction;
  int leftMotorSpeed = baseSpeed - correction;

  if (rightMotorSpeed < minSpeed) rightMotorSpeed = minSpeed;
  else if (rightMotorSpeed > maxSpeed) rightMotorSpeed = maxSpeed;

  if (leftMotorSpeed < minSpeed) leftMotorSpeed = minSpeed;
  else if (leftMotorSpeed > maxSpeed) leftMotorSpeed = maxSpeed;

  if ( leftMotorSpeed > 0 && rightMotorSpeed > 0)
  {
      analogWrite(motor_a0, leftMotorSpeed);
      analogWrite(motor_b0, LOW);
      analogWrite(motor_a1, rightMotorSpeed);
      analogWrite(motor_b1, LOW);
  }
  else if ( leftMotorSpeed < 0 && rightMotorSpeed > 0)
  {

      analogWrite(motor_b0, leftMotorSpeed);
      analogWrite(motor_a0, LOW);
      analogWrite(motor_b1, LOW);
      analogWrite(motor_a1, rightMotorSpeed);
  }

  else if ( leftMotorSpeed > 0 && rightMotorSpeed < 0)
  {
      analogWrite(motor_b0, LOW);
      analogWrite(motor_a0, leftMotorSpeed);
      analogWrite(motor_b1, rightMotorSpeed);
      analogWrite(motor_a1, LOW);
      
  }

//end of pid algorithm

/// logic codes written below
if ( sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500 && sensorValues[3] > 500 && sensorValues[4] > 500 && sensorValues[5] > 500 && sensorValues[6] > 500 &&sensorValues[7] > 500  ) goForward();
if ( sensorValues[0] < 500 && sensorValues[1] < 500 || sensorValues[2] > 500 && sensorValues[3] > 500 && sensorValues[4] > 500 && sensorValues[5] > 500 && sensorValues[4] > 500 && sensorValues[5] > 500  ) right_prior();

else if ( sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500 && sensorValues[3] > 500 && sensorValues[4] < 500 && sensorValues[5] < 500 && sensorValues[6] < 500 && sensorValues[7] < 500) left_prior();

 
}// end of loop

void readIR()
{
  // read calibrated sensor values and obtain a measure of the line position from 0 to 5000
  // To get raw sensor values, call:
  //  qtrrc.read(sensorValues); instead of unsigned int position = qtrrc.readLine(sensorValues);

   unsigned int position = qtrrc.readLine(sensorValues);
 
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensorValues[i]);
    Serial.print('\t');
  }
  //Serial.println(); // uncomment this line if you are using raw values
  Serial.println(position); // comment this line out if you are using raw values
  
  //delay(250);


}

void right_prior()
{
      goRight();
      readIR();

//go right until middle sensors are black

    while ( sensorValues[3] > 500 && sensorValues[4] > 500 ) 
    {
      goForward();
      readIR();
    }
  
}


void left_prior()
{
    goLeft();

    readIR();
// go left until middle sensors are black
   
    while( sensorValues[3] > 500 && sensorValues[4] > 500 ) 
    {
      goForward();
      readIR();
    }  


  
}

void goForward()
{
  analogWrite(motor_a0, baseSpeed);
  analogWrite(motor_b0, LOW);
  analogWrite(motor_a1, baseSpeed);
  analogWrite(motor_b1, LOW);

}

void goBackward()
{
  digitalWrite(motor_a0, LOW);
  digitalWrite(motor_b0, HIGH);
  digitalWrite(motor_a1, LOW);
  digitalWrite(motor_b1, HIGH);
}

void goRight()
{

  digitalWrite(motor_a0, baseSpeed);
  digitalWrite(motor_b0, LOW);
  digitalWrite(motor_a1, LOW);
  digitalWrite(motor_b1, baseSpeed);


}

void goLeft()
{
  digitalWrite(motor_a0, LOW);
  digitalWrite(motor_b0, baseSpeed);
  digitalWrite(motor_a1, baseSpeed);
  digitalWrite(motor_b1, LOW);


}

void stp()
{

//  analogWrite(rSpeed, 0);
//  analogWrite(lSpeed, 0);
  digitalWrite(motor_a0, LOW);
  digitalWrite(motor_b0, LOW);
  digitalWrite(motor_a1, LOW);
  digitalWrite(motor_b1, LOW);


}

boolean noLineIsThere()
{
  temp1 = true;

  for (int i = 0; i < NUM_SENSORS; i++)
  {
    if (sensorValues[i] == 0)
    {
      temp1 = temp1 && true;
    }

    else if  (sensorValues[i] == 1) temp1 = temp1 && false ;

  }



  return temp1;
}

void setPwmFrequency(int pin, int divisor) {
  byte mode;
  if(pin == 5 || pin == 6 || pin == 9 || pin == 10) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 64: mode = 0x03; break;
      case 256: mode = 0x04; break;
      case 1024: mode = 0x05; break;
      default: return;
    }
    if(pin == 5 || pin == 6) {
      TCCR0B = TCCR0B & 0b11111000 | mode;
    } else {
      TCCR1B = TCCR1B & 0b11111000 | mode;
    }
  } else if(pin == 3 || pin == 11) {
    switch(divisor) {
      case 1: mode = 0x01; break;
      case 8: mode = 0x02; break;
      case 32: mode = 0x03; break;
      case 64: mode = 0x04; break;
      case 128: mode = 0x05; break;
      case 256: mode = 0x06; break;
      case 1024: mode = 0x7; break;
      default: return;
    }
    TCCR2B = TCCR2B & 0b11111000 | mode;
  }
}



void BT()
{
  while (Serial3.available())
  {
    delay(3);
    char c =  Serial3.read();
    readText += c;
    
  }

  if (readText.length() > 0)
  {
    //Serial.println(readText);
    if (readText[0] == 'P') kp = converter(readText);
    else if (readText[0] == 'I') ki = converter(readText);
    else if (readText[0] == 'D') kd = converter(readText);
    else if (readText[0] == 'B') baseSpeed = converter(readText);
    else if (readText[0] == 'H') maxSpeed = converter(readText);
    else if (readText[0] == 'L') minSpeed = -converter(readText);
    else if (readText[0] == 'S'){

      

    }
  } 
    readText=""; 
  
  



}


float converter (String x)
{
  int l = x.length();
  char z[l];
  for ( int i=0; i<l; i++)
    z[i] = x[i+1];
  return atof(z);
}

