#ifndef MotorShield_h
#define MotorShield_h

#include "Arduino.h"


const bool FORWARD = false; //vaihtaa "reverce" muttujan "LOW" tai "false" FORWARD:ksi
const bool BACKWARD = true; //vaihtaa "reverce" muttujan "HIGH" tai "true" BACKWARD:ksi


class Motor{ 
	public:
	Motor(int pwmCtl, int directCtl, int balance);
	void Control(int speed, bool reverse);
  
	
	private:
	int _pwmCtl; //PWM pinni
	int _directCtl; //Direct pinni
	int _speed; //PWM muttuja, nopeudensäätö
	int _reverse; //Suunnanvaito
  int _balance; //Nopeuden hidastuvuus
	
};



#endif
