#include <LiquidCrystal.h>

#include "FPS_GT511C3.h"
#include "SoftwareSerial.h"

FPS_GT511C3 fps(9, 10); // 4 5
LiquidCrystal lcd(8, 7, 6, 5, 4, 3);
int a,b,c= 0; // modes of taking data

int buzzPin = A0;
void setup() {
  
Serial.begin(9600);

pinMode(2,INPUT);
pinMode(11,INPUT);
pinMode(12,INPUT);
pinMode(A0,OUTPUT);


  lcd.begin(16, 2);
  lcd.print(" ATTENDANCE SYS");
  lcd.setCursor(0, 1);
  lcd.print("FINGERPRINT 499");
  delay(3000);
  
  lcd.clear();


fps.Open();
fps.SetLED(true);

fps.UseSerialDebug = true; // so you can see the messages in the serial debug screen
  

}

void loop() {


int c = digitalRead(2); //R
int b = digitalRead(11);// F
int a = digitalRead(12); //L


// FPS Blink LED Test
  fps.SetLED(true); // turn on the LED inside the fps
  delay(1000);
  fps.SetLED(false);// turn off the LED inside the fps
  delay(1000);


//Serial.println("SELECT MODE OF ENTRY");
//delay(500);

/*
Serial.print(a);
Serial.print(b);
Serial.print(c);

Serial.println("");
delay(1000);
*/
  lcd.clear();
  
  lcd.print("FINGERPRINT MODE");
  lcd.setCursor(0, 1);
  lcd.print("Enroll or Match...");

   while( a == 0) // left button
   {
      lcd.clear();
      lcd.print("Enroll....");
      Enroll();
    //if(digitalRead(11) == 0)  //forward button
    break;
    
   }
   while( c == 0) //right button
   {
      
      /*lcd.print("Match....");
      delay(2000);
      lcd.clear();
      */
    ReadFinger();
     if(digitalRead(11) == 0)
    break;
    
   }
   
}

void Enroll()
{
  
  int enrollid = 0;
  bool usedid = true;
  while (usedid == true)
  {
    usedid = fps.CheckEnrolled(enrollid);
    if (usedid==true) enrollid++;
  }
  fps.EnrollStart(enrollid);

  // enroll
  Serial.print("Press finger to Enroll #");
  Serial.println(enrollid);
  lcd.clear();
  lcd.print("Press to enroll #");
  lcd.setCursor(0,1);
  lcd.print(enrollid);
  
  fps.SetLED(true);
  
  
  while(fps.IsPressFinger() == false) delay(100);
  bool bret = fps.CaptureFinger(true);
  int iret = 0;
  if (bret != false)
  {
    
    lcd.clear();
    Serial.println("Remove finger");
    lcd.print("Remove finger");
    fps.Enroll1(); 
    while(fps.IsPressFinger() == true) delay(100);
    Serial.println("Press same finger again");
    lcd.clear();
    lcd.print("Press again..");
    
    while(fps.IsPressFinger() == false) delay(100);
    bret = fps.CaptureFinger(true);
    if (bret != false)
    {
      lcd.clear();
      Serial.println("Remove finger");
      lcd.print("Remove finger..");
      fps.Enroll2();
      while(fps.IsPressFinger() == true) delay(100);
      Serial.println("Press same finger yet again");
      lcd.clear();
      lcd.print("Press again...");
      while(fps.IsPressFinger() == false) delay(100);
      bret = fps.CaptureFinger(true);
      if (bret != false)
      {
        Serial.println("Remove finger");
        lcd.clear();
        lcd.print("Remove finger...");
//////////////////////
        lcd.clear();
        lcd.print("Enroll ok");
       
        iret = fps.Enroll3();
        
        if (iret == 0)
        {
          Serial.println("Enrolling Successfull");
          lcd.clear();
          lcd.print("Enroll ok");
        }
        else
        {
          Serial.print("Enrolling Failed with error code:");
          Serial.println(iret);
          lcd.clear();
          lcd.print("Error");
        }
      }
      else Serial.println("Failed to capture third finger");
    }
    else Serial.println("Failed to capture second finger");
  }
  else Serial.println("Failed to capture first finger");
}


void ReadFinger(){

   fps.SetLED(true);
    // Identify fingerprint test
  if (fps.IsPressFinger())
  {
    fps.CaptureFinger(false);
    int id = fps.Identify1_N();
    if (id <200)
    {
      Serial.print("Verified ID:");
      Serial.println(id);

      lcd.clear();
      lcd.print("VERIFIED ID : ");
      lcd.setCursor(0,1);
      lcd.print(id);

     
      analogWrite(buzzPin,255);
      delay(100);
      analogWrite(buzzPin,0);
      
      
    /* if(id == 0)
     {
      Serial.println("HASIB");
     }*/

     
    }
    else
    {
      Serial.println("Finger not found");
      lcd.clear();
      lcd.print("Finger not found");
    }
  }
  else
  {
    Serial.println("Please press finger");
    lcd.clear();
      lcd.print("Press finger");
      analogWrite(buzzPin,0);
  }
  delay(100);
}

