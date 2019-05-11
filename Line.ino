int I,C,R;    //  Sensores         //
int DB = 8;   //  Derecha Atras    //
int DF = 7;   //  Derecha Frente   //
int IB = 6;   //  Izquierda Atras  //
int IF = 5;   //  Izquierda Frente //


int L = 1;    //        Line       //
int M = 0;    //        Maze       //

//  Vars UltraSonic //

const int UTI = 0;  //  Trigger Izquierdo // 
const int UTF = 0;  //  Trigger Frente    //
const int UTD = 0;  //  Trigger Derecho   //
const int UEI = 0;  //  Echo Izquierdo    //
const int UEF = 0;  //  Echo Frente       //
const int UED = 0;  //  Echo Derecho      //
float distance1;    //  Distancia Iz      //
float distance2;    //  Distancia Frente  //
float distance3;    //  Distancia Der     //

//  Ultrasonicos  // 
  float sonar(int trigger, int echo)  {
  float sonarDistance;
  unsigned long pulseTime;
  const float soundSpeed = .03432;                      
  
  digitalWrite(trigger, LOW);
  delayMicroseconds(4);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW); 

  pulseTime = pulseIn(echo, HIGH);
  sonarDistance = (pulseTime*soundSpeed)/2;

  return sonarDistance;         
}
   
void setup() {
  
 // Llantas //
 pinMode(DB,OUTPUT); // Llanta Derecha Atras    //
 pinMode(DF,OUTPUT); // Llanta Derecha Frente   //
 pinMode(IB,OUTPUT); // Llanta Izquierda Atras  //
 pinMode(IF,OUTPUT); // Llanta Izquierda Frente //
  
 //   IRs   //
 pinMode(2,INPUT); // Sensor Izquierdo  //
 pinMode(3,INPUT); // Sensor Medio      //
 pinMode(4,INPUT); // Sensor Derecho    //

 //  UltraSonicos  //
 Serial.begin (9600);
 pinMode(UTI, OUTPUT);  //  Trigger Izquierdo //
 pinMode(UTF, OUTPUT);  //  Trigger Frente    //
 pinMode(UTD, OUTPUT);  //  Trigger Derecho   //
 pinMode(UEI, INPUT);   //  Echo Izquierdo    //
 pinMode(UEF, INPUT);   //  Echo Frente       //
 pinMode(UED, INPUT);   //  Echo Derecho      //
}

void loop() {
//  Vars IRs  //
L=digitalRead(3);
M=digitalRead(4);
R=digitalRead(2);

//  UltraSonics //
distance1 = sonar(UTI, UEI);  //  UltraSonico Izquierdo // 
distance2 = sonar(UTF, UEF);  //  UltraSonico Frente    // 
distance2 = sonar(UTD, UED);  //  UltraSonico Derecho   // 


//  Line  //
if(L==1 && M==0)
{
 //ULTRASONIC FRENTE//
 if(distance2 <= 3){
  digitalWrite(DB,LOW);
  digitalWrite(DF,LOW);
  digitalWrite(IB,LOW);
  digitalWrite(IF,LOW);
 }
 
 if(I==LOW && M==LOW && R==LOW) //  No No No //
 {
  digitalWrite(DB,LOW);
  digitalWrite(DF,LOW);
  digitalWrite(IB,LOW);
  digitalWrite(IF,LOW);
 }
   
 if(I==HIGH && C==HIGH && R==HIGH)  //  Si Si Si  //
 {
  digitalWrite(DB,LOW);
  digitalWrite(DF,HIGH);
  digitalWrite(IB,LOW);
  digitalWrite(IF,HIGH);
 }
    
  if(I==HIGH && C==HIGH && R==LOW) // Si Si No  //
 {
  digitalWrite(DB,HIGH);
  digitalWrite(DF,LOW);
  digitalWrite(IB,LOW);
  digitalWrite(IF,HIGH);
 }

 if(I==HIGH && C==LOW && R==HIGH) //  Si No Si  //
 {
  digitalWrite(DB,LOW);
  digitalWrite(DF,HIGH);
  digitalWrite(IB,LOW);
  digitalWrite(IF, HIGH);
 }
  
  if(I==LOW && C==HIGH && R==HIGH) // No Si Si  //
 {
  digitalWrite(DB,LOW);
  digitalWrite(DF,HIGH);
  digitalWrite(IB,HIGH);
  digitalWrite(IF,LOW);
 }
   
  if(I==LOW && C==LOW && R==HIGH)  // No No Si //
 {
  digitalWrite(DB,LOW);
  digitalWrite(DF,HIGH);
  digitalWrite(IB,HIGH);
  digitalWrite(IF,LOW);
 }}
 // Maze  //
 
 if(M==1 && L==0)
 {
  if(distance1 <= 3 && distance2 <= 3 && distance3 <= 3) //No No No
  {
    digitalWrite(DB,LOW);
    digitalWrite(DF,HIGH);
    digitalWrite(IB,LOW);
    digitalWrite(IF,HIGH);
    analogWrite(enB, 128);
  }
  if(distance1 >= 3 && distance2 >= 3 && distance3 >= 3) //Si Si Si
  {
    digitalWrite(DB,HIGH);
    digitalWrite(DF,LOW);
    digitalWrite(IB,LOW);
    digitalWrite(IF,HIGH);
    analogWrite(enB, 255);
  }
   if(distance1 >= 3 && distance2 >= 3 && distance3 <= 3) //Si Si No
  {
    digitalWrite(DB,HIGH);
    digitalWrite(DF,LOW);
    digitalWrite(IB,LOW);
    digitalWrite(IF,HIGH);
    analogWrite(enB, 255);
  }
     if(distance1 >= 3 && distance2 <= 3 && distance3 >= 3) //Si No Si
  {
    digitalWrite(DB,LOW);
    digitalWrite(DF,HIGH);
    digitalWrite(IB,LOW);
    digitalWrite(IF,HIGH);
    analogWrite(enB, 255);
  }
     if(distance1 <= 3 && distance2 >= 3 && distance3 >= 3) //No Si Si
  {
    digitalWrite(DB,LOW);
    digitalWrite(DF,HIGH);
    digitalWrite(IB,HIGH);
    digitalWrite(IF,LOW);
    analogWrite(enB, 255);
  }
     if(distance1 <= 3 && distance2 <= 3 && distance3 >= 3) //No No Si
  {
    digitalWrite(DB,LOW);
    digitalWrite(DF,HIGH);
    digitalWrite(IB,LOW);
    digitalWrite(IF,HIGH);
    analogWrite(enB, 255);
  }
  if(distance1 >= 3 && distance2 <= 3 && distance3 <= 3) //Si No No
  {
    digitalWrite(DB,LOW);
    digitalWrite(DF,HIGH);
    digitalWrite(IB,LOW);
    digitalWrite(IF,HIGH);
    analogWrite(enB, 128);
  }
 }
 
}
