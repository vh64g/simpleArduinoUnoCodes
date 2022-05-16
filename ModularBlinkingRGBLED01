// Modular red/blue blinking RGB LED
int i;

int pinCount = 2;
int pins[] = {13,11,10};

int duration = 300;
int delays = 40;

void setup()
{
  for(i=0 ; i<pinCount ; i++)
	{
		pinMode(pins[i], OUTPUT);
	}
}


void blink(int pin,int du,int de)
{
  digitalWrite(pin, HIGH);
  delay(du);
  digitalWrite(pin, LOW);
  delay(de);
}


void loop()
{
  for(i=0 ; i<pinCount ; i++)
	{
    	{blink(pins[i], duration, delays);}
	}
}
