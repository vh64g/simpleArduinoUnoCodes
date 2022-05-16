int LEDPins[] = {
        3, 10, 11, 12, 8
};

int RGBLEDPins[] = {5, 6, 9};

int pinCount = 5;

int RGBPinCount = 3;

int BLBtonesCountS1 = 13;
int BLBtonesCountS2 = 10;

int tonesBLBS1[][3] = {{165, 100, 50},{147, 50, 50},{147, 50, 50},{220, 50, 50},{220, 50, 50},{392, 50, 50},{330, 50, 50},{294, 50, 50},{493, 50, 50},{466, 50, 50},{440, 50, 50},{392, 50, 50},{165, 50, 50}};
int tonesBLBS2[][3] = {{147, 75, 50},{247, 75, 50},{415, 75, 50},{247, 75, 50},{220, 75, 50},{247, 75, 50},{233, 75, 50},{247, 75, 50},{247, 75, 50},{165, 75, 50}};

void allon()
{
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {
        digitalWrite(LEDPins[thisPin], HIGH);
    }
}

void alloff()
{
    for (int thispin = 0; thispin < pinCount; thispin++)
    {
        digitalWrite(LEDPins[thispin], LOW);
    }
}

void discostart()
{
    digitalWrite(2, HIGH);
    delay(200);
    digitalWrite(2, LOW);
}

void Lied(int tonesBLBS1[][3], int tonesBLBS2[][3])
{
  for (int thistone = 0; thistone < BLBtonesCountS1; thistone++)
  {
    {Zuffall();}
    tone(13, tonesBLBS1[thistone][0]);
    delay(tonesBLBS1[thistone][1]);
    noTone(13);
    delay(tonesBLBS1[thistone][2]);
  }
  for (int thistone = 0; thistone < BLBtonesCountS1; thistone++)
  {
    {Zuffall();}
    tone(13, tonesBLBS1[thistone][0]);
    delay(tonesBLBS1[thistone][1]);
    noTone(13);
    delay(tonesBLBS1[thistone][2]);
  }
  for (int thistone = 0; thistone < BLBtonesCountS2; thistone++)
  {
    {Zuffall();}
    tone(13, tonesBLBS1[thistone][0]);
    delay(tonesBLBS1[thistone][1]);
    noTone(13);
    delay(tonesBLBS2[thistone][2]);
  }
  {RGBoff();}
}

void RGB()
{
    analogWrite(9, 255);
    analogWrite(5, 140);
    analogWrite(6, 0);
    delay(1000);
    analogWrite(9, 0);
    analogWrite(5, 255);
    analogWrite(6, 255);
    delay(1000);
    analogWrite(9, 255);
    analogWrite(5, 0);
    analogWrite(6, 255);
    delay(1000);
}

void Lila()
{
    analogWrite(9, 255);
    analogWrite(5, 0);
    analogWrite(6, 255);
}
void orange()
{
    analogWrite(9, 255);
    analogWrite(5, 140);
    analogWrite(6, 0);
}
void Hellblau()
{
    analogWrite(9, 0);
    analogWrite(5, 255);
    analogWrite(6, 255);
}

void Zuffall()
{
    int R = random(0, 255);
    int G = random(0, 255);
    int B = random(0, 255);
    analogWrite(9, R);
    analogWrite(5, G);
    analogWrite(6, B);
}

void RGBoff()
{
  analogWrite(9, 0);
  analogWrite(5, 0);
  analogWrite(6, 0);
}

void setup()
{
    for (int thisPin = 0; thisPin < pinCount; thisPin++) {

        pinMode(LEDPins[thisPin], OUTPUT);

    }
    for (int thisPin = 0; thisPin < RGBPinCount; thisPin++){

        pinMode(RGBLEDPins[thisPin], OUTPUT);

    }
    pinMode(2, OUTPUT);
    pinMode(13, OUTPUT);
    Serial.begin(9600);
    randomSeed(analogRead(A1));

}

void loop()
{
    {discostart();}
    {allon();}
    {RGB();}
    {Lied(tonesBLBS1, tonesBLBS2);}
    {Lied(tonesBLBS1, tonesBLBS2);}
    {alloff();}
    delay(2000);
}
