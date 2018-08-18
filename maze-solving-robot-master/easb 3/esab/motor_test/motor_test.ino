const int motorRight1 = 10;
const int motorRight2 = 9;


const int motorLeft1 = 5;
const int motorLeft2 = 6;








void setup()
{
  
  Serial.begin(9600);
  pinMode(motorRight1, OUTPUT);   
  pinMode(motorRight2, OUTPUT);   
  pinMode(motorLeft1, OUTPUT);   
  pinMode(motorLeft2, OUTPUT);  
}



void loop(){
 
 
  moveForward();
  delay(1500);
  moveLeftUturn();
  delay(1500);
  
  
}


//functions for different modes


void moveForward(){
  
  analogWrite(motorRight1, 255);
  analogWrite(motorRight2, 0);
  analogWrite(motorLeft1, 255);
  analogWrite(motorLeft2, 0);
}

void moveBackward(){
  
  analogWrite(motorRight1, 0);
  analogWrite(motorRight2, 255);
  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, 255);
}

void moveLeft(){
  
  analogWrite(motorRight2, 0);
  analogWrite(motorRight1, 0);//
  analogWrite(motorLeft1, 255);
  analogWrite(motorLeft2,0); 
}

void moveRight(){
  
  analogWrite(motorRight2, 0);
  analogWrite(motorRight1, 255);
  analogWrite(motorLeft1, 0);//
  analogWrite(motorLeft2, 0);
}

void moveStop(){
  
  analogWrite(motorRight1, 0);
  analogWrite(motorRight2, 0);
  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, 0);
}

void moveRightUturn(){
  
  analogWrite(motorRight1, 255);
  analogWrite(motorRight2, 0);
  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, 255);
}

void moveLeftUturn(){
  
  analogWrite(motorRight1, 0);
  analogWrite(motorRight2, 255);
  analogWrite(motorLeft1, 255);
  analogWrite(motorLeft2, 0);
}
