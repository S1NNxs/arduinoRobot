
#ifndef UltraSonic_h
#define UltraSonic_h

#include "Arduino.h"

#define START_SEND 1
#define END_SEND 2
#define START_RECEIVE 3
#define END_RECIEVE 4

class USonic
{
  public:
  USonic(int trigPin, int echoPin);
  unsigned long Distance();
  
  
 
    
  private:
  int _trigPin;
  int _echoPin; 
  
  unsigned long _currentMicros;
  unsigned long _previousMicros = 0;
  const int ON_TIME = 10;
  const int OFF_TIME = 2;
  const int TIMEOUT = 1000; 
  unsigned long _measure;
  unsigned long _duration;
  unsigned long _currentTime;
  unsigned long _distance;
  int _trigState = LOW;
  int _state = START_SEND;
  
  

 
};




#endif
