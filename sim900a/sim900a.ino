#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3
#define MQ2pin (0)
#define Flamepin 7
#define buzzer_pin 6

float sensorValue;
int flameValue;
SoftwareSerial sim900a(rxPin, txPin);
const String PHONE_1 = "+84819412556";

unsigned long startMillis1;
unsigned long startMillis2;
unsigned long startMillis3;
void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(115200);
  pinMode(buzzer_pin, OUTPUT);
  digitalWrite(buzzer_pin, LOW);
  //Begin serial communication with Arduino and SIM800L
  sim900a.begin(115200);
  sim900a.println("AT");
  delay(1000);
  sim900a.println("AT+CMGF=1");
   delay(1000);
  //send_mess("Alo",PHONE_1);

}

void loop()
{ sensorValue = analogRead(MQ2pin); // lay gia tri
  Serial.print("Sensor Value: ");// in gia tri ra
  Serial.print(sensorValue);
  Serial.println("");
  delay(1000);
  flameValue = digitalRead(Flamepin); // lay gia tri
  Serial.print("Flame Value: ");// in gia tri ra
  Serial.print(flameValue);
  Serial.println("");
  delay(1000);
//  -- - bao chay
  if ((sensorValue > 500 || flameValue == 0) || (sensorValue > 500 && flameValue == 0) ){ // so sanh gia tri

   // digitalWrite(buzzer_pin, HIGH);
  //send_mess("Alo", PHONE_1);
  startMillis1 = millis();
    while (millis() - startMillis1 < 10000) {
      // Chờ 5000ms
      make_call(PHONE_1);
    }

}

else {
   //digitalWrite(buzzer_pin,LOW);
}

//-- ket thuc bao chay
}


void send_mess(String text, String phone) {
  sim900a.print("AT+CMGF=1\r");
  delay(1000);
  sim900a.print("AT+CMGS=\"" + phone + "\"\r");
  delay(1000);
  sim900a.print(text);
  delay(100);
  sim900a.write(0x1A);
  delay(5000);
  Serial.println("gui tn xong");

}
void make_call(String phone)
{
//  sim900a.println("ATD" + phone + ";");
//  delay(10000);
  while (millis() - startMillis1 < 20000) {
      // Chờ 5000ms
    sim900a.println("ATD" + phone + ";");
    }
  Serial.println("da goi xong");
  sim900a.println("ATH");
  delay(1000); //1 sec delay
  Serial.println("goi xong");

}
