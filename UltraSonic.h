
#ifndef UltraSonic_h
#define UltraSonic_h

#include "Arduino.h"

class USonic
{
  public:
    USonic(int trigPin, int echoPin);
    Distance();
  private:
  int _trigPin;
  int _echoPin;
};








#endif
