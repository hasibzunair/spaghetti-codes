#include <QTRSensors.h>

int finish = 0;
int end11=0,i=0,i1=0,i2=0;
char read11[100],mread[100];

int counter = 0;

const int motorRight1 = 10;
const int motorRight2 = 9;

const int motorLeft1 = 5;
const int motorLeft2 = 6;


int x = 10; // delay value= 100 !!!

int led1 = 3;

int sPeed = 255;

float Kp = 5; //5,4
float Kd = 1; // 1,3
float Ki = 0;

//
int preverror = 0;
int error = 0;
int derror = 0;
int ierror = 0;

int U;


#define NUM_SENSORS   10    // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) { A5, A4, A2, A0, 13, 11,  7, 4, A1, A3 }, //{A5, A4, A3, A2, A1, A0, 5, 7, 8, 11, 12 , 13},
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
  
  while ( finish == 0 )
  {
    readIR();
    computePID();
    moveForward();
    if ( sensorValues[0] > 500 && sensorValues[1] > 500 && sensorValues[2] > 500 && sensorValues[3] > 500 && sensorValues[4] > 500 && sensorValues[5] > 500 && sensorValues[6] > 500 && sensorValues[7] > 500 && sensorValues[8] > 500 && sensorValues[9] > 500) leftHandend11();
    
    if(sensorValues[0] > 500 && sensorValues[3] > 500)leftHandLeft2();
    else if (sensorValues[0] > 500 && sensorValues[3] < 500) leftHandLeft();
    else if (sensorValues[7] > 500 && sensorValues[3] > 500)leftHandRightStraight();
    else if (sensorValues[7] > 500) leftHandRight();          
    else if ( sensorValues[1] < 500 && sensorValues[2] < 500 && sensorValues[3] < 500 && sensorValues[4] < 500 && sensorValues[5] < 500 && sensorValues[6] < 500  ) leftHandUturn();
  }

  while ( finish == 1 )
  {
    
    counter = 0;

    
    if (mread[counter] == 'l')
    else if (mread[counter] == 'r')
    else if (mread[counter] == 's')
    else if (mread[counter] == 'b') 
    else 

    
  }

}


void calibration()
{
  //delay(500);
  //pinMode(13, OUTPUT);
  //digitalWrite(13, HIGH);    // turn on Arduino's LED to indicate we are in calibration mode
  for (int i = 0; i < 400; i++)  // make the calibration take about 10 seconds
  {
    qtrrc.calibrate();       // read11s all sensors 10 times at 2500 us per read11 (i.e. ~25 ms per call)
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
  // read11 calibrated sensor values and obtain a measure of the line position from 0 to 5000
  // To get raw sensor values, call:
  //  qtrrc.read11(sensorValues); instead of unsigned int position = qtrrc.read11Line(sensorValues);
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

  computePID();
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
      digitalWrite(led1, HIGH);
    }  
    digitalWrite(led1, LOW);
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
       digitalWrite(led1, HIGH);
    }  
     digitalWrite(led1, LOW);
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
      digitalWrite(led1, HIGH);
    }  
    digitalWrite(led1, LOW);
}


 void leftHandRightStraight()
{
   while(sensorValues[7] > 500) 
   {   
      readIR();
      sensorValues[6] = sensorValues[1];
      moveForward();
       digitalWrite(led1, HIGH);
   }
    digitalWrite(led1, LOW);
    read11[counter] = 's';
    counter++;
}



void leftHandUturn()
{
  while (sensorValues[2] < 500)
  {
    moveLeftSharpTurn();
    readIR();
    digitalWrite(led1, HIGH);
  }
   digitalWrite(led1, LOW);
  moveForward();
  delay(100);

  read11[counter] = 'b';
  counter++;

}

void leftHandend11()
{
  moveStop();

  delay(1000);
 

  finish = 1;
  tanvirDiode();

  while (sensorValues[8]>500)
  {

    
  }
  while (sensorValues[3] > 500)
  {
    moveLeftSharpTurn();
    readIR();
  }

  while (sensorValues[3] < 500)
  {
    moveLeftSharpTurn();
    readIR();
  }

}

void tanvirDiode()
{
  while(finish!=1)
{


    for(i1=0;i1<=i;i1++)
    {
        if(read11[i1]=='l' && read11[i1+1]=='b' && read11[i1+2]=='r')
        {
          mread[i2]= 'b' ;
           printf("\n\n\n%c   %c",read11[i1],mread[i2]);
          i1+=2;
          i2++;
        }
        else if(read11[i1]=='l' && read11[i1+1]=='b' && read11[i1+2]=='s')
        {
          mread[i2]= 'r' ;
           printf("\n\n\n%c   %c",read11[i1],mread[i2]);
          i1+=2;
          i2++;
        }
        else if(read11[i1]=='r' && read11[i1+1]=='b' && read11[i1+2]=='l')
        {
          mread[i2]= 'b' ;
          i1+=2;
          i2++;
        }
        else if(read11[i1]=='s' && read11[i1+1]=='b' && read11[i1+2]=='l')
        {
          mread[i2]= 'r' ;
          i1+=2;
          i2++;
        }
        else if(read11[i1]=='s' && read11[i1+1]=='b' && read11[i1+2]=='s')
        {
          mread[i2]= 'b' ;
          i1+=2;
          i2++;
        }
        else if(read11[i1]=='l' && read11[i1+1]=='b' && read11[i1+2]=='l')
        {
          mread[i2]= 's' ;
           printf("\n\n\n%c   %c",read11[i1],mread[i2]);
          i1+=2;
          i2++;
        }
        else
        {
            mread[i2]=read11[i1];
            printf("\n\n\n%c   %c",read11[i1],mread[i2]);
            i2++;
        }
    }
    if( strcmp(read11,mread)==0)
    {
        finish=1;
    }
    else
    {
       strcpy(read11,mread);
       i1=i2;
       i2=0;
    }



    printf("\n finish");
}

    printf("\ninput = ");
    for(i=0;i<31;i++)
    {
        if(read11[i]!='0' )
        {
            printf("%c",read11[i]);
        }
        else{break;}

    }
  
}

