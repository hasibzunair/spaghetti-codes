

int x = 5;


const int a = 4;  
const int b = 5;


const int c =6;
const int d = 7;


const int e = 2;
const int f = 3;

const int g = 8;
const int h = 9;

//2,4  7, 8    10, 11    12,13

#define t1 2
#define e1 4

#define t2 7
#define e2 8

#define t3 10
#define e3 11

#define t4 12
#define e4 13



void setup(){
  
  Serial.begin(9600);
  pinMode(a, OUTPUT);   
  pinMode(b, OUTPUT);   
  pinMode(c, OUTPUT);   
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);

  pinMode(t1,OUTPUT);
  pinMode(e1,INPUT);

  pinMode(t2,OUTPUT);
  pinMode(e2,INPUT);

  pinMode(t3,OUTPUT);
  pinMode(e3,INPUT);

  pinMode(t4,OUTPUT);
  pinMode(e4,INPUT);
  

  
}



void loop(){

  int d1,d2,d3,d4,dis1,dis2,dis3,dis4;
  
  digitalWrite(t1, HIGH); //send sound wave
  delay(x);
  digitalWrite(t1, LOW); 
  
  d1 = pulseIn(e1,HIGH); // calc total time travel for the pulse 
  
  dis1 = (d1/2 )/29.1;

  
  digitalWrite(t2, HIGH); //send sound wave
  delay(x);
  digitalWrite(t2, LOW); 
  
  d2 = pulseIn(e2,HIGH); // calc total time travel for the pulse 
  
  dis2 = (d2/2 )/29.1; //convert to cm

   
  digitalWrite(t3, HIGH); //send sound wave
  delay(x);
  digitalWrite(t3, LOW); 
  
  d3 = pulseIn(e3,HIGH); // calc total time travel for the pulse 
  
  dis3 = (d3/2 )/29.1; //convert to cm


   
  digitalWrite(t4, HIGH); //send sound wave
  delay(x);
  digitalWrite(t4, LOW); 
  
  d4 = pulseIn(e4,HIGH); // calc total time travel for the pulse 
  
  dis4 = (d4/2 )/29.1; //convert to cm

  
  int p, q, r, s;

  p = map(dis1,8,30,255,0);
  if(p>255) p =255;
  else if( p <0) p =0;
  q = map(dis2,8,30,255,0);
    if(q>255) q =255;
  else if( q <0) q =0;
  r = map(dis3,8,30,255,0);
    if(r>255) r =255;
  else if( r <0) r =0;
  s = map(dis4,8,30,255,0);
    if(s>255) s =255;
  else if( s <0) s =0;

  analogWrite(b,p);
  analogWrite(c,q);
  analogWrite(f,r);
  analogWrite(h,s);

  Serial.print(p);
  Serial.print("   ");
  Serial.print(q);
  Serial.print("   ");
  Serial.print(r);
  Serial.print("   ");
  Serial.print(s);
  Serial.println("");

  delay(20);


}

