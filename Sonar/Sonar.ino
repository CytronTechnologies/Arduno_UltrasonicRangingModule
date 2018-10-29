#define trigPin 12
#define echoPin 13
#define beepPin 10
#define scalingfactor 50

int inches = 0;
unsigned long duration = 0;
unsigned long maxtime = 1000;
unsigned long i = 1;
unsigned long time2 = 0;
unsigned long time1 = 0;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(beepPin, OUTPUT);
}

void logdistance(){
  time1 = millis();
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  inches = duration/148;
  time2 = millis();
  maxtime = scalingfactor*inches;
}

void delayandcheckdistance(){
  i=1;
  while(1){
    if (i % 60 == 0){
      logdistance();
    }
    delay(1);
    ++i;
    if (i >= maxtime){
      break;
    }
  }
}

void beep(){
  digitalWrite(beepPin, HIGH);
  delay(90);
  logdistance();
  if(time2-time1 < 30){
    delay(60-(time2-time1));
  }
  digitalWrite(beepPin, LOW);
}

void loop(){
  beep();
  delayandcheckdistance();
}

