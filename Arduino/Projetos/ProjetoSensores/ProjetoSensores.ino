#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_BMP280.h>
#include <Servo.h>

// definicao dos pinos dos leds
#define LED_AMARELO   7 
#define LED_VERMELHO  9
#define LED_VERDE     13

// pinos dos sensores
#define PINO_MAGNETICO 11   // sensor de ima ky-021
#define PINO_TOQUE     4    // digital do sensor de toque
#define PINO_TOQUE_ANALOG A1 // analogico do sensor de toque

#define PINO_TEMP      A0   // sensor ds18b20 de temperatura
#define PINO_SERVO     26   // servo motor no mega

// sensor bmp280 
#define BMP_SDA  A5   
#define BMP_SCL  A4   
#define BMP_SND  -1   // -1 desativa o que nao vai usar no circuito
#define BMP_CS   -1


// setup dos objetos das bibliotecas
OneWire oneWire(PINO_TEMP);
DallasTemperature sensores(&oneWire);

// forca o bmp a ler nos pinos analogicos
Adafruit_BMP280 bmp(BMP_CS, BMP_SDA, BMP_SND, BMP_SCL); 

Servo meuServo;

// variaveis de controle do tempo e estados
unsigned long tempoAbertura = 0;
bool portaAberta = false;
bool alarmeDisparado = false;
const long tempoLimite = 5000; // 5 segundos de tolerancia
unsigned long ultimoEnvioSerial = 0;

// variaveis para controlar o servo sem travar o codigo com delay
unsigned long tempoServoAberto = 0;
bool servoAberto = false;

void setup() {
  Serial.begin(9600);
  Serial.println("--- Sistema Iniciado ---");

  // configura pinos dos leds
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);

  // pullup pros sensores pra garantir sinal estavel
  pinMode(PINO_MAGNETICO, INPUT_PULLUP);
  pinMode(PINO_TOQUE, INPUT_PULLUP);

  // inicia o servo trancado
  meuServo.attach(PINO_SERVO);
  meuServo.write(0); 

  // liga o ds18b20
  sensores.begin();
  
  // tenta iniciar o bmp no endereco 0x76, se nao der tenta no 0x77
  if (!bmp.begin(0x76)) {
    if (!bmp.begin(0x77)) {
      Serial.println("Erro no BMP280!");
      while (1); // trava aqui se der ruim no sensor
    }
  }

  // estado inicial dos leds (verde ligado)
  digitalWrite(LED_VERDE, HIGH);
  digitalWrite(LED_AMARELO, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

void loop() {
  // --- parte 1: leitura dos sensores de clima ---
  sensores.requestTemperatures();
  float temperatura = sensores.getTempCByIndex(0);
  float pressao = bmp.readPressure() / 100.0F; // converte pra hPa

  // acende o amarelo se o clima passar dos limites
  if (temperatura > 28.0 || temperatura < 15.0 || pressao > 1020.0) {
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, LOW);
  } else {
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }

  // printa no monitor a cada 1 segundo pra nao inundar o serial
  if (millis() - ultimoEnvioSerial > 1000) {
    Serial.print("Temp: ");
    Serial.print(temperatura, 1);
    Serial.print(" C | Pressao: ");
    Serial.print(pressao, 1);
    Serial.print(" hPa");

    // FIX: mudado para digitalRead para checar o estado corretamente
    if (digitalRead(LED_AMARELO) == HIGH) { 
      Serial.println(" -> [ALERTA CLIMA]");
    } else {
      Serial.println(" -> [Clima OK]");
    }
    ultimoEnvioSerial = millis();
  }

  // --- parte 2: seguranca e controle da porta ---
  int estadoPorta = digitalRead(PINO_MAGNETICO); 
  int estadoToque = digitalRead(PINO_TOQUE);
  int leituraToqueAnalog = analogRead(PINO_TOQUE_ANALOG);

  // se afastar o ima (porta aberta), comeca a contar o tempo
  if (estadoPorta == HIGH && !portaAberta && !alarmeDisparado && !servoAberto) {
    portaAberta = true;
    tempoAbertura = millis();
    Serial.println("Porta aberta, esperando toque...");
  }

  if (portaAberta) {
    unsigned long tempoDecorrido = millis() - tempoAbertura;

    // checa se tocou no sensor (digital ou analogico)
    if (estadoToque == LOW || leituraToqueAnalog > 500) {
      portaAberta = false;
      servoAberto = true;
      tempoServoAberto = millis(); // guarda quando abriu pra fechar depois

      Serial.println("Acesso liberado!");
      meuServo.write(90); // destranca
    } 
    // se estourar o tempo de 5 segundos sem tocar, ativa alarme
    else if (tempoDecorrido > tempoLimite) {
      portaAberta = false;
      alarmeDisparado = true;
    }
  }

  // fecha o servo sozinho depois de 4 segundos sem usar delay()
  if (servoAberto && (millis() - tempoServoAberto > 4000)) {
    meuServo.write(0);
    servoAberto = false;
    Serial.println("Trancando porta...");
  }

  // se o alarme tiver ativo, pisca o aviso e liga o led vermelho
  if (alarmeDisparado) {
    digitalWrite(LED_VERMELHO, HIGH);
    meuServo.write(0); // garante que ta trancado
    
    if (millis() % 1000 < 50) {
      Serial.println("!!! INTRUSO DETECTADO !!!");
    }

    // fecha a porta (encosta o ima) pra dar o reset no alarme
    if (estadoPorta == LOW) {
      alarmeDisparado = false;
      digitalWrite(LED_VERMELHO, LOW);
      Serial.println("Sistema resetado.");
    }
  }

  delay(50); // estabiliza o loop
}

