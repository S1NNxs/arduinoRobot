#define EN1 6
#define EN2 5

void setup() {
  pinMode(4, OUTPUT); //
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);  //set pin 4,5,6,7 to output mode
  Serial.begin(9600);
}
void Motor1(int pwm){
  analogWrite(EN1, pwm);
  }

void Motor2(int pwm){
  analogWrite(EN2, pwm);
  }
void loop() {
  char val;
  while (1)  {
    val = Serial.read();
    if (val != -1)    {
      switch (val)      {
        case 'w'://Move ahead
          Motor1(255); //You can change the speed, such as Motor(50,true)
          Motor2(255);
          break;
        
        case 's'://stop
          Motor1(0);
          Motor2(0);
          break;
      }
    }
  }
  
  
}
