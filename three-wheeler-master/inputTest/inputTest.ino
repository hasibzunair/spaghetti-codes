 
int SENSOR_PIN = A0; 
int RPWM_Output = 5;
int LPWM_Output = 6;

const int buttonPin = 2; 
int buttonState = 0; 
const int buttonPinnn = 4;
int buttonStateee = 0;

void setup()
{
  pinMode(RPWM_Output, OUTPUT);
  pinMode(LPWM_Output, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPinnn,INPUT);
  pinMode(SENSOR_PIN,INPUT);
  Serial.begin(9600);
  
}
 
void loop()
{
  
  int buttonState = digitalRead(buttonPin);
  int buttonStateee = digitalRead(buttonPinnn);
  int sensorValue = analogRead(SENSOR_PIN);



  Serial.print(buttonState);
  Serial.print("     ");
  Serial.print(buttonStateee);
  Serial.print("     ");
  Serial.print(sensorValue);
  Serial.println("");
  delay(100);

  
}
