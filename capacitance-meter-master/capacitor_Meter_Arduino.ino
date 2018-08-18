#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 7, 6, 5, 4);
float R1 = 1e6;                    
float C1 = 0;                       
volatile int led_pin = 12;        
volatile long t_inicio = 0;       
volatile long t_final = 0;        
long T = 0;                         
int pin = 8;

void setup()
{    pinMode(pin,OUTPUT);
     lcd.begin(16, 2);
     Serial.begin(9600);                 
     attachInterrupt(0, start, RISING);  
     attachInterrupt(1, stop, FALLING);                                  
     pinMode(led_pin, OUTPUT);        

  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  delay(300);
  digitalWrite(pin,HIGH);
  delay(200);
  digitalWrite(pin,LOW);
  delay(150);
  digitalWrite(pin,HIGH);
  delay(70);
  digitalWrite(pin,LOW);
    
}

void loop()
{
   
    if (t_final > 0)
    {
        T = t_final - t_inicio;         
        C1 = T * 1000 / (1.1 * R1);     

       // for debugging
       /* Serial.print("t = ");
        Serial.print(T);
        Serial.println(" microSeg");
        Serial.print("C = ");
        Serial.print(C1 );
        Serial.println(" microF");
        Serial.print("C = ");
        Serial.print(C1 * 1000);        
        Serial.println(" nanoF");
        Serial.println();
        */
      lcd.setCursor(0, 0);
      lcd.print(T);  
      lcd.print(" microSec");
      lcd.setCursor(0,1);
      lcd.print(C1);
      lcd.print(" microFarad");
         
        t_inicio = 0;                   
        t_final = 0;                   
    }


}
void start()
{
    t_inicio = millis();              
}
void stop()
{
    t_final = millis();                            
}

