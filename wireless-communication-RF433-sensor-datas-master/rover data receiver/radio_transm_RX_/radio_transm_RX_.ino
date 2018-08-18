
//******************RADIO RECEIVER!!!!!!!!!!!!!!!!!!


#include <VirtualWire.h>

byte message[VW_MAX_MESSAGE_LEN]; // a buffer to hold the incoming messages
byte msgLength = VW_MAX_MESSAGE_LEN; // the size of the message

char incomingbyte;
int ledPin = 8;
int buzPin = 7;

void setup()
{
 Serial.begin(9600);
 Serial.println("                 [[[[[[[*****ROVER WIRELESS CONTROl STATION*****]]]]]]]          ");
 Serial.println(""); 
 Serial.println("                              INITIALIZING TRANSMISSION......                    ");  
 delay(3000);
 
 Serial.println(""); 
 Serial.println("_________________________________________________________________________________");
 Serial.println("MOTION SENSOR        TEMPERATURE        BRIGHTNESS        DISTANCE        FORCE  "); 
 Serial.println("_________________________________________________________________________________");
 Serial.println(""); 
 Serial.println(""); 
 delay(3000); 
 
 
// Initialize the IO and ISR
vw_setup(2000); // Bits per sec
vw_rx_start(); // Start the receiver

pinMode(ledPin, OUTPUT);
pinMode(buzPin, OUTPUT);

}

void loop()
{
  
 
if (vw_get_message(message, &msgLength)) // Non-blocking

{
  
digitalWrite(ledPin,HIGH);
digitalWrite(buzPin,HIGH);
delay(100);
digitalWrite(ledPin,LOW); 
digitalWrite(buzPin,LOW);

  
//read the byte and store it in incoming byte

int i;

incomingbyte = message[i];     

// if else with the incoming byte! :D :D

/*if( incomingbyte == 'a')
{
 //do this
}
else{ 
  do this
}
}*/



if( incomingbyte == 'a'){
  
  Serial.println("MOTION DETECTED!");

}

else if( incomingbyte == 'b'){
  
  Serial.println("                       Normal");

}

else if( incomingbyte == 'c'){
  
   Serial.println("                       Average");

}

else if( incomingbyte == 'd'){
  
  Serial.println("                       MEDIUM");

}

else if( incomingbyte == 'e'){
  
  Serial.println("                       DANGER");

}

else if( incomingbyte == 'f'){
  
  Serial.println("                       EXTREME!! :O");

}

else if( incomingbyte == 'g'){
  
  Serial.println("                                                           NEAR");

}

else if( incomingbyte == 'h'){
  
  Serial.println("                                                           FAR");

}

else if( incomingbyte == 'i'){
  
  Serial.println("                                                           TOO FAR");

}

else if( incomingbyte == 'j'){
  
  Serial.println("                                         DARK");

}

else if( incomingbyte == 'k'){
  
   Serial.println("                                         AVERAGE");

}

else if( incomingbyte == 'l'){
  
   Serial.println("                                         VERY BRIGHT");

}

else if( incomingbyte == 'm'){
  
  Serial.println("                                                                          LIGHT");

}

else if( incomingbyte == 'n'){
  
  Serial.println("                                                                          MEDIUM");

}

else if( incomingbyte == 'o'){
  
  Serial.println("                                                                          HEAVY");

}

  }//end of NON BLOCKING

}//end of void loop
