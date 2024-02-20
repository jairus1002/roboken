
int intersections=0;
int i;
int ledpin =13;
int IR_R=50;
int IR_C=46;
int IR_L=52;
void setup() {
  // put your setup code here, to run once:
// setting the baud rate 
  Serial.begin(115200);  
  
  // starting the execution 
  Serial.print("starting...\n");
pinMode(IR_R,INPUT);
pinMode(IR_C,INPUT);
pinMode(IR_L,INPUT);

}

void counter(){
int val1=digitalRead(IR_R);
int val2=digitalRead(IR_C);
int val3=digitalRead(IR_L);


 
  if(val1 ==LOW && val2==LOW && val3==LOW){
    intersections++;
    Serial.println("val high");
    analogWrite(ledpin,100);
     delay(100);
    Serial.println(intersections);  
     analogWrite(ledpin,0);
Serial.print(val1);Serial.print(" ");Serial.print(val2);Serial.print(" ");Serial.println(val3);
     //Serial.println(intersections);
}  
  }

void loop() {
  // put your main code here, to run repeatedly:
counter();
}
