#include <QTRSensors.h>


////////////////Set these parameters////////////////////////////////////////////////////////////////////////////////////////////////////////////
int sensorMode = 0; //0-calibrationON & calibrated values; 1-raw values; 2-calibrated+position
int crit = 500; // senorValue<crit: white 
int errorMode = 1; // 0=digital & 1=analog

int turnStDelay = 100;

int fullSpeed = 150;
int turnSpeed = 90;
int lowSpeed = 0;

float Kp = 55;
float Kd = 0;
float Ki = 0;
//////////////////////////////////////////////////////





#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   22     // emitter is controlled by digital pin 2
// sensors 0 through 7 are connected to digital pins
QTRSensorsRC qtrrc((unsigned char[]) { 7, 6, 5, 4, 3, 35, 33, 31 }, 
NUM_SENSORS, TIMEOUT, EMITTER_PIN);



String readString;

const int motorRight1 = 9;
const int motorRight2 = 8;

const int motorLeft1 = 10;
const int motorLeft2 = 11;


int vel;


//
float preverror = 0;
float error = 0;
float derror = 0;
float ierror = 0;

float U;


unsigned int sV[NUM_SENSORS];
bool bSV[NUM_SENSORS]; //sensor values in binary



int flip = 0; // 1=right sensors flipped -1=left sensor flipped
int turn = 0; // 1=right turn  -1=left turn 3=right at finish

int invert = 1;
int firstCross = 0;

void setup()
{

  pinMode(motorRight1, OUTPUT);
  pinMode(motorRight2, OUTPUT);
  pinMode(motorLeft1, OUTPUT);
  pinMode(motorLeft2, OUTPUT);

  if (sensorMode != 1) calibration();
  Serial.begin(9600);
  Serial3.begin(9600);

}


void loop()
{

  if (Serial3.available() > 0) BT();

  readIR();

  
    
    if ( sensorCheck("x111111x") ) 
    {
      turn = 3; 
      flip = 0;
    }
    
    //90 turn
    else if (  turn !=3 && sensorCheck("1111xxx0") )
    {
      flip = -1; 
      turn = -1;  
    }
    
    //30 turn
    else if ( turn !=3 && sensorCheck("1xx||xx0") ) // or this logic: 1oo| |xx0 
    {
      flip = -1; 
      turn = -2;   
    }
    
    
    //90 turn
    else if (  turn !=3 && sensorCheck("0xxx1111") ) 
    {
      flip = 1; 
      turn = 1;  
    }
    //30 turn
    else if (  turn !=3 && sensorCheck("0xx||xx1") ) //or this logic 0xx| |oo1 
    {
      flip = 1; 
      turn = 2; 
    }

  
    if (flip == 1) sensorFlip(1);
    else if (flip == -1) sensorFlip(-1);
    
    if ( sensorCheck("00000000") )  //( allwhite() )
    {
        flip = 0;
        //turn = 0;
        
        if ( (turn == 1) || (turn == 2) ) rightTurn();
        else if ( (turn == -1) || (turn == -2) ) leftTurn();
        //else if (turn == 0) goStraight();  //if turn=0; do nothing, go straight on PID algorithm 
    }
  
    
    if ( (turn == 3 || turn==1) && sensorCheck("0xxxxxx0") ) rightTurn();
      
    if ( (turn == 2) && sensorCheck("0xxxxxx0") ) leftTurn();
  

  
  
  
  computePID();
  moveRobot();

}






void calibration()
{
  delay(50);
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
  Serial.println();
  // read calibrated sensor values and obtain a measure of the line position from 0 to 5000
  // To get raw sensor values, call:
  //  qtrrc.read(sV); instead of unsigned int position = qtrrc.readLine(sV);

  //unsigned int position = qtrrc.readLine(sV);
  if ( sensorMode == 0 ) qtrrc.readCalibrated(sV);
  else if ( sensorMode == 1 ) qtrrc.read(sV);
  else if ( sensorMode == 2 ) int position = qtrrc.readLine(sV);

  // print the sensor values as numbers from 0 to 1000, where 0 means maximum reflectance and
  // 1000 means minimum reflectance, followed by the line position
  for (unsigned char i = 0; i < NUM_SENSORS; i++)
  {

    
    ///////////////////scaes raw values from 0-1000
    if (sensorMode==1) sV[i] = map(sV[i], 0, 2500, 0, 1000);

    /////////////////////////////////////////
    if ( sV[i]>crit ) bSV[i] = 1;
      else bSV[i] = 0;

    Serial.print(sV[i]);
    Serial.print("--");
    Serial.print(bSV[i]);
    Serial.print('\t');
  }
  //Serial.println(); // uncomment this line if you are using raw values
  //Serial.print('   ');
  //Serial.print(position); // comment this line out if you are using raw values
  
  if ( firstCross==1 && sensorCheck("000||000") ) invert = 0;
  if (invert==1) invertSV();

}




