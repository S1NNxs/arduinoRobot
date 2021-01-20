#include "Arduino.h"
#include "Average.h"



Average::Average(unsigned long value,unsigned int arrSize){ //parametrit(Muuttuja, taulukon koko

arrSize = _arrSize;

*ptrArr = new unsigned int[_arrSize]; //uusi dyynaminen taulukko
for (int count = 0; count< _arrSize; count++){ //dyynaminen taulukon täyttö
  ptrArr[count] = value;
  }
}

unsigned long Average::Calculate(unsigned long x){
  unsigned long sum = 0;
  ptrArr[_index++] = x;
  if(_index == _arrSize){_index = 0;}
  for (int count = 0; count< _arrSize; count++){//lukeminen taulokosta ja laskeminen luvuen summa.
  sum = sum + ptrArr[count];
  }
  unsigned long average = sum/_arrSize;
  return average;
  }
