
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
int velHigh = 160;
int velLow = 140;
int velzero   = 0;

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

 //set to zero to prevent errors!
 val[0],val[1],val[2],val[3] = 0;

}

void loop() {
//-------------------
/*int x = 3000;  // testing motor pins
  movFor();
  delay(x);
  movBac();
  delay(x);
  movLef();
  delay(x);
  movRig();
  delay(x);
  movStop();
  delay(x);
*/
//---------------------test motors

//----------------------------------
 /* for( int j = 0; j < 4 ; j++){    //reading the IR values

   val[j] = analogRead(sPin[j]);
   Serial.print("\t Sensor ");
   Serial.print(j);
   Serial.print("-");
   Serial.print(val[j]);
   Serial.print("\t");
   
   }
  Serial.println("");
  delay(2);
 */
//-----------------------------------print ir values

   Read();

 /*   Serial.print(val[0]);
    Serial.print("\t");
    Serial.print(val[1]);
    Serial.print("\t");
    Serial.print(val[2]);
    Serial.print("\t");
    Serial.print(val[3]);
    Serial.println("");
    delay(4);
  */
  
 // greater than 700 --------BLACK LINE
 // less than  200   --------WHITE LINE


    if(val[1] > MAX && val[2] > MAX && val[0] < MIN && val[3] < MIN ){
     
      movFor();
     }
     
     if( val[0] > MAX ){ 
      movLef();
     }
      
    if( val[3] > MAX){
      movRig();
     }
     
     if( val[0] > MAX &&  val[1] > MAX && val[2] > MAX && val[3] > MAX){
        movStop();
     } 
           
       

}

//function to move ,left, right ,forward, backward and stop!

void movFor(){

 analogWrite(leftmotor1,velHigh);
 analogWrite(leftmotor2,velzero);
 analogWrite(rightmotor1,velHigh);
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

void Read(){

    val[0] = analogRead(sPin[0]);
    val[1] = analogRead(sPin[1]);
    val[2] = analogRead(sPin[2]);
    val[3] = analogRead(sPin[3]);   
}

