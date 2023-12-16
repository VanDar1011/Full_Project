int in1 = 6;
int in2 = 7;
int ena = 8;

void setup() 
{
pinMode(ena,OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

}

void loop() 
{ analogWrite(ena,255);
  digitalWrite (in1, LOW);
  digitalWrite (in2, HIGH);

  delay (1000);

}
