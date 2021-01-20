#include "Arduino.h"
#include "MotorShield.h"

Motor::Motor(int pwmCtl, int directCtl, int balance) //Mootorin asetukset (PWM pin, DIRECT pin, BALANCE) "balance" - hidastuvuus jos pyörät pyöri epätasaisesti.
{
	pinMode(pwmCtl, OUTPUT);
	pinMode(directCtl, OUTPUT);
	
	_pwmCtl=pwmCtl; //Nopeuden säätö kopio "Control" fuktiolle
	_directCtl=directCtl; //Sunnanvaihto kopio "Control" fuktiolle
  _balance=balance; //Nopeudensäätö: hidastuvuus kopio "Control" fuktiolle
  
	
}

//Ohjaa nopeuden ja sunnanvaihto 
void Motor::Control(int speed, bool reverse) { //Ota nopeude ja pyörimissunnan parametrit
  analogWrite(_pwmCtl, speed - _balance); //Lähettää ne parametrit moottorin ohjaukseen
  if (reverse)  {
    digitalWrite(_directCtl, FORWARD); //tarkista onko pyörimissuunta kellon suuntaan vastaava
  }
  else  {
    digitalWrite(_directCtl, BACKWARD); s
  }
}
