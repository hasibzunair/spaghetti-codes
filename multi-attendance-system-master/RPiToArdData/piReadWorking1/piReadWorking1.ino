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
int p14 = 48; //input pins from RPI


const int in1 = 2;  
const int in2 = 3;
const int in3 =4;
const int in4 = 5;
const int in5 = 6;
const int in6 = 7;
const int in7 = 8;
const int in8 = 9;
const int in9 = 10;
const int in10 = 11;
const int in11 = 12;
const int in12 = 31;
// motor pins for wheel

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
int s14 = 0;// state of input pins from RPI



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
   pinMode(p14, INPUT);// RPI inputs

  pinMode(in1, OUTPUT);   
  pinMode(in2, OUTPUT);   
  pinMode(in3, OUTPUT);   
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  pinMode(in9, OUTPUT);
  pinMode(in10, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(in12, OUTPUT);
  
  // motor pins for wheel 

  moveStop();
   
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
    Serial.print("  ");
    Serial.print(s2);
    Serial.print("  ");
    Serial.print(s3);
    Serial.print("  ");
    Serial.print(s4);
    Serial.print("  ");
    Serial.print(s5);
    Serial.print("  ");
    Serial.print(s6);
    Serial.print("  ");
    Serial.print(s7);
    Serial.print("  ");
    Serial.print(s8);
    Serial.print("  ");
    Serial.print(s9);
    Serial.print("  ");
    Serial.print(s10);
    Serial.print("  ");
    Serial.print(s11);
    Serial.print("  ");
    Serial.print(s12);
    Serial.print("  ");
    Serial.print(s13);
    Serial.print("  ");
    Serial.print(s14);
    Serial.println(" ");
    delay(50);  // read values from RPI

  //wheel motor control using inputs
  if (s1 == HIGH){ moveForward();}
  else if (s3 == HIGH){ moveBackward();}
  else if (s2 == HIGH){ moveLeft();}
  else if (s4 == HIGH){ moveRight();}
  else if (s5 == HIGH){ moveStop();}//use key input from base motor

}

//functions for different modes of wheel motors
void moveBackward(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  digitalWrite(in9, HIGH);
  digitalWrite(in10, LOW);
  digitalWrite(in11, HIGH);
  digitalWrite(in12, LOW);
}
void moveForward(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  digitalWrite(in9, LOW);
  digitalWrite(in10, HIGH);
  digitalWrite(in11, LOW);
  digitalWrite(in12, HIGH);
}
void moveLeft(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4,LOW); 
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, HIGH);
  digitalWrite(in8,LOW); 
  digitalWrite(in9, LOW);
  digitalWrite(in10, HIGH);
  digitalWrite(in11, HIGH);
  digitalWrite(in12, LOW);
}
void moveRight(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW); 
  digitalWrite(in8, HIGH);
  digitalWrite(in9, HIGH);
  digitalWrite(in10, LOW);
  digitalWrite(in11, LOW);
  digitalWrite(in12, HIGH);
}
void moveStop(){ 
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  digitalWrite(in9, LOW);
  digitalWrite(in10, LOW);
  digitalWrite(in11, LOW);
  digitalWrite(in12, LOW);
}
