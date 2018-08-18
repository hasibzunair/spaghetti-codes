#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>// libs


LiquidCrystal lcd(8, 7, 6, 4, 3, 2);

#define RST_PIN         5          // Configurable, see typical pin layout above
#define SS_PIN          53         // Configurable, see typical pin layout above
// 9 10 
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance

int val1 = 0;
int val2 = 0;

void setup() {

  val1, val2 = 0;
  lcd.begin(16, 2);
  lcd.print(" ATTENDANCE SYS");
  lcd.setCursor(0, 1);
  lcd.print("   RFID 499A");
  delay(3000);
  
  lcd.clear();

  Serial.begin(9600);    // Initialize serial communications with the PC
  while (!Serial);    // Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init();   // Init MFRC522
  mfrc522.PCD_DumpVersionToSerial();  // Show details of PCD - MFRC522 Card Reader details
  Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {

   

    if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  // Dump debug info about the card; PICC_HaltA() is automatically called
 // mfrc522.PICC_DumpToSerial(&(mfrc522.uid));

 if (mfrc522.uid.uidByte[0] == 0x64 && //circle tag
     mfrc522.uid.uidByte[1] == 0xE5 &&
     mfrc522.uid.uidByte[2] == 0x49 &&
     mfrc522.uid.uidByte[3] == 0x39) {


      val1++;
      
     lcd.setCursor(0,0);
     lcd.print("Jubayer= ");
     lcd.print(         val1);
    
     Serial.println("It's me Jubayer Kabir");
     delay(5000);
     }

  if (mfrc522.uid.uidByte[0] == 0xBB && //card tag
     mfrc522.uid.uidByte[1] == 0xFA &&
     mfrc522.uid.uidByte[2] == 0xEB &&
     mfrc522.uid.uidByte[3] == 0x93) {


      val2++;
      
     lcd.setCursor(0,1);
     lcd.print("Saadi= ");
     lcd.print(        val2);
    
     Serial.println("It's me Shamsul Islam Saadi");
     delay(5000);
     }

  
}
