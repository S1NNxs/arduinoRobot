#ifndef MotorShield_h
#define MotorShield_h

#include "Arduino.h"

const int FORWARD=LOW;
const int BACKWARD=HIGH;

class Motor{
	public:
	Motor(int pwmCtl, int directCtl);
	Control(int speed, bool reverse);
	
	private:
	int _pwmCtl;
	int _directCtl;
	int _speed;
	int _reverse;
	
};


#endif
