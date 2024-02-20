

// setting up forLINE TRACKING the IRS 
int left=4;
int rigth=5;

int val_LEFT=0;
int val_RIGTH=0;

// setting up for the INTERSECTIONS  ir sensors 
const int LEFT=9;
const int MIDR=10;
const int RIGHT=11;

int val_R=0;
int val_C=0;
int val_L=0;


// setting up for the counter LED
int ledpin =12;


// initializaton of the intersections 
int intersections=0;

// setting up fotr the motors 
//Rigth motors 1             //motor 2      //left motor 3           // motor 4 
int EN1=7;            int EN2=6;           int EN3=9;        int EN4=8;
int in1=23;           int in3=26;         int in5=30;        int in7=34;
int in2=24;           int in4=28;         int in6=32;        int in8=36;


void setup() {
  
// begining the baud rate 
Serial.begin (9600);


// Setting up for the LED
  pinMode(ledpin,OUTPUT);


// setting up for the Ir sensors
pinMode(LEFT,INPUT);
pinMode(MIDR,INPUT);
pinMode(RIGHT,INPUT);


// setting the out puts for the motors 
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

// setting up for the counter 
void counter(){
int val_R=analogRead(IR1);
int val_C=analogRead(IR2);
int val_L=analogRead(IR3);


 
  if(val_R ==LOW && val_C==LOW && val_L==LOW){
    intersections++;
    Serial.println("val high");
    analogWrite(ledpin,100);
     delay(100);
    Serial.println(intersections);  
     analogWrite(ledpin,0);
Serial.print(val1);Serial.print(" ");Serial.print(val2);Serial.print(" ");Serial.println(val3);
     //Serial.println(intersections);
}


// setting up for the  tracking 
void track() { 
  val_RIGTH=digitalRead(left);
  val_LEFT=digitalRead (rigth);
Serial.print("left=");
Serial.print (val_RIGTH);
Serial.print("rigth=");
Serial.print (val_LEFT);
delay (100);

// condition no 1 
if ((val_RIGTH==HIGH)&&(val_LEFT==HIGH)){
  moveforward(255,255);  
   Serial.print("moving forward ");
}

//condition 2 
 else if ((val_RIGTH==HIGH)&&(val_LEFT==LOW){
  moveleft(255,255);
   Serial.print("moving left");
}

//condition 3
 else if ((val_RIGTH==LOW)&&(val_LEFT==HIGH) {
  moverigth(255,255);
   Serial.print("moving rigth");
 }

 
 //condition 4 
 else if ((val_RIGTH==LOW )&&(val_LEFT==LOW)) {
  stopp ();
   Serial.print("stopping");
 }
 else if ((val_RIGTH==HIGH)&&(val_LEFT==HIGH)){
  stopp();
  Serial.print("stopping");
 }
 }

// Setting up the functions for the motors 
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
  digitalWrite(in8,HIGH);7
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

// the breakdown loop.
void stopp(){
  movebackwards(255);
  delay(100);
  moveforward(255,255);
  delay(25);
  moveforward(0,0);
  for(;;){}
}



void loop() {
  // put your main code here, to run repeatedly:

}
