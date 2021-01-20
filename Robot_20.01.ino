#include "UltraSonic.h"
#include "MotorShield.h"
#include "Average.h"


//TODO 
//Poista mootorin ojhauksesta Delay-funktio
//Tehdä oma luokka moottorin nopeuden ohjauksen
//Moottorit toimivat eri nopeusella, täytyy tasapainota.
//Distance() funktio toimii vain funktio-kyselyn kautta, ei toimi muuttajan kautta. Täytyy tutkia lisää.
//Poista vanha Distance() koodi UlttaSonic kirjastosta
//Kirjoitaa kommentteja


//ultrasonic moduulin säätö
USonic Sensor1(8,9); //Ensimmäinen numero TrigPin, toinen EchoPin (echo, trig)
Motor Motor1(6,7,0); //Moottorin PWM ja Direct Control piuhat (pwm,directCtl)
Motor Motor2(5,4,15); //Moottorin PWM ja Direct Control piuhat (pwm,directCtl)
Average Distance(Sensor1.Distance(), 1);

void setup() {  
Serial.begin(9600); //serial port enable for debuging

}




void motorControl(){
  int distance = Sensor1.Distance();
  if (distance >=10){
    Motor1.Control(180, BACKWARD);
    Motor2.Control(180, BACKWARD);
    }
  else{
    Motor1.Control(90, BACKWARD);
    Motor2.Control(90, FORWARD);
    }
  }


  
  


void loop() {
  //Serial.println(Distance.Calculate(Sensor1.Distance()));
  Serial.println(Sensor1.Distance());

  

    }   
 
  
