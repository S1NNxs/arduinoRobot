#include "UltraSonic.h"
#include "MotorShield.h"
#include "Average.h"


//ultrasonic moduulin säätö
USonic Sensor1(8,9); //Ensimmäinen numero TrigPin, toinen EchoPin (echo, trig)
Motor Motor1(6,7,0); //Moottorin PWM ja Direct Control piuhat (pwm,directCtl)
Motor Motor2(5,4,15); //Moottorin PWM ja Direct Control piuhat (pwm,directCtl)
Average Distance1(Sensor1.Distance()); //Keskiarvon laskeminen

void setup() {  
Serial.begin(9600); //serial port enable for debuging
}

void motorControl(){                                //mootorin ohjaus
  int distance = Sensor1.Distance();                //Talenna etäsyys
  if (distance > 0){                                //vertaa, että etäisyys ei ole nolla
  if (distance >=20){                                //Jos etäisyys isompi kun 20cm ajaa eteen
    Motor1.Control(150, FORWARD);
    Motor2.Control(150, FORWARD);
    }
  else if (distance < 20) {                          //Jos alle 20, kääntää
    Motor1.Control(70, BACKWARD);
    Motor2.Control(70, FORWARD);
    }
    Serial.println(distance);
  }
}




  

void loop() {
  motorControl();
 }   
 
  
