#include <DistanceSensor.h>
#include <Stepper.h>


double stepsPerRevolution = 2048;
Stepper myStepper(stepsPerRevolution, 22, 24, 26, 28);   // Pin inversion to make the library work
void setup() {
  myStepper.setSpeed(5);   
  Serial.begin(9600);
  }
  
  void loop() {   
      // 1 rotation counterclockwise:   
      Serial.println("counterclockwise");       
      myStepper.step(-stepsPerRevolution);   
      delay(1000);
        
    // 1 rotation clockwise: 
    Serial.println("clockwise");  
    myStepper.step(stepsPerRevolution);
    delay(1000);
}
