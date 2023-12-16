int Sensor = A3;
//int Sensor = 7;
int Value;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(Sensor, INPUT);

}

void loop() {
  Value = analogRead(Sensor);
 //Value =digitalRead(Sensor);
  Serial.print("Gia tri cua cam bien:  ");
  Serial.println(Value);
  // put your main code here, to run repeatedly:
delay(1000);
}
