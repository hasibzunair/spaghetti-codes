float tempC;
int tempPin = 0;

int pin3 = 3;
int pin5 = 5; 
int pin6 = 6;
int pin7 = 7;
int pin8 = 8;
int pin9 = 9;
int pin10 = 10;
int pin13 = 13;

int piezoPin = 11;


void setup()
{
  Serial.begin(9600);
  pinMode(pin3 ,OUTPUT); 
  pinMode(pin13 ,OUTPUT);
  pinMode(pin5 ,OUTPUT);
  pinMode(pin6 ,OUTPUT);
  pinMode(pin7 ,OUTPUT);
  pinMode(pin8 ,OUTPUT);
  pinMode(pin9 ,OUTPUT);
  pinMode(pin10 ,OUTPUT);
  pinMode(piezoPin ,OUTPUT);
  
}


void loop()
{
  tempC = analogRead(tempPin); 
  tempC = (5.0*tempC*100.0)/1024.0; 
  Serial.println((byte)tempC); 
  delay(1000);
 
  
  if(tempC>=23){digitalWrite(pin10,HIGH);}
  if(tempC>=28){digitalWrite(pin9,HIGH);}
  if(tempC>=35){digitalWrite(pin8,HIGH);}
  if(tempC>=39){digitalWrite(pin7,HIGH);}
  if(tempC>=45){digitalWrite(pin6,HIGH);}
  if(tempC>=47){digitalWrite(pin5,HIGH);}
  if(tempC>=50){digitalWrite(pin13,HIGH);}
  if(tempC>=55)
  {
    digitalWrite(pin3,HIGH);
    tone(11 , 1500 ,5000);
  }
  
  //add this for flashing signal
  /*delay(10);
  digitalWrite(pin10,LOW);
  digitalWrite(pin9,LOW);
  digitalWrite(pin8,LOW);   
  digitalWrite(pin7,LOW);
  digitalWrite(pin6,LOW);
  digitalWrite(pin5,LOW);
  digitalWrite(pin13,LOW);
  digitalWrite(pin3,LOW);
  delay(10);
  */
  
   if(tempC<=23){digitalWrite(pin10,LOW);}
   if(tempC<=33){digitalWrite(pin9,LOW);}
   if(tempC<=35){digitalWrite(pin8,LOW);}
   if(tempC<=39){digitalWrite(pin7,LOW);}
   if(tempC<=45){digitalWrite(pin6,LOW);}
   if(tempC<=47){digitalWrite(pin5,LOW);}
   if(tempC<=50){digitalWrite(pin13,LOW);}
   if(tempC<=55){ digitalWrite(pin3,LOW);} 
  
}
