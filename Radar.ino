
#include <Servo.h>. 

const int trgPin = 10;
const int echPin = 11;
long tempo;
int distancia;
Servo meuServo; 
void setup() {
  pinMode(trgPin, OUTPUT);
  pinMode(echPin, INPUT); 
  Serial.begin(9600);
  Serial.setTimeout(10);
  meuServo.attach(12); 
}
void loop() {
  for(int i=0;i<=180;i++){  
  meuServo.write(i);
  delay(10);
  distancia = calculaDistancia();
  
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distancia); 
  Serial.print("."); 
  }
  for(int i=180;i>0;i--){  
  meuServo.write(i);
  delay(10);
  distancia = calculaDistancia();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distancia);
  Serial.print(".");
  }
}
int calculaDistancia(){ 
  digitalWrite(trgPin, LOW); 
  delayMicroseconds(10);
  digitalWrite(trgPin, HIGH); 
  digitalWrite(trgPin, LOW);
  tempo = pulseIn(echPin, HIGH); 
  distancia = tempo*0.034/2;
  return distancia;
}
