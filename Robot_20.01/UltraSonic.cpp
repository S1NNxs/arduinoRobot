#include "Arduino.h"
#include "UltraSonic.h"



USonic::USonic(int trigPin, int echoPin) //Ultraäänietäisyysmittarin asetukset (TRIG, ECHO)
{
  pinMode(trigPin, OUTPUT); //Pistä Trig pinni lähtevän signaaliksi
  pinMode(echoPin, INPUT);  //Pistä Echo pinni saapuvan signaaliksi

  _trigPin = trigPin; //Tekee muuttujan kopio
  _echoPin = echoPin; //Tekee muuttujan kopio
  }


unsigned long USonic::Distance(){ //Mittää etäisyys

    
  switch(_state){  
                     
    case START_SEND:                                     // Pistä Trig Low tilaan ja talenna nykyaika
    _currentTime = millis();                              //Teke aikaleiman ms (TIMEOUT)
    digitalWrite(_trigPin, LOW);                          //Muutaa Trig LOW tilaan 
    _distance = 0;                                          //Nollaa _distance arvo
    _currentMicros = micros();                                //Aikaleimaus OFF_TIME
    if(_currentMicros - _previousMicros >= OFF_TIME){   //tarkista onko OFF_TIME aika kulunut
      _previousMicros = _currentMicros;                 //Jos on, tekee  aikaaleima _previousMicros
      _state = END_SEND;                              //Jatkaa serurava askeliin
    }
    break;
    
    case END_SEND:                                        //Lähetää HIGH signaali
    _currentMicros = micros();                          //tekee aikaleiman
    digitalWrite(_trigPin, HIGH);                       //Pistä Trig HIGH tilaan              
    if(_currentMicros - _previousMicros >= ON_TIME){  //Vertaa onko ON_TIME kulunut
      _previousMicros = _currentMicros;               //Jos se toteutuu, aikaleima -> _previousMicros
      digitalWrite(_trigPin, LOW);                    //Pistä Trif LOW tilaan
      _state = START_RECEIVE;                         //Seurava askel
    }
    break;
    
    case START_RECEIVE:                             //Odotaa tulevan vastauksen
    if(digitalRead(_echoPin) == HIGH){              //Jos Echo tulee HIGH tilaan
    _measure = micros();                             //tekee aikaleiman _measure
    _state = END_RECIEVE;                             //Seurava askel
    }
    break;
    
    case END_RECIEVE:                                 //Laskee etäisyys 
    if(digitalRead(_echoPin) == LOW){                 //Jos Echo on LOW tilassa
      _duration = (micros() - _measure);              //Laskee nykyisen aikaan - _measure
      _distance = _duration * 0.034/2;                //laske etäisyys
      _state = START_SEND;                            //Ohjelma paluu alkuun
    }
    break;
    
}

if(millis()-_currentTime>=TIMEOUT){                 // jos Echo pinnin ei tule signaali, palauu aslein 1.
 _state = START_SEND;
 return -1; 
 }
if(_distance > 0){ 
return (_distance);}
return 0;
}


 
