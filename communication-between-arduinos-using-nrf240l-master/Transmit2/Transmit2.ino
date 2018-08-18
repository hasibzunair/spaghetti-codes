#include  <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
//unsigned long msg[2];
RF24 radio(49, 53);
const uint64_t pipe = 0xE8E8F0F0E2LL;
int SW1 = 7;

void setup(void) {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);
  pinMode(A5, INPUT);
}

void loop(void) {

    unsigned long msg2[3] = {92904936,92230957, 1};
    radio.write(msg2, sizeof(msg2));
    

}
