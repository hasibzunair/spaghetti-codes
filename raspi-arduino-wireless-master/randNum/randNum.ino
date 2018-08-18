long randNumber;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
randNumber = random(0,1023);
Serial.println(randNumber);
delay(2000);

}
