#include <LiquidCrystal.h>

#define trigPin 8
#define echoPin 9
int sensePin = 1;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int inPin = 0;

int value;
float millivolts,celsius;

void setup()
  {
    
    analogReference(DEFAULT); // not needed
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin,INPUT);
    lcd.begin(16, 2);
  }
void loop()
  {
   //  lcd.setCursor(0, 1);
   //calc distacne
  int duration,distance;
  
  digitalWrite(trigPin, HIGH); //send ultrasoncie wave
  delay(500);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin,HIGH);
  distance = (duration/2 )/29.1; //convert to cm
   
    //calc temperature
    int value = analogRead(inPin);
    
     millivolts = (value / 1024.0) * 5000;
     celsius = millivolts / 10;
     
   //calc LUX(brightness in room)
 
    int val = analogRead(sensePin);
   //  val = constrain(val ,20 , 200);
  
  float dark = 500/ val;
       
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(celsius);
    lcd.print(" Degrees");
  
   // lcd.setCursor(0,1);
   //lcd.print((celsius * 9)/ 5 + 32);    //for fahrenhiet
   // lcd.print(" Fahrenheit");
   
    lcd.setCursor(0,1);
    lcd.print(distance);
    lcd.print("cm");
    lcd.setCursor(6,1);
    
  lcd.print(dark);
  lcd.print("Dark");
  delay(500);
    
    
  }
