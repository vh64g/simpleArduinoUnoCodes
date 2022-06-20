using namespace std;

int i;

int outputPins[] = {13,12,11,10};
int outputPinCount = *(&outputPins+1) - outputPins;
int lightning[][3] = {{12, 2500, 740},{11, 750, 0},{10,3000, 0},{11, 750, 0}};
int lightStepCount = *(&lightning+1) - lightning;

void declarePins()
{
  for(i=0; i<outputPinCount; i++)
  {
    pinMode(outputPins[i], OUTPUT);
  }
}


void lightcontrol()
{
  for(i=0; i<lightStepCount; i++)
  {
    digitalWrite(lightning[i][0],1);
	tone(13, lightning[i][2]);
    delay(lightning[i][1]);
    digitalWrite(lightning[i][0],0);
    noTone;
  }
}


void setup()
{
  {declarePins();}
}


void loop()
{
  {lightcontrol();}
}
