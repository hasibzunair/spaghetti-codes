 
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
  
   if (buttonState == LOW)
  {
    // reverse rotation
    int sensorValue = analogRead(SENSOR_PIN);

    int reversePWM = map(sensorValue,200,800,0,255);
    if(reversePWM > 255)
    reversePWM = 255;
    else if (reversePWM < 0)
    reversePWM = 0;

    
    analogWrite(LPWM_Output, LOW);
    analogWrite(RPWM_Output, reversePWM);
  }
  else if (buttonState == HIGH)
  {
    // forward rotation
   
    int sensorValue = analogRead(SENSOR_PIN);

    int forwardPWM = map(sensorValue,200,800,0,255);
    if(forwardPWM > 255)
    forwardPWM = 255;
    else if (forwardPWM < 0)
    forwardPWM = 0;

    
    analogWrite(LPWM_Output, forwardPWM);
    analogWrite(RPWM_Output, LOW);
  }
  else
  {
    //motor stop
    analogWrite(LPWM_Output, LOW);
    analogWrite(RPWM_Output, LOW);
  }

  
}
