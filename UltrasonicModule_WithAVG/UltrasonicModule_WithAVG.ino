


  int _trigPin = 8;
  int _echoPin = 9;
  unsigned long _currentMicros;
  unsigned long _previousMicros = 0;
  const int START_SEND = 1;
  const int END_SEND = 2;
  const int START_RECEIVE = 3;
  const int END_RECIEVE = 4;
  
  const int ON_TIME = 10;
  const int OFF_TIME = 2;
  const int TIMEOUT = 1000;
  unsigned long _currentTime;
  unsigned int _distance;
  int _trigState = LOW;
  int _state = START_SEND;
  unsigned long _measure;
  
void setup() {
  
  pinMode(_trigPin, OUTPUT);
  pinMode(_echoPin, INPUT);
  Serial.begin (9600);
}


unsigned long distance(){

    
    unsigned long _duration;
    
  switch(_state){
    
    case START_SEND:
    _currentTime = millis();
    digitalWrite(_trigPin, LOW);
    _distance = 0;
    _currentMicros = micros();
    if(_currentMicros - _previousMicros >= OFF_TIME){
      _previousMicros = _currentMicros;         //  
      _state = END_SEND;
    }
    break;
    
    case END_SEND:
    _currentMicros = micros();
    digitalWrite(_trigPin, HIGH);                   
    if(_currentMicros - _previousMicros >= ON_TIME){ 
      _previousMicros = _currentMicros;               
      digitalWrite(_trigPin, LOW);
      _state = START_RECEIVE;
    }
    break;
    
    case START_RECEIVE:
    if(digitalRead(_echoPin) == HIGH){
    _measure = micros();
    _state = END_RECIEVE;
    }
    break;
    
    case END_RECIEVE:
    if(digitalRead(_echoPin) == LOW){
      _duration = (micros() - _measure);
      _distance = _duration * 0.034/2;
      _state = START_SEND;
    }
    break;
    
}

if(millis()-_currentTime>=TIMEOUT){
 _state = START_SEND;
 return -1; 
 }
 
return (_distance);
}





int _value;
int _arrSize;

int avgSetup(unsigned int value,unsigned int arrSize){
value = _value;
arrSize = _arrSize;
}


unsigned long avgValue(){ //parametrit(Muuttuja, taulukon koko)
unsigned long sum = 0; //nollata summa
unsigned long average = 0; //nollata keskiarvo
unsigned int *ptrArr = new unsigned int[_arrSize]; //uusi dyynaminen taulukko
for (int count = 0; count< _arrSize; count++){ //dyynaminen taulukon täyttö
  ptrArr[count] = _value;
}

for (int count = 0; count< _arrSize; count++){//lukeminen taulokosta ja laskeminen luvuen summa.
sum = sum + ptrArr[count];
}

average = sum/_arrSize; //laskeminen keskiarvo


delete [] ptrArr; //poistaa taulukko
return sum; //palauta keskiarvo
}

void loop() {

  int avgSetup(distance(),10);
  Serial.println(distance());
  


}
