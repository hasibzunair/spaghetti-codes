const int sPin[4] = {A3,A2,A1,A0}; // sensor pins

unsigned int val[4]; // sensor readings stored here
//val 0 1 2 3


void setup() {

   Serial.begin(9600);
   for ( int i = 0; i<4 ; i++ ) {
    pinMode(sPin[i],INPUT);
    
   }

}

void loop() {

   for( int j = 0; j < 4 ; j++){

   val[j] = analogRead(sPin[j]);
   Serial.print("\t Sensor ");
   Serial.print(j);
   Serial.print("-");
   Serial.print(val[j]);
   Serial.print("\t");
    
    }

  Serial.println("");
  delay(2);
}
