
int a,b,c= 0; // modes of taking data

void setup() {
  
Serial.begin(9600);

pinMode(2,INPUT);
pinMode(11,INPUT);
pinMode(12,INPUT);

}

void loop() {


int c = digitalRead(2); //R
int b = digitalRead(11);// F
int a = digitalRead(12); //L

//Serial.println("SELECT MODE OF ENTRY");
//delay(500);

/*
Serial.print(a);
Serial.print(b);
Serial.print(c);

Serial.println("");
delay(1000);
*/


   while( a == 0)
   {
    Serial.println("READ MODE");
    delay(100);
    if(digitalRead(11) == 0)
    break;
    
   }
   while( c == 0)
   {
    Serial.println("MATCH MODE");
    delay(100);
     if(digitalRead(11) == 0)
    break;
    
   }
   





}
