#define trigPin 3
#define echoPin 2

void setup()
{
  
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);  // sends the wave 
 pinMode(echoPin,INPUT);   // 

}

void loop(){
  
  
  int duration,distance;  // variables declared 
  
  digitalWrite(trigPin, HIGH); //send sound wave
  delay(400);
  digitalWrite(trigPin, LOW); 
  
  duration = pulseIn(echoPin,HIGH); // calc total time travel for the pulse 
  
  distance = (duration/2 )/29.1; //convert to cm

  
  Serial.print(distance);
  Serial.println("cm");
  delay(50);
  
}
  
  
  
  
  
  
  
  
  
