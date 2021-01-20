//for ultrasonic module
#define trigPin 8
#define echoPin 9
//for motor controll
#define MOTOR1 6 //motor 1 speed control
#define MOTOR2 5 //motor 2 speed control
#define MOTOR2_DIRECTION 7 //motor 2 direction control
#define MOTOR1_DIRECTION 4 //Motor 1 direction control

#define FORWARD LOW
#define BACKWARD HIGH

#define FULL_SPEED 255
#define STOP 0

void setup() {
  //pinmode for motor control
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
    //pinmode for ultrasonic module
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  
  
  Serial.begin(9600); //serial port enable for debuging
}

long duration;
int distance;

int Distance(){
//Code for ultrasonic module
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
return distance; 
}

void Motor1(int speed, bool reverse) {
  analogWrite(MOTOR1, speed);
  if (reverse)  {
    digitalWrite(MOTOR1_DIRECTION, BACKWARD);
  }
  else  {
    digitalWrite(MOTOR1_DIRECTION, FORWARD);
  }
}

void Motor2(int speed, bool reverse) {
  analogWrite(MOTOR2, speed);
  if (reverse)  {
    digitalWrite(MOTOR2_DIRECTION, BACKWARD);
  }
  else  {
    digitalWrite(MOTOR2_DIRECTION, FORWARD);
  }
}


int Speed_value(){ //Motor speed setup
  int speed;
  if (Distance()==175){speed = FULL_SPEED;}
  if (Distance()<175){speed = Distance()/0.6;}
  if (Distance()<100){speed = 100;}
  if (Distance()<10){speed = STOP;}
  return speed;
}




void loop() {
  Speed_value();
  Serial.println(Speed_value());
  
    
      //forward
    if (Distance() > 30)   {
      Motor1(Speed_value, true);
      Motor2(Speed_value, true);
    }
  else if(Distance()< 30){
      Motor1(Speed_value, true);
      Motor2(Speed_value, false);
      delay (1000);
  }     
    
  }
