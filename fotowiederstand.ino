//https://www.roboter-bausatz.de/projekte/lichtsensor-fotowiderstand-mit-arduino-auslesen

int pinConfig[][10] = {{13},{A0, A1}};
int pins = *(pinConfig + 1) - *pinConfig;

float normalGoalOne = 0;
float normalGoalTwo = 0;

int score[2] = {0,0};

void setup() {
  Serial.begin(9600);
  for (int i=0; i<pins; i++){if(*((*(pinConfig))+i)==0){continue;};pinMode(*((*(pinConfig))+i), OUTPUT);}
  for (int i=0; i<pins; i++){if(*((*(pinConfig+1))+i)==0){continue;};pinMode(*((*(pinConfig+1))+i), INPUT);}

  normalGoalOne = analogRead(*((*(pinConfig+1))+0));
  normalGoalTwo = analogRead(*((*(pinConfig+1))+1));
}

void readSensor(){
  float GoalOne = analogRead(*((*(pinConfig+1))+0));
  if(GoalOne<(normalGoalOne/2)){score[0] += 1;}      // Geht das mit  Pointern? Bzw geht das überhaupt weil es sich verändert?

  float GoalTwo = analogRead(*((*(pinConfig+1))+1));
  if(GoalTwo<(normalGoalTwo/2)){score[1] += 1;}
}

void loop() {
  readSensor();
}
