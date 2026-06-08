#include <Servo.h>
#include <DistanceSensor.h>

#define ECHO 3//defino meu pin echo
#define TRIG 8//defino meu pin trig

Servo Motor;//objeto/var Servo para o meu motor

int ledFrente = 22, ledDireita = 28, ledEsquerda = 34, ledTras = 40, pinMotor = 11, cont = 0;//minhas var

DistanceSensor sensorPrincipal(TRIG, ECHO);//crio o meu objeto/var do tipo DistanceSensor

float disFrente, disDireita, disEsquerda;//var do tipo real para receber a distancia

void setup() {
  // put your setup code here, to run once:
  Motor.attach(pinMotor);//acedo meu motor atravez do meu pinMotor
  Serial.begin(115200);//Mostrar no serial.begin o valor da distancia
  pinMode(ECHO, INPUT);//pin ECHO para saida(envia)
  pinMode(TRIG, OUTPUT);//pin TRIG para saida(recebe)
  pinMode(ledFrente, OUTPUT);//pin ledFrente para saida
  pinMode(ledTras, OUTPUT);//pin ledTras para saida
  pinMode(ledDireita, OUTPUT);//pin ledDireita para saida
  pinMode(ledEsquerda, OUTPUT);//pin ledEsquerda para saida

  digitalWrite(ledFrente, HIGH);//acender o ledFrente
}

void loop() {
  // put your main code here, to run repeatedly:
  Motor.write(90);//meu sensor comeca sempre em um angulo de 90º
  disFrente = sensorPrincipal.getCM();//calcular a minha distancia de frente

  Serial.print("Frente: ");
  Serial.println(disFrente);

  if (disFrente > 30) //ver se a distancia for maior 30 para seguir em frente
    frente();//chamo minha funcao frente
  else{
    parar();
  }
}

//seguir em frente
void frente() {
  digitalWrite(ledEsquerda, LOW);//apagar o led da esquerda
  digitalWrite(ledDireita, LOW);//apagar o led da direita
  digitalWrite(ledTras, LOW);//apagar ledTras
}

//funcao parar e procurar a distancia
void parar() {
  digitalWrite(ledTras, HIGH);//acender ledTras

  delay(250);//aguarda 2s

  Motor.write(20);//mudo o angulo para 20 para captar a distancia direita
  disDireita = sensorPrincipal.getCM();//recebe a distancia do sensor

  Serial.print("disDireita: ");
  Serial.println(disDireita);
  delay(500);
  Motor.write(160);//mudo o angul para 160 para captar a distancia da esquerda
  disEsquerda = sensorPrincipal.getCM();//recebe a distancia do sensor

  Serial.print("disEsquerda: ");
  Serial.println(disEsquerda);
  delay(500);

  if (disDireita > disFrente && disDireita > disEsquerda) { //caso o carro vai para a direita
    Motor.write(20);//mudo o angulo para 20 para a mesma direcao onde o carro vai
    for(int i=0;i<50;i++){
      digitalWrite(ledDireita, HIGH);//acendo o ledEsquerda
      delay(100);//aguarda 1s
      digitalWrite(ledDireita, LOW);//acendo o ledEsquerda
      delay(100);
    }
    //acelerarD();
  } else if (disEsquerda > disFrente && disEsquerda > disDireita) { //caso o carro vai para a esquerda
    Motor.write(160);//mudo o angul para 160 para a mesma direcao onde o carro vai
    for(int i=0;i<50;i++){
      digitalWrite(ledEsquerda, HIGH);//acender o ledDireita
      delay(100);//aguarda 1s
      digitalWrite(ledEsquerda, LOW); //apago o ledEsquerda
      delay(100);
    }
    delay(500);
    //acelerarE();
  }
}
