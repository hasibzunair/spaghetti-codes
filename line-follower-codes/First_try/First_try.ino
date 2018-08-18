 const int sPin[6] = {A0,A1,A2,A3,A4,A5};

unsigned int val[6];

#define LeftM_1 9
#define LeftM_2 10
#define RightM_1 6
#define RightM_2 11

//#define Max 180
#define Av 140
#define Low 60
#define Zero 0

#define Thresh 350
#define Thresh_1 400
void setup() {
  // put your setup code here, to run once:

     pinMode(LeftM_1, OUTPUT);
     pinMode(LeftM_2, OUTPUT);
     pinMode(RightM_1, OUTPUT);
     pinMode(RightM_2, OUTPUT);

     for ( int i = 0; i<6 ; i++ ) {
       pinMode(sPin[i],INPUT);
     }
     val[0],val[1],val[2],val[3],val[4],val[5] = 0;

       Serial.begin(9600);
}

void loop() {
    
    Read();

    Serial.print(val[0]);
    Serial.print(" ");
    Serial.print(val[1]);
    Serial.print(" ");
    Serial.print(val[2]);
    Serial.print(" ");
    Serial.print(val[3]);
    Serial.print(" ");
    Serial.print(val[4]);
    Serial.print(" ");
    Serial.print(val[5]);
    Serial.println(" ");
    delay(40);

    if(val[0]<Thresh && val[1]<Thresh  && val[2]>Thresh  && val[3]>Thresh  && val[4]<Thresh  && val[5]<Thresh ){
      Forward();
    }
    if(val[0]>Thresh  && val[1]>Thresh  && val[2]<Thresh  && val[3]<Thresh  && val[4]<Thresh && val[5]<Thresh){
      Left_1();
    }
    if(val[0]<Thresh  && val[1]>Thresh  && val[2]>Thresh  && val[3]>Thresh  && val[4]<Thresh && val[5]<Thresh){
      Left_1();
    }
    if(val[0]>Thresh && val[1]>Thresh && val[2]>Thresh && val[3]<Thresh && val[4]<Thresh && val[5]<Thresh){
      Left_1();
    }  
    if(val[0]<Thresh && val[1]>Thresh && val[2]>Thresh && val[3]<Thresh && val[4]<Thresh && val[5]<Thresh){
      Left_3();
    } 
    if(val[0]>Thresh && val[1]>Thresh && val[2]>Thresh && val[3]>Thresh && val[4]<Thresh && val[5]<Thresh){
      Left_1(); 
    }
    if(val[0]<Thresh && val[1]<Thresh && val[2]<Thresh && val[3]>Thresh && val[4]>Thresh && val[5]>Thresh){
      Right_1();
    }
    if(val[0]<Thresh && val[1]<Thresh && val[2]>Thresh && val[3]>Thresh && val[4]>Thresh && val[5]>Thresh){
      Right_1();
    }
    if(val[0]<Thresh && val[1]<Thresh && val[2]<Thresh && val[3]<Thresh && val[4]>Thresh && val[5]>Thresh){
      Right_1();
    }
    if(val[0]<Thresh && val[1]<Thresh && val[2]<Thresh && val[3]>Thresh && val[4]>Thresh && val[5]<Thresh){
      Right_3();
    }
    if(val[0]<Thresh && val[1]<Thresh && val[2]>Thresh & val[3]>Thresh && val[4]>Thresh && val[5]>Thresh){
      Right_1();
    }
    if(val[0]>Thresh && (val[1]<Thresh || val[2]<Thresh || val[3]<Thresh) &&val[5]<Thresh){
      do{
        Left_2();
        Read();
       }
      while(!(val[0]<Thresh && val[1]<Thresh && val[2]>Thresh && val[3]>Thresh && val[4]<Thresh && val[5]<Thresh));
    }
     if(val[0]<Thresh && (val[4]<Thresh || val[2]<Thresh || val[3]<Thresh) && val[5]>Thresh){
      do{
        Right_2();
        Read();
      }
      while(!(val[0]<Thresh && val[1]<Thresh && val[2]>Thresh && val[3]>Thresh && val[4]<Thresh && val[5]<Thresh));
    }
     /*if(val[0]==1 && (val[1]==0 || val[2]==0 || val[3]==0) &&val[5]==1){
      if(val[0]==0 && val[1]==0 && val[2]==1 & val[3]==1 && val[4]==0 && val[5]==0){
      Forward();
      }
    if(val[0]==0 && val[1]==1 && val[2]==1 & val[3]==0 && val[4]==0 && val[5]==0){
      Left_1();
    }  
    if(val[0]==0 && val[1]==0 && val[2]==0 & val[3]==1 && val[4]==1 && val[5]==0){
      Right_1();
    }
     }*/
    if(val[0]>Thresh && val[1]>Thresh && val[2]>Thresh && val[3]>Thresh && val[4]>Thresh && val[5]>Thresh){
       Forward();
   }
     
}
    
  void Forward(){

      analogWrite(LeftM_1, Av+10);
      analogWrite(RightM_1, Av+10);
      analogWrite(LeftM_2, Zero);
      analogWrite(RightM_2, Zero);
     }

  /*void Reverse(){

      digitalWrite(LeftM_1, Zero);
      digitalWrite(LeftM_2,);
      delay(1000);
      
      digitalWrite(RightM_1,LOW);
      digitalWrite(RightM_2,HIGH);
      delay(1000);
     }*/

       
     void Right(){

      analogWrite(LeftM_1, Av-10);
      analogWrite(RightM_1,50);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }

      
     void Right_1(){

      analogWrite(LeftM_1, Av);
      analogWrite(RightM_1,Low);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }
     void Right_2(){

      analogWrite(LeftM_1, Av);
      analogWrite(RightM_1,Zero);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Low);
     }
     void Right_3(){

      analogWrite(LeftM_1, Av+10);
      analogWrite(RightM_1,Low);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }

     void Left(){

      analogWrite(LeftM_1,50 );
      analogWrite(RightM_1,Av-10);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }

      void Left_1(){

      analogWrite(LeftM_1, Low);
      analogWrite(RightM_1,Av);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }

      void Left_2(){

      analogWrite(LeftM_1, Zero);
      analogWrite(RightM_1,Av);
      analogWrite(LeftM_2,Low);
      analogWrite(RightM_2,Zero);
     }
      void Left_3(){

      analogWrite(LeftM_1, Low+10);
      analogWrite(RightM_1,Av+10);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }


     void Stop(){

      analogWrite(LeftM_1,Zero);
      analogWrite(RightM_1,Zero);
      analogWrite(LeftM_2,Zero);
      analogWrite(RightM_2,Zero);
     }

     void Read(){

    val[0] = analogRead(sPin[0]);
    val[1] = analogRead(sPin[1]);
    val[2] = analogRead(sPin[2]);
    val[3] = analogRead(sPin[3]);  
    val[4] = analogRead(sPin[4]);
    val[5] = analogRead(sPin[5]); 
}

     

