#include <Servo.h>

Servo meuMotor;//crio meu objeto/var para o meu motor do tipo servo
int pinMotor = 2;//pin para acessar o motor
int ledD = 8, ledE = 11;//pin dos leds

void setup() {
  // put your setup code here, to run once:
  meuMotor.attach(pinMotor);//apanho/acesso o meuMotor atravez do pinMotor
  pinMode(ledD, OUTPUT);//levo o meu ledD para saida
  pinMode(ledE, OUTPUT);//levo o meu ledE para saida
}

void loop() {
  // put your main code here, to run repeatedly:
  meuMotor.write(90);//comeco meu motor com um angulo de 90º

  for(int i = 90; i > 20; i/=2){
    meuMotor.write(i);//desloca com forme o valor do i
    digitalWrite(ledD, HIGH);//acendo o ledD
    delay(1000);//aguarda 1s
    digitalWrite(ledD, LOW);//apaga o ledD
    delay(1000);//aguarda 1s
  }
  
  delay(1500);//aguarda 1.5s

  for(int i = 90; i < 160; i++){
    meuMotor.write(i);//desloca conforme o i
    digitalWrite(ledE, HIGH);//acendo o ledE
    delay(1000);//aguarda 1s
    digitalWrite(ledE, LOW);//apago o ledE
    delay(1000);//aguarda 1s
  }

   delay(1500);//aguarda 1.5s

}
