#include "DHT.h"
#include <NewPing.h>
#include <Servo.h>
//Khai báo loại cảm biến, có 2 loại là DHT11 và DHT22
const int DHTPIN = 2;       //Đọc dữ liệu từ DHT11 ở chân 2 trên mạch Arduino
const int DHTTYPE = DHT11;
float h;
float t;

#define TRIG_PIN 4
#define ECHO_PIN 5
#define MAX_DISTANCE 200
#define BUTTON_PIN 3
#define LED_PIN 7
int distance = 0;
bool ledState = false;
//struct touch {
//   byte wasPressed = LOW;
//   byte isPressed = LOW;
//};
//touch touch;
Servo myservo;
DHT dht(DHTPIN, DHTTYPE);
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
void setup() {
  Serial.begin(9600);
  myservo.attach(6);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  dht.begin();         // Khởi động cảm biến
}

void loop() {
  readTemp();
  delay(100);   //Đợi 1 giây
  distance = readPing();
  if (distance < 5) {
    moCua();
  }
  returnStateButton();
 
}
 void moCua() {
    Serial.println("MỞ cửa");
    for (int i = 0; i < 255; i++) { // chạy từ 0 đến 255 giá trị

      myservo.write(i);

      delay(3); // đợi 3 mili dây
    }
  }
int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  return cm;
}
void readTemp() {
  h = dht.readHumidity();    //Đọc độ ẩm
  t = dht.readTemperature(); //Đọc nhiệt độ
  Serial.print("Nhiet do: ");
  Serial.println(t);               //Xuất nhiệt độ
  Serial.print("Do am: ");
  Serial.println(h);               //Xuất độ ẩm
  Serial.println();
  if (t > 37) {
    Serial.println("Bat dieu hoa di");
  }
}
void returnStateButton() {
  if (digitalRead(BUTTON_PIN) == HIGH) {
    ledState = !ledState;
  }
  if (ledState == true) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
