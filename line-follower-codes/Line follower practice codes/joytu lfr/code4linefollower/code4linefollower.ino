


const int analogInPin1 = A0, analogInPin2 = A1, analogInPin3 = A2, analogInPin4 = A3, analogInPin5 = A4, analogInPin6 = A5 ,analogInPin7 = A6;
                             //**************** motors******************//
const int rightMotor1 = 8, rightMotor2 = 7,  leftMotor1 = 3 ,leftMotor2 =4;
                            //***************** sensors ****************//
int sensorValue1 = 0, sensorValue2 = 0, sensorValue3 = 0,  sensorValue4 = 0,  sensorValue5 = 0,  sensorValue6 = 0 ,sensorValue7 = 0;
int handler = 750,frontHandler=550, leftPWM = 10, rightPWM =11;
                            //******************Functions****************//
#define goLeft();      digitalWrite(leftMotor1,LOW);digitalWrite(leftMotor2,LOW);digitalWrite(rightMotor1,HIGH);digitalWrite(rightMotor2,LOW);Serial.println("left")
#define goFront();     digitalWrite(leftMotor1,HIGH);digitalWrite(leftMotor2,LOW);digitalWrite(rightMotor1,HIGH);digitalWrite(rightMotor2,LOW);Serial.println("mid")
#define goRight();     digitalWrite(leftMotor1,HIGH);digitalWrite(leftMotor2,LOW);digitalWrite(rightMotor1,LOW);digitalWrite(rightMotor2,LOW);Serial.println("right")

                            //***************** booleans ***************//
                            //***************** maze array **************//
int maze[10]={0,0,0,0,0,0,0,0,0,0};
void setup() {
  pinMode(leftMotor1,OUTPUT); pinMode(leftMotor2,OUTPUT); pinMode(rightMotor1,OUTPUT); pinMode(rightMotor2,OUTPUT);
  pinMode(leftPWM,OUTPUT); pinMode(rightPWM,OUTPUT);
  Serial.begin(9600); 
}

void loop() 
{   
  
  int leftValues = 0, rightValues =0;
  // delay(1000);
  // read the analog in value:
  sensorValue1 = analogRead(analogInPin1); if(sensorValue1>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue2 = analogRead(analogInPin2); if(sensorValue2>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue3 = analogRead(analogInPin3); if(sensorValue3>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue4 = analogRead(analogInPin4); if(sensorValue4>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue5 = analogRead(analogInPin5); if(sensorValue5>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue6 = analogRead(analogInPin6); if(sensorValue6>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue7 = analogRead(analogInPin7);
  
  // print the results to the serial monitor:
  Serial.print("sensor 1 = " );  Serial.print(sensorValue1);  Serial.print("\n"); 
  Serial.print("sensor 2 = " );  Serial.print(sensorValue2);  Serial.print("\n");
  Serial.print("sensor 3 = " );  Serial.print(sensorValue3);  Serial.print("\n");
  Serial.print("sensor 4 = " );  Serial.print(sensorValue4);  Serial.print("\n");                           
  Serial.print("sensor 5 = " );  Serial.print(sensorValue5);  Serial.print("\n");
  Serial.print("sensor 6 = " );  Serial.print(sensorValue6);  Serial.print("\n");
  
  Serial.print("\t \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ \n");
    if(sensorValue1 > handler || sensorValue6 > handler){analogWrite(leftPWM,200);analogWrite(rightPWM,200);}
    else if(sensorValue2 > handler || sensorValue5 > handler){analogWrite(leftPWM,180);analogWrite(rightPWM,180);}
    else if(sensorValue3 > handler || sensorValue4 > handler) {analogWrite(leftPWM,160);analogWrite(rightPWM,160);}
  
    else {analogWrite(leftPWM,160);analogWrite(rightPWM,160);}
                                          
     // if()
      if(leftValues > rightValues ){do{goLeft();}while(!onLine());}
      else if (leftValues == rightValues && frontPresent()){goFront();}                   
      else if (leftValues < rightValues){do{goRight();}while(!onLine());}
      else if (!frontPresent()){ turnBack(); }
      
      


 }
 
bool onLine()
 {
   int leftValues = 0, rightValues =0;
  sensorValue1 = analogRead(analogInPin1); if(sensorValue1>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue2 = analogRead(analogInPin2); if(sensorValue2>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue3 = analogRead(analogInPin3); if(sensorValue3>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue4 = analogRead(analogInPin4); if(sensorValue4>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue5 = analogRead(analogInPin5); if(sensorValue5>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue6 = analogRead(analogInPin6); if(sensorValue6>handler) {leftValues++;Serial.println(leftValues);}
  
   if(sensorValue1 < handler && sensorValue2 < handler && sensorValue3 > handler && sensorValue4 > handler && sensorValue5 < handler && sensorValue6 < handler ){return true;}
   return false;
 }
bool frontPresent()
{ 
  
  sensorValue7 = analogRead(analogInPin7); 
  
  if(sensorValue7>frontHandler )return true;
  return false;
  
}
void turnBack()
{
  analogWrite(leftPWM,200);analogWrite(rightPWM,230);
  do
  {
    int leftValues = 0, rightValues =0;
  sensorValue1 = analogRead(analogInPin1); if(sensorValue1>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue2 = analogRead(analogInPin2); if(sensorValue2>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue3 = analogRead(analogInPin3); if(sensorValue3>handler) {rightValues++;Serial.println(rightValues);}
  sensorValue4 = analogRead(analogInPin4); if(sensorValue4>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue5 = analogRead(analogInPin5); if(sensorValue5>handler) {leftValues++;Serial.println(leftValues);}
  sensorValue6 = analogRead(analogInPin6); if(sensorValue6>handler) {leftValues++;Serial.println(leftValues);}
  if(sensorValue1>handler||sensorValue2>handler)analogWrite(leftPWM,160);analogWrite(rightPWM,180);
    digitalWrite(leftMotor1,HIGH);digitalWrite(leftMotor2,LOW);digitalWrite(rightMotor1,LOW);digitalWrite(rightMotor2,HIGH);
  }while(!frontPresent());
}