void computePID()
{
  //analog version of code
  if (errorMode == 1)
    error = ( (-4.0*sV[0]) + (-3.0*sV[1]) + (-2.0*sV[2]) + (-1.0*sV[3]) + (1.0*sV[4]) + (2.0*sV[5]) + (3.0*sV[6]) + (4.0*sV[7]));  
    if ((sV[0]+sV[1]+sV[2]+sV[3]+sV[4]+sV[5]+sV[6]+sV[7]) > 10) error = error/((sV[0]+sV[1]+sV[2]+sV[3]+sV[4]+sV[5]+sV[6]+sV[7]));   
  //
  
  //digital version of code
  if (errorMode == 0)
  {
    error =   ((-4.0*bSV[0]) + (-3.0*bSV[1]) + (-2.0*bSV[2]) + (-1.0*bSV[3])   + (1.0*bSV[4]) + (2.0*bSV[5]) + (3.0*bSV[6]) + (4.0*bSV[7])) ;
    if ((bSV[0]+bSV[1]+bSV[2]+bSV[3]+bSV[4]+bSV[5]+bSV[6]+bSV[7])!=0) error/=(bSV[0]+bSV[1]+bSV[2]+bSV[3]+bSV[4]+bSV[5]+bSV[6]+bSV[7]);
  }
  //
  derror = error - preverror;
  ierror += error;
  U = Kp * error + Kd * derror + Ki * ierror;
  preverror = error;

  Serial.print("            ");
  Serial.print(error);
}





void BT()
{
  while (Serial3.available())
  {
    delay(3);
    char c = Serial3.read();
    readString += c;
  }

  if (readString.length() > 0)
  {
    if (readString[0] == 'P') Kp = converter(readString);
    else if (readString[0] == 'I') Ki = converter(readString);
    else if (readString[0] == 'D') Kd = converter(readString);
    else if (readString[0] == 'H') fullSpeed = converter(readString);
    else if (readString[0] == 'L') turnSpeed = converter(readString);
  }
  readString = "";
}



float converter (String x)
{
  int l = x.length();
  char z[l];
  for ( int i = 0; i < l; i++)
    z[i] = x[i + 1];
  return atof(z);
}




void moveRobot()
{
  if (U < 0)
  { 
    vel = fullSpeed + (int)U;
    if (vel>fullSpeed)vel=fullSpeed;
    else if (vel<lowSpeed) vel=lowSpeed;
    
    analogWrite(motorRight1, fullSpeed);
    analogWrite(motorRight2, 0);
    
    if  (vel>0)
    {
      analogWrite(motorLeft1, abs(vel));
      analogWrite(motorLeft2, 0);
    }

    else
    {
      analogWrite(motorLeft1, 0);
      analogWrite(motorLeft2, abs(vel)); 
      
     }

     Serial.print("       ");
     Serial.print(vel);
     Serial.print("   ");
     Serial.print(fullSpeed);
  }

  else if (U >= 0)
  {
    vel = fullSpeed - (int)U;
    if (vel>fullSpeed)vel=fullSpeed;
    else if (vel<lowSpeed) vel=lowSpeed;

    
    analogWrite(motorLeft1, fullSpeed);
    analogWrite(motorLeft2, 0);

    if (vel>0)
    {
      analogWrite(motorRight1, abs(vel));
      analogWrite(motorRight2, 0);  
    }

    else
    {
      analogWrite(motorRight1,0);
      analogWrite(motorRight2, abs(vel));  
    }

    Serial.print("       ");
    Serial.print(fullSpeed);
    Serial.print("   ");
    Serial.print(vel);
  }
}


