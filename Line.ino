int A,B,C;
void setup() {
 pinMode(12,OUTPUT);
 //WheelRB
 pinMode(13,OUTPUT);
 //WheelLB
 pinMode(14,OUTPUT);
 //WheelRF
 pinMode(15,OUTPUT);
 //WheelLF
 
 pinMode(2,INPUT);
 //SensorCenter
 pinMode(3,INPUT);
 //SensorRight
 pinMode(4,INPUT);
 //SensorLeft        

}

void loop() {
A=digitalRead(2);
B=digitalRead(3);
C=digitalRead(4);


 
  //No No No
 if(A==0 && B==0 && C==0)
 {digitalWrite(12,0);
 digitalWrite(13,0);
 digitalWrite(14,0);
 digitalWrite(15,0);
 }
  //Si Si Si
 if(A==1 && B==1 && C==1)
 {digitalWrite(12,1);
 digitalWrite(13,1);
 digitalWrite(14,1);
 digitalWrite(15,1);
 }
  //Si Si No
  if(A==1 && B==1 && C==0)
 {digitalWrite(12,0);
 digitalWrite(13,1);
  digitalWrite(14,1);
 digitalWrite(15,1);
 }
 //Si No Si
 if(A==1 && B==0 && C==1)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
 //No Si Si
  if(A==0 && B==1 && C==1)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
 //Si No No
  if(A==1 && B==0 && C==0)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
  //No Si No
  if(A==0 && B==1 && C==0)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
 //No No Si
  if(A==0 && B==0 && C==1)
 {digitalWrite(12,1);
 digitalWrite(13,0); 
 } }
