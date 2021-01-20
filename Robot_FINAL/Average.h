#ifndef Average_h
#define Average_h
#include "Arduino.h"

#define _arrSize 30
class Average
{
  public:
    Average(unsigned long value);
    unsigned long Calculate(unsigned long x);
    unsigned long Filter(unsigned long dist);
    unsigned long dist;
  private:
  int _index= 0;
  int _distVal[_arrSize];
  
  

  
  };

#endif
