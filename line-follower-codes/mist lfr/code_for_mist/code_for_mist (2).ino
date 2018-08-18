
const int analogInPin1 = A1;
const int analogInPin2 = A2;
const int analogInPin3 = A3;
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

const int pwm1=9;
const int pwm2=10;
int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue = 0;        // value read from the pot

int outputValue = 0;        // value output to the PWM (analog out)
#define mot_A_IN_1      2
#define mot_A_IN_2      3
#define mot_B_IN_1      4
#define mot_B_IN_2      5
#define moveforward();    digitalWrite(mot_A_IN_1, HIGH); digitalWrite(mot_A_IN_2, LOW); digitalWrite(mot_B_IN_1, HIGH); digitalWrite(mot_B_IN_2, LOW)
#define movebackward();   digitalWrite(mot_A_IN_1, LOW); digitalWrite(mot_A_IN_2, HIGH); digitalWrite(mot_B_IN_1, LOW); digitalWrite(mot_B_IN_2, HIGH)
#define rotateleft();     digitalWrite(mot_A_IN_1, LOW); digitalWrite(mot_A_IN_2, HIGH); digitalWrite(mot_B_IN_1, HIGH); digitalWrite(mot_B_IN_2, LOW)
#define rotateright();    digitalWrite(mot_A_IN_1, HIGH); digitalWrite(mot_A_IN_2, LOW); digitalWrite(mot_B_IN_1, LOW); digitalWrite(mot_B_IN_2, HIGH)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
 moveforward();
}
void readSensor()
{
  sensorValue = analogRead(analogInPin);    
  sensorValue1 = analogRead(analogInPin1);
  sensorValue2 = analogRead(analogInPin2);
  sensorValue3 = analogRead(analogInPin3);
  
  Serial.print("\n sensor = " );                       
  Serial.print(sensorValue);  
  Serial.print("\t sensor1 = " );                       
  Serial.print(sensorValue1);
  Serial.print("\t sensor2 = " );                       
  Serial.print(sensorValue2);
  Serial.print("\t sensor3 = " );                       
  Serial.print(sensorValue3);  
}
