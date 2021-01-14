#include "Arduino.h"
#include "UltraSonic.h"


USonic::USonic(int trigPin, int echoPin)
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  _trigPin = trigPin;
  _echoPin = echoPin;
  }
  
long duration;
int distance;

USonic::Distance(){
	
//Code for ultrasonic module
// Clears the trigPin
digitalWrite(_trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(_trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(_trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(_echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
return distance; 
}
