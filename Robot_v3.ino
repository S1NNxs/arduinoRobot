#include "UltraSonic.h"
#include "MotorShield.h"


//ultrasonic moduulin säätö
USonic Module1(8,9); //Ensimmäinen numero TrigPin, toinen EchoPin
Motor Unit1(6,7);
Motor Unit2(5,4);




void setup() {  

Serial.begin(9600); //serial port enable for debuging
}



void loop() {

//  Serial.println(Module1.Distance());
 
  }
