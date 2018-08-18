
#include<SPI.h>
#include<RF24.h>

RF24 radio(9,10);
int depth = 0;
int randNumber;
void setup(void) {

 Serial.begin(9600);
 radio.begin();
 radio.setPALevel(RF24_PA_MAX);
 radio.setChannel(0x76);
 radio.openWritingPipe(0xF0F0F0F0E1LL);
 radio.enableDynamicPayloads();
 radio.powerUp();



  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
   pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);

  
 
}

void loop(void) {

 
float  x = analogRead(A0);
float   y = analogRead(A1);
float    z = analogRead(A2);


if (x  < 150){
  depth = 0;
  digitalWrite (2, HIGH);
  digitalWrite (3, LOW);
  digitalWrite (4, LOW);
   
  }

if (y  < 150){
  depth = 5;
  digitalWrite (2, HIGH);
  digitalWrite (3, HIGH);
  digitalWrite (4, LOW);  
  }

if (z  < 150){

  depth = 10;
  digitalWrite (2, HIGH);
  digitalWrite (3, HIGH);
  digitalWrite (4, HIGH);
  
}
Serial.println(depth);
 //const char text[] = "Hello World" ;
 //const int text = 55;
 
  //randNumber = random(0,10);
  //Serial.println(randNumber);

 
 radio.write(&depth, sizeof(depth));
 //delay(1000);

}
