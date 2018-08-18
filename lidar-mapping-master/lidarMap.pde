import processing.serial.*;

float pcolor = 0;
float xVal = 0;
float yVal = 0;

 Serial myPort;
 
 void setup(){
  
  size(200,100);
 
 print(Serial.list());
 
 myPort = new Serial(this,Serial.list()[0],9600);
 myPort.bufferUntil('\n');
 background(0);
}

void draw() { 
  
 stroke(pcolor);
 point(xVal,yVal);
}

void serialEvent(Serial myPort) {
  
  String inString = myPort.readStringUntil('\n');
  
  if(inString != null) {
    
    inString = trim(inString);
    
    float[] colors = float(split(inString, ","));
    if (colors.length >=3) {
      
      xVal = colors[0];
      yVal = colors[1];
      pcolor = map(colors[2],0,400,0,255);
    }
    
  }
}
