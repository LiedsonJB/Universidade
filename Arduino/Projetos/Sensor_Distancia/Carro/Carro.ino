#include <DistanceSensor.h>

/*verificar se o carro vai para frente ou para direita ou esquerda ou para tras
      frente led-branco = Led[0]=28
      tras led-vermelho = Led[1]=22
      esquerda led-amarelo = Led[2]=26
      direita led-amarelo = Led[3]=24

      para frente d1 > d2 && d1 > d3
      para tras d2 = d3 && d2 > d1
      para esquerda  d2 > d1 && d2 > d3
      para direita d3 > d1 && d3 > d2

      distancia[0] => Sensor de frente
      distancia[1] => Sensor da esquerda
      distancia[2] => Sensor da direita
*/

int echo1 = 3, echoD = 5, echoE = 7;
int trig1 = 8, trigD = 11, trigE = 13;

int ledB = 22, ledD = 28, ledE = 34, ledT = 42; 
float d1, d2, d3;

int i;

DistanceSensor sensorF(trig1, echo1);
DistanceSensor sensorD(trigD, echoD);
DistanceSensor sensorE(trig1, echo1);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(230400);
  pinMode(echo1, INPUT);
  pinMode(trig1, OUTPUT);
  
  pinMode(echoD, INPUT);
  pinMode(trigD, OUTPUT);

  pinMode(echoE, INPUT);
  pinMode(trigE, OUTPUT);
  
  pinMode(ledB, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledT, OUTPUT);
  
  digitalWrite(ledB, HIGH);
  //digitalWrite(ledT, HIGH);
}

void loop() {
  d1 = sensorF.getCM();
  d2 = sensorD.getCM();
  d3 = sensorE.getCM();

   Serial.println("Sensor frente");
   Serial.println(d1);
   Serial.println("Sensor direita");
   Serial.println(d2);
   Serial.println("Sensor esquerda");
   Serial.println(d3);

  if (d1 > d2 && d1 > d3) {
    digitalWrite(ledB, HIGH);//acendo o led-branco de novo
    digitalWrite(ledD, LOW);
    digitalWrite(ledE, LOW);
    digitalWrite(ledT, LOW);
  } else if (d3 == d2 && d2 == d1) {
    digitalWrite(ledT, HIGH);//acendo o ledV ate o carro parar de ir para traz
  }else if (d3 > d1 && d3 > d2) {
        digitalWrite(ledE, HIGH);//acendo o led-amarelo da esquerda 
        delay(1000);//demora 0.05s para executar proxima instrucao
        digitalWrite(ledE, LOW);//apago o led-amarelo da esquerda 
 }else if (d2 > d1 && d2 > d3) {
        digitalWrite(ledD, HIGH);//acendo o led-amarelo da direita
        delay(1000);//demora 0.05s para executar proxima instrucao
        digitalWrite(ledD, LOW);//apago o led-amarelo da direita
  }
  digitalWrite(ledB, HIGH);
  delay(1000);
}
