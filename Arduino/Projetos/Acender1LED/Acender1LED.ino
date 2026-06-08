void setup() {
  // put your setup code here, to run once:
    pinMode(12, OUTPUT);//levo o pin 12 para a saida
}
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(12, HIGH);//acendo o pin 12
  delay(1000);//fica 1s acesso
  digitalWrite(12, LOW);//apago o pin 12
  delay(1000);//fica is apagado
}
