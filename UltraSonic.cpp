#include "Arduino.h"
#include "UltraSonic.h"



USonic::USonic(int trigPin, int echoPin) //Ultraäänietäisyysmittarin asetukset (TRIG, ECHO)
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  _trigPin = trigPin;
  _echoPin = echoPin;
  }


unsigned long USonic::Distance()
{

    
    switch(_state){
    
    case START_SEND:
    _currentTime = millis();
    _distance = 0;
    digitalWrite(_trigPin, LOW);
    _currentMicros = micros();
    if(_currentMicros - _previousMicros >= OFF_TIME){
      _previousMicros = _currentMicros;         //  
      _state = END_SEND;
    }
    break;
    
    case END_SEND:
    _currentMicros = micros();
    digitalWrite(_trigPin, HIGH);                   
    if(_currentMicros - _previousMicros >= ON_TIME){ 
      _previousMicros = _currentMicros;               
      digitalWrite(_trigPin, LOW);
      _state = START_RECEIVE;
    }
    break;
    
    case START_RECEIVE:
    if(digitalRead(_echoPin) == HIGH){
    _measure = micros();
    _state = END_RECIEVE;
    }
    break;
    
    case END_RECIEVE:
    if(digitalRead(_echoPin) == LOW){
      _duration = (micros() - _measure);
      _distance = _duration * 0.034/2;
      _state = START_SEND;
    }
    break;
    
}

if(millis()-_currentTime>=TIMEOUT){
 _state = START_SEND;
 }
 
  
    return _distance;
    
  }

 
