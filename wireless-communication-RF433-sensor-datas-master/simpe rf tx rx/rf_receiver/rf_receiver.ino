#include <VirtualWire.h>
byte message[VW_MAX_MESSAGE_LEN]; // a buffer to hold the incoming messages
byte msgLength = VW_MAX_MESSAGE_LEN; // the size of the message

char incomingbyte;


void setup()
{
Serial.begin(9600);
Serial.println("Ready");
// Initialize the IO and ISR
vw_setup(2000); // Bits per sec
vw_rx_start(); // Start the receiver
}

void loop()
{
  
  
if (vw_get_message(message, &msgLength)) // Non-blocking

{
//Serial.print("Got: ");


//for (int i = 0; i < msgLength; i++)
//{
//Serial.write(message[i]);
//}
//Serial.println();


//read the byte and store it in incoming byte
int i;
incomingbyte = message[i];     //Serial.read();
//


// if else with the incoming byte! :D :D

//--------------------------------------------
/*
if( incomingbyte == 'a')
{

Serial.print("I got ");
Serial.print(incomingbyte);
Serial.println();
}

else{ 
  
  Serial.print("NOO");
  Serial.println();
}
*/
///--------------------------------------------------

Serial.println(incomingbyte);
Serial.println();



}}
