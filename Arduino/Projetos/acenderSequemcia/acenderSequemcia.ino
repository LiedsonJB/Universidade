// para variaveis
int v[7]={13, 12, 8, 7, 4, 2, 1};
   
int i, j;
void setup() {
  // put your setup code here, to run once:
    for(i=0; i<7; i++)
      pinMode(v[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    for(i=0; i<7; i++){
        digitalWrite(v[i], HIGH);
        delay(1000);
     }
      
      for(j=7; j>=0; j--){
          digitalWrite(v[j], LOW);
          delay(300);
     }
    digitalWrite(v[7/2], HIGH);
    
    for(i=0, j=6; i < 7/2 && 7/2 < j; i++, j--){
            digitalWrite(v[i], HIGH);
            digitalWrite(v[j], HIGH);
            delay(1000);  
      }
      for(i=0, j=6; i < 7/2 && 7/2 < j; i++, j--){
            digitalWrite(v[i], LOW);
            digitalWrite(v[j], LOW);
            delay(1000);  
      }
      digitalWrite(v[7/2], LOW);
     
}
