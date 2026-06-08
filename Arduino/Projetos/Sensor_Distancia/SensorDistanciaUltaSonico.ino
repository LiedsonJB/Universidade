#include <HCSR04.h>

#define ECHO 12
#define TRIG 13

int v[5] = {1, 2, 3 , 4, 5};
float distanciaCM;

void muitoPerto() {

  for (int i = 0; i < 5; i++)
    digitalWrite(v[i], HIGH);

  delay(80);

  for (int i = 0; i < 5; i++)
    digitalWrite(v[i], LOW);

  delay(80);  
}

void perto() {

  for (int i = 0; i < 5; i++)
    digitalWrite(v[i], HIGH);

  delay(500);

  for (int i = 0; i < 5; i++)
    digitalWrite(v[i], LOW);
    
  delay(500);
}

void razoavel(){
  
  for (int i = 0; i < 5; i++)
    digitalWrite(v[i], HIGH);

  delay(1000);

  for (int i = 0; i < 5; i++)
    digitalWrite(v[i], LOW);
    
  delay(1000);
  
 }

 void bom(){
  
     for (int i = 0; i < 5; i++)
        digitalWrite(v[i], LOW);
 
 }

void setup(){
    
  pinMode(ECHO, INPUT);//levo o pin do echo para o input do sensor
  pinMode(TRIG, OUTPUT);//levo o pin do trig para a saida

  for (int i = 0; i < 5; i++)
     pinMode(v[i], OUTPUT);

}

void loop(){

      distanciaCM = pulseIn(ECHO, HIGH)/58;//ativo o echo que recebe informacao do sensor e utilizo o pulseIn que serve para calcular a distancia em cm pulseIn(echo, HIGH/LOW);

      if(distanciaCM <= 10)
          muitoPerto();
      else if(distanciaCM > 10 && distanciaCM <= 30)
          perto();
      else if(distanciaCM > 30 && distanciaCM <= 100)
          razoavel();
      else
          bom(); 
  
}
