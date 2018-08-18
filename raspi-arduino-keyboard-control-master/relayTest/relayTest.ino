

//RC car with bluetooth communication

const int in1 = 2;  // left motor pins
const int in2 = 3;
const int in3 =4;
const int in4 = 5;

const int in5 = 6;
const int in6 = 7;
const int in7 = 8;
const int in8 = 9;


void setup(){
  
  Serial.begin(9600);
  pinMode(in1, OUTPUT);   
  pinMode(in2, OUTPUT);   
  pinMode(in3, OUTPUT);   
  pinMode(in4, OUTPUT);

  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  
}



void loop(){

 moveBackward();
 delay(2000);
 moveForward();
 delay(2000);
 moveLeft();
 delay(2000);
 moveRight();
 delay(2000); 
  
}


//functions for different modes


void moveBackward(){
  
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);

  
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
}

void moveLeft(){
  
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);//
  digitalWrite(in3, HIGH);
  digitalWrite(in4,LOW); 

  digitalWrite(in6, HIGH);
  digitalWrite(in5, LOW);//
  digitalWrite(in7, HIGH);
  digitalWrite(in8,LOW); 

  
}

void moveRight(){
  
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  digitalWrite(in3, LOW); 
  digitalWrite(in4, HIGH);

   digitalWrite(in6, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in7, LOW); 
  digitalWrite(in8, HIGH);
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
}

