#define RUNNING_DURATION 300000
#define SLEEP_DURATION  1800000

int pinOut = 10;
bool isON = true;

unsigned long nextOFFTime = 0;
unsigned long nextONTime = 0;

void setup() {
  pinMode(pinOut, OUTPUT);
  digitalWrite(pinOut, LOW);
  nextOFFTime = millis() + RUNNING_DURATION;
}

void loop() {
        
       
    if(millis() > nextOFFTime && isON == true){
        digitalWrite(pinOut, HIGH);
        nextONTime = millis()+SLEEP_DURATION;
        isON = false;
    }
    
    if(millis() > nextONTime && isON == false){
       digitalWrite(pinOut, LOW);
        nextOFFTime = millis() + RUNNING_DURATION;
        isON = true;
    }
}
