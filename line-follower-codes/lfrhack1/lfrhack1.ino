const int sPin[4] = {A3,A2,A1,A0}; //IR sensor pins

unsigned int val[4]; // IR sensor readings stored here
                     //val 0 1 2 3

//motor pins
// pin at PWM for analogWrite
const int leftmotor1 = 5; // forward pin left
const int leftmotor2 = 6;
const int rightmotor1 = 10; // forward pin right
const int rightmotor2 = 11;

// different motor speeds
int velHigh = 180;
int velLow = 100;
int velFor = 150;
int velzero   = 0;

// runs good at 180 80 140 0


//threshold for ir sensors
#define MAX 800
#define MIN 100


void setup() {

 //define motor pins
 pinMode(leftmotor1,OUTPUT);
 pinMode(leftmotor2,OUTPUT);
 pinMode(rightmotor1,OUTPUT);
 pinMode(rightmotor2,OUTPUT);
 
 //define IR sensor pins
  Serial.begin(9600);
   for ( int i = 0; i<4 ; i++ ) {
    pinMode(sPin[i],INPUT);
   }

   delay(2000);

 
}

void loop() {
  
 // greater than MAX 700 --------BLACK LINE
 // less than  MIN 200   --------WHITE LINE
    val[0] = analogRead(sPin[0]);
    val[1] = analogRead(sPin[1]);
    val[2] = analogRead(sPin[2]);
    val[3] = analogRead(sPin[3]); 

   if(val[1] < MIN || val[2]<MIN ){ //WHITE LINE!

    movFor();
   }

   else{

    if(val[0]<MIN){

      movLef();
    }
      else{
        if(val[3]<MIN){
          movRig();
          
        }
      }
    
   }


    

   
   
}

//function to move ,left, right ,forward, backward and stop!

void movFor(){

 analogWrite(leftmotor1,velFor);
 analogWrite(leftmotor2,velzero);
 analogWrite(rightmotor1,velFor);
 analogWrite(rightmotor2,velzero);
}

void movBac(){
 analogWrite(leftmotor1,velzero);
 analogWrite(leftmotor2,velHigh);
 analogWrite(rightmotor1,velzero);
 analogWrite(rightmotor2,velHigh);  
}

void movRig(){
 analogWrite(leftmotor1,velHigh);
 analogWrite(leftmotor2,velzero);
 analogWrite(rightmotor1,velLow);
 analogWrite(rightmotor2,velzero);
}

void movLef(){
 analogWrite(leftmotor1,velLow);
 analogWrite(leftmotor2,velzero);
 analogWrite(rightmotor1,velHigh);
 analogWrite(rightmotor2,velzero);
}

void movStop(){
 analogWrite(leftmotor1,velzero);
 analogWrite(leftmotor2,velzero);
 analogWrite(rightmotor1,velzero);
 analogWrite(rightmotor2,velzero);
}
