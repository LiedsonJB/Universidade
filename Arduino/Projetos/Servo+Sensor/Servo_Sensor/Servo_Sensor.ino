#include <Servo.h>
#include <DistanceSensor.h>

#define ECHO1 10
#define TRIG1 11

#define ECHO2 12
#define TRIG2 13

int pinMotor = 5;
float distancia1, distancia2;

Servo Motor;
DistanceSensor sensor1(TRIG1, ECHO1);
DistanceSensor sensor2(TRIG2, ECHO2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Motor.attach(pinMotor);
  pinMode(ECHO1, INPUT);
  pinMode(TRIG1, OUTPUT);
  pinMode(ECHO2, INPUT);
  pinMode(TRIG2, OUTPUT);

  Motor.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
  distancia1 = sensor1.getCM();
  distancia2 = sensor2.getCM();

  Serial.print("distancia1: ");
  Serial.println(distancia1);
  Serial.print("distancia2: ");
  Serial.println(distancia2);

  delay(1000);

  if (distancia1 < 20) {
    Motor.write(0);
    Motor.write(90);
  }
  if (distancia2 < 20) {
    Motor.write(0);
    Motor.write(90);
  }
}
