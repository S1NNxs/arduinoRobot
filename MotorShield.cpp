<<<<<<< HEAD
#include "Arduino.h"
#include "MotorShield.h"

Motor::Motor(int pwmCtl, int directCtl)
{
	pinMode(pwmCtl, OUTPUT);
	pinMode(directCtl, OUTPUT);
	
	_pwmCtl=pwmCtl;
	_directCtl=directCtl;
	
}



Motor::Control(int speed, bool reverse) {
  analogWrite(_pwmCtl, speed);
  if (reverse)  {
    digitalWrite(_directCtl, BACKWARD);
  }
  else  {
    digitalWrite(_directCtl, FORWARD);
  }
}
=======
#include "Arduino.h"
#include "MotorShield.h"

Motor::Motor(int pwmCtl, int directCtl)
{
	pinMode(pwmCtl, OUTPUT);
	pinMode(directCtl, OUTPUT);
	
	_pwmCtl=pwmCtl;
	_directCtl=directCtl;
	
}



Motor::Control(int speed, bool reverse) {
  analogWrite(_pwmCtl, speed);
  if (reverse)  {
    digitalWrite(_directCtl, BACKWARD);
  }
  else  {
    digitalWrite(_directCtl, FORWARD);
  }
}
>>>>>>> 1b5bc16bd089aec3a92494c572e35a5836c0ef35
