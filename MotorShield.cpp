#include "Arduino.h"
#include "MotorShield.h"

Motor::Motor(int pwmCtl, int directCtl, int balance) //Mootorin asetukset (PWM pin, DIRECT pin, BALANCE) "balance" - hidastuvuus jos pyörät pyöri epätasaisesti.
{
	pinMode(pwmCtl, OUTPUT);
	pinMode(directCtl, OUTPUT);
	
	_pwmCtl=pwmCtl; //Nopeuden säätö "Control" fuktiolle
	_directCtl=directCtl; //Sunnanvaihto "Control" fuktiolle
  _balance=balance; //Nopeudensäätö: hidastuvuus "Control" fuktiolle
  
	
}

//Ohjaa nopeuden ja sunnanvaihto 
Motor::Control(int speed, bool reverse) {
  analogWrite(_pwmCtl, speed - _balance);
  if (reverse)  {
    digitalWrite(_directCtl, BACKWARD);
  }
  else  {
    digitalWrite(_directCtl, FORWARD);
  }
}
