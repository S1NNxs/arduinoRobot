#include "Arduino.h"
#include "Average.h"



Average::Average(unsigned long value){ //parametrit(Muuttuja)

for (int count = 0; count< _arrSize; count++){ //dyynaminen taulukon täyttö
  _distVal[count] = value;
  }
}

unsigned long Average::Calculate(unsigned long x){ //poista vanhemmin arvo taulukosta ja kirjoitaa uuden.
  unsigned long sum = 0;
  _distVal[_index++] = x;
  if(_index == _arrSize){_index = 0;}
  for (int count = 0; count< _arrSize; count++){//lukeminen taulokosta ja laskeminen luvuen summa.
  sum = sum + _distVal[count];
  }
  unsigned long average = sum/_arrSize; //laske keskiarvo
  return average;
  }
