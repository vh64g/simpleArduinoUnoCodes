//Define pin arrays
int outs[] = {7,2,13,12};
int triggers[] = {2,7};
int echos[] = {4,8};

// Get pin array lengths
int triggerCount = *(&triggers+1) - triggers;
int echoCount = *(&echos+1) - echos;
int outsLen = *(&outs+1) - outs;
int de = 500;

//Define constants
float soundSpeed = 0.03432;

//Setup pins, serial
void setup() {
  for(int i=0; i < outsLen; i++){pinMode(outs[i], OUTPUT);}
  for(int i=0; i < echoCount; i++){pinMode(echos[i], INPUT);}
  Serial.begin(9600); 
}

//Get the sensor data of each sensor
void getSensorData(){
  for (int i=0;i<triggerCount; i++){
      digitalWrite(triggers[i], 0);
      digitalWrite(triggers[i], 1);
      digitalWrite(triggers[i], 0);
      long du = pulseIn(echos[i],1);
      long distance = (du/2)*soundSpeed;
  }
}

// Main loop
void loop(){
  Serial.println("-------------------------------l---------------------------------");
  Serial.println("New run started:");
  getSensorData();
  delay(de);
}
