#ifndef Average_h
#define Average_h
#include "Arduino.h"

class Average
{
  public:
    Average(unsigned long value,unsigned int arrSize);
    unsigned long Calculate(unsigned long x);
  

  private:
  int _index= 0;
  int _arrSize;
  unsigned int*ptrArr;
  

  
  };

#endif
