
int trig = 13;
int echo = 12;
int v[7] = { 11, 10, 9, 8, 7, 4, 2 };

float distancia;


void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(v[i], OUTPUT);
  }

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  Serial.begin(9600);
}

void loop() {

  digitalWrite(trig, LOW);
  delay(0005);
  digitalWrite(trig, HIGH);
  delay(0010);
  digitalWrite(trig, LOW);

  distancia = pulseIn(echo, HIGH);
  distancia = distancia / 58;


  if (distancia <= 10) {

    for (int i = 0; i < 7; i++) {

      digitalWrite(v[i], HIGH);
    }
    delay(20);

    for (int i = 0; i < 7; i++) {

      digitalWrite(v[i], LOW);
    }
    delay(50);
  }

  else if (distancia <= 20) {

    for (int i = 0; i < 5; i++) {

      digitalWrite(v[i], HIGH);
    }
    delay(50);

    for (int i = 5; i < 7; i++) {

      digitalWrite(v[i], LOW);
    }
    delay(50);
  }


  else if (distancia <= 30) {

    for (int i = 0; i < 4; i++) {

      digitalWrite(v[i], HIGH);
    }
    delay(100);

    for (int i = 4; i < 7; i++) {

      digitalWrite(v[i], LOW);
    }
    delay(100);

  }

  else if (distancia <= 40) {

    for (int i = 0; i < 2; i++) {

      digitalWrite(v[i], HIGH);
    }
    delay(200);

    for (int i = 2; i < 7; i++) {

      digitalWrite(v[i], LOW);
    }
    delay(200);

  }
  else {
    for (int i = 0; i < 7; i++) {

      digitalWrite(v[i], LOW);
    }
    delay(100);
  }
}
