#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
//unsigned long msg[2];
RF24 radio(9, 10);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(A5, INPUT);
}

void loop(void) {

    unsigned long msg1[3] = {92940605,92984729, 220};
    radio.write(msg1, sizeof(msg1));
    

}
