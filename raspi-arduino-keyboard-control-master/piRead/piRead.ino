int p1 = 22;
int p2 = 24;
int p3 = 26;
int p4 = 28;
int p5 = 30;
int p6 = 32;
int p7 = 34;
int p8 = 36;
int p9 = 38;
int p10 = 40;
int p11= 42;
int p12 = 44;
int p13 = 46;
int p14 = 48; //input pins


int s1 = 0;
int s2 = 0;
int s3 = 0;
int s4 = 0;
int s5 = 0;
int s6 = 0;
int s7 = 0;
int s8 = 0;
int s9 = 0;
int s10 = 0;
int s11 = 0;
int s12 = 0;
int s13 = 0;
int s14 = 0;// state of input pins


void setup() {
  Serial.begin(9600);
   pinMode(p1, INPUT);
   pinMode(p2, INPUT);
   pinMode(p3, INPUT);
   pinMode(p4, INPUT);
   pinMode(p5, INPUT);
   pinMode(p6, INPUT);
   pinMode(p7, INPUT);
   pinMode(p8, INPUT);
   pinMode(p9, INPUT);
   pinMode(p10, INPUT);
   pinMode(p11, INPUT);
   pinMode(p12, INPUT);
   pinMode(p13, INPUT);
   pinMode(p14, INPUT);



   
}

void loop() {
  
       s1 = digitalRead(p1);
       s2 = digitalRead(p2);
       s3 = digitalRead(p3);
       s4 = digitalRead(p4);
       s5 = digitalRead(p5);
       s6 = digitalRead(p6);
       s7 = digitalRead(p7);
       s8 = digitalRead(p8);
       s9 = digitalRead(p9);
       s10 = digitalRead(p10);
       s11 = digitalRead(p11);
       s12 = digitalRead(p12);
       s13 = digitalRead(p13);
       s14 = digitalRead(p14);//value of input pins

    Serial.print(s1);
    Serial.print(" ");
    Serial.print(s2);
    Serial.print(" ");
    Serial.print(s3);
    Serial.print(" ");
    Serial.print(s4);
    Serial.print(" ");
    Serial.print(s5);
    Serial.print(" ");
    Serial.print(s6);
    Serial.print(" ");
    Serial.print(s7);
    Serial.print(" ");
    Serial.print(s8);
    Serial.print(" ");
    Serial.print(s9);
    Serial.print(" ");
    Serial.print(s10);
    Serial.print(" ");
    Serial.print(s11);
    Serial.print(" ");
    Serial.print(s12);
    Serial.print(" ");
    Serial.print(s13);
    Serial.print(" ");
    Serial.print(s14);
    Serial.println("");
    
   delay(100);

}
