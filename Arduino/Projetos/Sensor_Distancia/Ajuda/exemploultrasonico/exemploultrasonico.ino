int trig = 12;
int echo = 13;
int led1 = 2;
int led2 = 4;

float distancia;	


void setup()	
{
  pinMode (trig, OUTPUT);
  pinMode (echo,INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
  //Serial.begin (9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delay(0005);
  digitalWrite(trig, HIGH);
  delay(0010);
  digitalWrite(trig, LOW);
  
  distancia = pulseIn (echo, HIGH);
  distancia = distancia/58;
  Serial.println (distancia);

  if(distancia > 50) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else{
     digitalWrite(led1, LOW);
       digitalWrite(led2, HIGH);
       delay(1000);
     
  }
}
