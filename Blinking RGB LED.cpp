// Simple red/blue blinking RGB LED
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}


void blink(int pin,int d)
{
  digitalWrite(pin, HIGH);
  delay(d);
  digitalWrite(pin, LOW);
}


void loop()
{
  {blink(13, 400);}
  delay(50);
  {blink(11, 400);}
}
