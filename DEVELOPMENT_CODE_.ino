//setting up for pixy cam 
#include <Pixy2.h>
Pixy2 pixy;

// Setting up for the motors 
//Rigth motors 1             //motor 2      //left motor 3           // motor 4 
int EN1=11;            int EN2=12;           int EN3=4;        int EN4=5;
int in1=22;            int in3=26;         int in5=30;        int in7=34;
int in2=24;            int in4=28;         int in6=32;        int in8=36;

int signature,width,height,x,y,cx,cy,area; 

//setting up for  ir sensors 
int left=42;
int right=44;

void setup() {

// setting the baud rate 
  Serial.begin(115200);  
  
  // starting the execution 
  Serial.print("starting...\n");
   pixy.init();
  pixy.changeProg("line");
  pixy.setServos(300,0);
   pixy.setLamp(1,0);

   pinMode(left,INPUT);
   pinMode(right,INPUT);

   
  //Rigth motor 1
pinMode(EN1,OUTPUT);
pinMode(in1,OUTPUT);
pinMode(in2,OUTPUT);
//motor 2
pinMode(EN2,OUTPUT);
pinMode(in3,OUTPUT);
pinMode(in4,OUTPUT);

//left motors
//MOTOR 3 
pinMode(EN3,OUTPUT);
pinMode(in5,OUTPUT);
pinMode(in6,OUTPUT); 
// motor 4 
pinMode(EN4,OUTPUT);
pinMode(in7,OUTPUT);
pinMode(in8,OUTPUT);

   
}
void moveforward(int R,int L){
   analogWrite(EN1,R);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
   analogWrite(EN2,R);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

   analogWrite(EN3,L);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
   analogWrite(EN4,L);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
 
  }
  void movebackwards(int e){
    analogWrite(EN1,e);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
   analogWrite(EN2,e);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

   analogWrite(EN3,e);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
   analogWrite(EN4,e);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
  }
  void turnrigth(int R,int L){
  analogWrite(EN1,R);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
   analogWrite(EN2,R);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);

   analogWrite(EN3,L);
  digitalWrite(in5,LOW);
  digitalWrite(in6,HIGH);
   analogWrite(EN4,L);
  digitalWrite(in7,LOW);
  digitalWrite(in8,HIGH);
}
void turnleft(int e, int s) {
  analogWrite(EN1,e);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
   analogWrite(EN2,e);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);

   analogWrite(EN3,s);
  digitalWrite(in5,HIGH);
  digitalWrite(in6,LOW);
   analogWrite(EN4,s);
  digitalWrite(in7,HIGH);
  digitalWrite(in8,LOW);
}


void stopp(){
  movebackwards(255);
  delay(100);
  moveforward(255,255);
  delay(25);
  moveforward(0,0);
  for(;;){}
}

void track() { 
  int val_RIGTH=digitalRead(left);
  int val_LEFT=digitalRead (right);
Serial.print("left=");
Serial.println (val_RIGTH);
Serial.print("rigth=");
Serial.println (val_LEFT);
delay (1000);

// condition no 1 
if ((val_RIGTH==HIGH)&&(val_LEFT==HIGH)){
  moveforward(100,100);  
   //Serial.print("moving forward ");
}

//condition 2 
 else if ((val_RIGTH==HIGH)&&(val_LEFT==LOW)){
  moveforward(0,100);
   //Serial.print("moving left");
}

//condition 3
 else if ((val_RIGTH==LOW)&&(val_LEFT==HIGH)) {
  moveforward(100,0);
   //Serial.print("moving rigth");
 }

 
 //condition 4 
 else if ((val_RIGTH==LOW )&&(val_LEFT==LOW)) {
  stopp ();
   //Serial.print("stopping");
 }

 
 //CONDITION 5
 else if ((val_RIGTH==HIGH)&&(val_LEFT==HIGH)){
  stopp();
  //Serial.print("stopping");
 }
 }

void pixycheck() {
  static int i = 0;
  int j;
  uint16_t blocks;
  char buf[32];
  blocks = pixy.ccc.getBlocks();
  if (blocks) {
    signature = pixy.ccc.blocks[0].m_signature;
    height = pixy.ccc.blocks[0].m_height;
    width = pixy.ccc.blocks[0].m_width;
    x = pixy.ccc.blocks[0].m_x; // Corrected
    y = pixy.ccc.blocks[0].m_y; // Corrected
  
    cx = (x + (width / 2));
    cy = (y + (height / 2));
    area = width * height;
    Serial.print("signature=");
    Serial.println(signature);
    Serial.print("width=");
    Serial.println(width);
  
    Serial.print("y=");
    Serial.println(y);
    Serial.print("cx=");
    Serial.println(cx); // Corrected
    Serial.print("cy=");
    Serial.println(cy);
    Serial.print("area=");
    Serial.println(area);
  }
}



void pixy_allign() {
  pixy.line.getMainFeatures();

  if (pixy.line.vectors) {
    if (pixy.line.vectors->m_x1 < 35 && pixy.line.vectors->m_x0 < 35) {
      moveforward(0, 255);
    }
    else if (pixy.line.vectors->m_x1 > 35 && pixy.line.vectors->m_x0 > 35) {
      moveforward(255, 0);
    }
    else {
      moveforward(255, 255);
    }
  }
}


void loop() {
  // put your main code here, to run repeatedly:
//moveforward(255,255);
pixy_allign() ;
//              track();
}
