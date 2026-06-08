#include <Stepper.h>

// Defina o número de passos por revolução do seu motor de passo
const int passosPorRevolucao = 200;

// Pinos conectados ao driver do motor de passo
const int in1 = 22;
const int in2 = 24;
const int in3 = 26;
const int in4 = 28;

// Crie um objeto de motor de passo
Stepper motor(passosPorRevolucao, in1, in2, in3, in4);

void setup() {
  // Defina a velocidade do motor (em RPM)
  motor.setSpeed(5); // Ajuste a velocidade conforme necessário
}

void loop() {
  // Número de passos necessários para girar 80 graus (assumindo um motor de 200 passos por revolução)
  int passos = 200 * 80 / 360;

  // Gire o motor 80 graus no sentido horário
  motor.step(passos);
  
  delay(1000); // Espere 1 segundo (opcional)
}
