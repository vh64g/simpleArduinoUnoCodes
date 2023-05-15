//https://www.roboter-bausatz.de/projekte/lichtsensor-fotowiderstand-mit-arduino-auslesen

int pinConfig[][10] = {{13},{A0}};
int pins = *(pinConfig + 1) - *pinConfig;

float normal = 0;

void setup() {
  Serial.begin(9600);
  for (int i=0; i<pins; i++){if(*((*(pinConfig))+i)==0){continue;};pinMode(*((*(pinConfig))+i), OUTPUT);}
  for (int i=0; i<pins; i++){if(*((*(pinConfig+1))+i)==0){continue;};pinMode(*((*(pinConfig+1))+i), INPUT);}

  normal = analogRead(*((*(pinConfig+1))+1));
}

void readSensor(){
  float value = analogRead(*((*(pinConfig+1))+1));
  if(value<(normal/2)){}
}

void loop() {
  {readSensor();}
}
