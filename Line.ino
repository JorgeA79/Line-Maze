int A,B,C,D;
void setup() {
 pinMode(12,OUTPUT);
 pinMode(13,OUTPUT);
 pinMode(2,INPUT);
 pinMode(3,INPUT);
 pinMode(4,INPUT);
 pinMode(5,INPUT);  // put your setup code here, to run once:

}

void loop() {
A=digitalRead(2);
B=digitalRead(3);
C=digitalRead(4);
D=digitalRead(5);// put your main code here, to run repeatedly:

 if(A==0 && B==0 && C==0 && D==0)
 {digitalWrite(12,1);
 digitalWrite(13,1);
 }
 if(A==1 && B==1 && C==1 && D==1)
 {digitalWrite(12,1);
 digitalWrite(13,1);
 }
  if(A==0 && B==1 && C==1 && D==1)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
 if(A==1 && B==0 && C==1 && D==1)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
  if(A==0 && B==0 && C==1 && D==1)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
  if(A==0 && B==0 && C==0 && D==1)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
  if(A==0 && B==0 && C==1 && D==0)
 {digitalWrite(12,0);
 digitalWrite(13,1);
 }
  if(A==1 && B==1 && C==0 && D==1)
 {digitalWrite(12,1);
 digitalWrite(13,0);
 }
  if(A==1 && B==1 && C==1 && D==0)
 {digitalWrite(12,1);
 digitalWrite(13,0);
 }
  if(A==1 && B==1 && C==0 && D==0)
 {digitalWrite(12,1);
 digitalWrite(13,0);
 }
  if(A==1 && B==0 && C==0 && D==0)
 {digitalWrite(12,1);
 digitalWrite(13,0);
 }
  if(A==0 && B==1 && C==0 && D==0)
 {digitalWrite(12,1);
 digitalWrite(13,1);
 } }