int sensorCheck(String val)
{
    //int bSV[]={0,0,0,1,1,1,0,1};
    //char* val = "0xx||oo1";
    
    int rarray[8];
    int returnVal = 1;
    
    for (int i=7; i>=0; i--)
    {
        if ( val[i]=='x' || ( bSV[i]==1 && val[i]=='1' ) || (bSV[i]==0 && val[i]=='0') ) rarray[i]=1;
        else if ( val[i]=='|' && bSV[i]==1 )  rarray[i]=2;
        else if ( val[i]=='|' && bSV[i]==0 ) rarray[i]=3;
        else if ( val[i]=='o' && bSV[i]==0 ) rarray[i]=8;
        else if ( val[i]=='o' && bSV[i]==1 ) rarray[i]=9;
        else rarray[i]=0;
        //printf("%d", rarray[i]);
    }
    
    //printf("\n");
    
    for (int i=0; i<8; i++)
    {
        
        int chkr = 0;
        if (rarray[i]==2 || rarray[i]==3) 
        {   
            int j = i;
            int k = i;
            
            while(j<8 && (rarray[j]==2 || rarray[j]==3))
            {
                if ( rarray[j]==2 ) chkr = 1;
                j++;
            }
            while(k<8 && (rarray[k]==2 || rarray[k]==3))
            {
                if ( chkr == 1) rarray[k]=1;
                else rarray[k]=0;
                k++;
            }
            
        }
        
        if (rarray[i]==8 || rarray[i]==9) 
        {   
            int j = i;
            int k = i;
            
            while(j<8 && (rarray[j]==8 || rarray[j]==9))
            {
                if ( rarray[j]==8 ) chkr = 1;
                j++;
            }
            while(k<8 && (rarray[k]==8 || rarray[k]==9))
            {
                if ( chkr == 1) rarray[k]=1;
                else rarray[k]=0;
                k++;
            }
            
        }
        
        //printf("%d", rarray[i]);
        returnVal*=rarray[i];
    }
    //printf("\n\n\n%d\n\n",returnVal);
    
    return returnVal; //0;
}   



void invertSV()
{
    for (int i=0; i<8; i++)
    {
      sV[i]= 1000 - sV[i];
      bSV[i] = 1 - bSV[i];  
    }
}

void rightTurn()
{

  if (turn!=2)
  {
    moveForward();
    delay(turnStDelay);
  }
  while( bSV[7]==0 )
  {
    moveSharpRight();
    readIR();  
  }
  turn = 0;  

  moveStop();
  delay(50);

  if ( turn == 3 ) firstCross = 1; 
  ierror = 0;
}


void leftTurn()
{
  if (turn != -2)
  {
    moveForward();
    delay(turnStDelay);
  }
  while( bSV[2]==0 )
  {
    moveSharpLeft();
    readIR();  
  }
  turn = 0; 
  ierror = 0; 

}
void goStraight()
{
  while ( sensorCheck("||||||||") )
  {
    moveForward();  
    readIR;
  }
  
  turn = 0;  
}

void sensorFlip(int x)
{
  if ( x=1 )
  {
    sV[7]=sV[0];
    sV[6]=sV[1];
    sV[5]=sV[2];
    bSV[7]=bSV[0];
    bSV[6]=bSV[1];
    bSV[5]=bSV[2];
  }

  if ( x=-1 )
  {
    sV[0]=sV[7];
    sV[1]=sV[6];
    sV[2]=sV[5];
    bSV[0]=bSV[7];
    bSV[1]=bSV[6];
    bSV[2]=bSV[5];
  }
    
}


void moveForward()
{
 analogWrite(motorLeft1,turnSpeed);
 analogWrite(motorLeft2,0);
 analogWrite(motorRight1,turnSpeed);
 analogWrite(motorRight2,0); 
}
void moveSharpRight()
{
 analogWrite(motorLeft1,turnSpeed);
 analogWrite(motorLeft2,0);
 analogWrite(motorRight1,0);
 analogWrite(motorRight2,turnSpeed);
}

void moveSharpLeft()
{
 analogWrite(motorLeft1,0);
 analogWrite(motorLeft2,turnSpeed);
 analogWrite(motorRight1,turnSpeed);
 analogWrite(motorRight2,0);
}

void moveStop()
{
 analogWrite(motorLeft1,0);
 analogWrite(motorLeft2,0);
 analogWrite(motorRight1,0);
 analogWrite(motorRight2,0);
}

