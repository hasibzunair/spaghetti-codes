#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

unsigned long msg1[3];
unsigned long msg2[3];
RF24 radio(9, 10);
const uint64_t pipes[3] = {0xE8E8F0F0E1LL, 0xE8E8F0F0E2LL, 0xE8E8F0F0E3LL};
int LED1 = 3;

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.startListening();
  pinMode(LED1, OUTPUT);
}


void loop(void) {

  radio.openReadingPipe(1, pipes[0]);
  while (radio.available()) {
    radio.read(msg1, sizeof(msg1));
    Serial.print(msg1[0] / 1000000.0, 6);
    Serial.print("\t");
    Serial.print(msg1[1] / 1000000.0, 6);
    Serial.print("\t");
    Serial.println(msg1[2]);
  }
  //radio.stopListening();
  delay(50);


  radio.openReadingPipe(1, pipes[1]);
  while (radio.available()) {
    radio.read(msg2, sizeof(msg2));
    Serial.print(msg2[0] / 1000000.0, 6);
    Serial.print("\t");
    Serial.print(msg2[1] / 1000000.0, 6);
    Serial.print("\t");
    Serial.println(msg2[2]);
  }

}
