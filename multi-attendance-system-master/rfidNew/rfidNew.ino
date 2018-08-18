#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>// libs


LiquidCrystal lcd(8, 7, 6, 4, 3, 2);

#define RST_PIN         5          // Configurable, see typical pin layout above
#define SS_PIN          53         // Configurable, see typical pin layout above
// 9 10 
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

int c = 39;// 17
int f = 33;// 22
int i = 35;// 6
int l = 37;// 19

int buzzPin = 9;
void setup() {

  pinMode(c,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(i,OUTPUT);
  pinMode(l,OUTPUT);

  
  lcd.begin(16, 2);
  lcd.print(" ATTENDANCE SYS");
  lcd.setCursor(0, 1);
  lcd.print("   RFID 499A");
  delay(3000);
  pinMode(buzzPin, OUTPUT);
  lcd.clear();
  lcd.print("Reading RFID Tags...");

  Serial.begin(9600);    // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {

   
   /* digitalWrite(c,LOW);
    digitalWrite(f,LOW);
    digitalWrite(i,LOW);
    digitalWrite(l,LOW);
    */
    if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
 // mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

  
 if (mfrc522.uid.uidByte[0] == 0x76 && //circle tag
     mfrc522.uid.uidByte[1] == 0xC0 &&
     mfrc522.uid.uidByte[2] == 0x37 &&
     mfrc522.uid.uidByte[3] == 0xBB) {
     Serial.println("It's me Jubayer");

     lcd.clear();
     lcd.print("Reading RFID Tags...");
     lcd.setCursor(0,1);
     lcd.print("Jubayer");
    
     digitalWrite(buzzPin,HIGH);
     delay(700);
     digitalWrite(buzzPin,LOW);
    
    
    digitalWrite(i,HIGH);
    digitalWrite(c,LOW);
    digitalWrite(f,LOW);
    digitalWrite(l,LOW);
    
      delay(500);
     }

  if (mfrc522.uid.uidByte[0] == 0xE5 && //card tag
     mfrc522.uid.uidByte[1] == 0xC4 &&
     mfrc522.uid.uidByte[2] == 0x37 &&
     mfrc522.uid.uidByte[3] == 0xBB) {
     Serial.println("It's me Saadi");

     
     lcd.clear();
     lcd.print("Reading RFID Tags...");
     lcd.setCursor(0,1);
     lcd.print("Saadi");

     
     digitalWrite(buzzPin,HIGH);
     delay(700);
     digitalWrite(buzzPin,LOW);

     digitalWrite(f,HIGH);
     digitalWrite(c,LOW);
    digitalWrite(i,LOW);
    digitalWrite(l,LOW);
      delay(500);
      
     }
  if (mfrc522.uid.uidByte[0] == 0xBB && //card tag
     mfrc522.uid.uidByte[1] == 0xFA &&
     mfrc522.uid.uidByte[2] == 0xEB &&
     mfrc522.uid.uidByte[3] == 0x93) {
     Serial.println("It's me Hasib");

     
     lcd.clear();
     lcd.print("Reading RFID Tags...");
     lcd.setCursor(0,1);
     lcd.print("Hasib");
     
    
     digitalWrite(buzzPin,HIGH);
     delay(700);
     digitalWrite(buzzPin,LOW);

     digitalWrite(l,HIGH);
     digitalWrite(c,LOW);
    digitalWrite(f,LOW);
    digitalWrite(i,LOW);
      delay(500);
      
     }

   if (mfrc522.uid.uidByte[0] == 0xA5 && //card tag
     mfrc522.uid.uidByte[1] == 0x07 &&
     mfrc522.uid.uidByte[2] == 0x37 &&
     mfrc522.uid.uidByte[3] == 0xBB) {
     Serial.println("It's me KMM Sir");
     
     lcd.clear();
     lcd.print("Reading RFID Tags...");
     lcd.setCursor(0,1);
     lcd.print("KMM Sir");
     
     
     digitalWrite(buzzPin,HIGH);
     delay(700);
     digitalWrite(buzzPin,LOW);

     digitalWrite(c,HIGH);
     digitalWrite(i,LOW);
    digitalWrite(f,LOW);
    digitalWrite(l,LOW);
      delay(500);
      
     }

}
