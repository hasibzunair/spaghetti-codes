
#include <VirtualWire.h> // for radio comm transmission


const int inputPin= 2; //for PIR sensor

float tempC;
int tempPin = 0; //Temp sensor plugged in analogpin 0


#define trigPin 6//distance sensor
#define echoPin 7

int sensePin = 1;//brighness

// pin for force sensor defined on function of FORCE

void setup(){                                                      //SETUP FUNCTION
 
 
// Initialize the IO and ISR
vw_setup(2000); // Bits per sec
 
 
 
 pinMode(inputPin, INPUT);//pir
 
 pinMode(tempPin, INPUT);// temp
 
 pinMode(trigPin ,OUTPUT);//distance
 pinMode(echoPin, INPUT);
 
 analogReference(DEFAULT);//brightness
 
 
 
 Serial.begin(9600); //Set up serial comm
 Serial.println("                    [[[[[[[*****ROVER CONTROl STATION*****]]]]]]]                ");
 Serial.println(""); 
 Serial.println("                              INITIALIZE TRANSMISSION                            ");  
 Serial.println(""); 
 Serial.println("_________________________________________________________________________________");
 Serial.println("MOTION SENSOR        TEMPERATURE        BRIGHTNESS        DISTANCE        FORCE  "); 
 Serial.println("_________________________________________________________________________________");
 Serial.println(""); 
 Serial.println(""); 
  
}


void loop(){                                                              //LOOP FUNCTION


 checkPir();
 checkTemp();
 checkDist();
 checkLux();
 checkForce();

 delay(10);


} // end of void loop!




void checkPir(){
  
    //PIR MOTION
  
 int value= digitalRead(inputPin); //read 1/0 from motion sensor

  if (value == HIGH)
{   
   
   Serial.println("MOTION DETECTED!");
  
}
   else{}


//end of PIR
  
  
}

void checkTemp(){
  
     //TEMP SENSE 


  tempC = analogRead(tempPin); //Takes tempPin reading and sets equal to tempC variable
  tempC = (5.0*tempC*100.0)/1024.0; //Convert the analog input to temp in celcius
 
  if(tempC<=28){ Serial.println("                       Normal");}
  else if(tempC<=35 &&  tempC >=28   ){ Serial.println("                       Average");}
  else if(tempC<=40 &&  tempC >= 35   ){ Serial.println("                       MEDIUM");}
  else if(tempC<=48 &&  tempC >= 40   ){ Serial.println("                       DANGER");}
  else if(tempC<=58 &&  tempC >= 48  ){ Serial.println("                       EXTREME!! :O");}
  
  
 
   
 //end of temp sense
 
  
  
  
}

void checkDist(){
  
    //DISTANCE


  int duration ,distance;
  
  digitalWrite(trigPin, HIGH);
  delay(700);                        // error minimized using this DELAY!! :D
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1; //29.1 is the inverse of speed of light

  
  if(distance<5){Serial.println("                                                           NEAR");}
  
  else if(distance<20 && distance >5){Serial.println("                                                           FAR");}
  
  else if(distance >20){Serial.println("                                                           TOO FAR");}
  
  
 
 
 //end of distance
 
 


  
  
}

void checkLux(){
  
   //LDR

 int val = analogRead(sensePin);
  
  val = constrain(val ,40 , 150);
  
  
  if(val<60){ Serial.println("                                         DARK");}
  else if(val<100 && val>60){ Serial.println("                                         AVERAGE");}
  else if(val>100){ Serial.println("                                         VERY BRIGHT");}
  
 
  
}

void checkForce(){
  
  //FORCE


 int sensorValue = analogRead(A2);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  if(voltage<2){Serial.println("                                                                          LIGHT");}
  
  else if(voltage<3.5 && voltage>2){Serial.println("                                                                          MEDIUM");}
  
  else if(voltage>3.5){Serial.println("                                                                          HEAVY");}
 
  
//end of force
  
  
}


void send (char *message)   //for radio comm functions
{
vw_send((uint8_t *)message, strlen(message));
vw_wait_tx(); // Wait until the whole message is gone
}


