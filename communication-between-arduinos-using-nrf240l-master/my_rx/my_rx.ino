/*
 Copyright (C) 2012 James Coliz, Jr. <maniacbug@ymail.com>

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/**
 * Simplest possible example of using RF24Network,
 *
 * RECEIVER NODE
 * Listens for messages from the transmitter and prints them out.
 */

#include <RF24Network.h>
#include <RF24.h>
#include <SPI.h>

// nRF24L01(+) radio attached using Getting Started board 
RF24 radio(9,10);

// Network uses that radio
RF24Network network(radio);

// Address of our node
const uint16_t this_node = 0; // COM8

// Address of the other node
const uint16_t other_node = 1; //COM4

// Structure of our payload
struct payload_t
{
  
  unsigned long ldr_val;
   unsigned long dist_val;
};


int led= 5;
int led1 = 2;

void setup(void)
{
  Serial.begin(57600);
  Serial.println("RF24Network/examples/helloworld_rx/");

   pinMode(led,OUTPUT);
   pinMode(led1,OUTPUT);

 
  SPI.begin();
  radio.begin();
  network.begin(/*channel*/ 90, /*node address*/ this_node);
}

void loop(void)
{
  // Pump the network regularly
  network.update();

  // Is there anything ready for us?
  while ( network.available() )
  {
    // If so, grab it and print it out
    RF24NetworkHeader header;
    payload_t payload;
    network.read(header,&payload,sizeof(payload));
    Serial.print("Sensor 1 : ");
    Serial.print(payload.ldr_val);
    Serial.print("      ");
    Serial.print("Sensor 2 : ");
    Serial.println(payload.dist_val);


    
     if(payload.ldr_val < 50 ){ 
      digitalWrite(led,1);
      Serial.println("ALERT!! ALERT!! :@ ");
      
      }
     else {digitalWrite(led,0);}
//===================================
     if(payload.dist_val < 10 ){ 
      digitalWrite(led1,1);
      Serial.println("BACK UP!! BACK UP!! :O");
      
      }
     else {digitalWrite(led1,0);}

     //all conditions for the datas must be written here!!!!!!!!!!!!
  }

  
   
  
}
// vim:ai:cin:sts=2 sw=2 ft=cpp
