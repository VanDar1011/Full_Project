
// Before uploading the code you have to install the necessary library//
//AFMotor Library https://learn.adafruit.com/adafruit-motor-shield/library-install //
//NewPing Library https://github.com/livetronic/Arduino-NewPing// 
//Servo Library https://github.com/arduino-libraries/Servo.git //
// To Install the libraries go to sketch >> Include Library >> Add .ZIP File >> Select the Downloaded ZIP files From the Above links //


#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 
 
#define TRIG_PIN A0 
#define ECHO_PIN A1
#define MAX_DISTANCE 200 
#define MAX_SPEED 190 // sets speed of DC  motors
#define MAX_SPEED_OFFSET 20

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo myservo;   

boolean goesForward=false;
int distance = 0;

void setup() {
Serial.begin(9600);
  myservo.attach(10);
  myservo.write(90); 
  delay(2000);
}

void loop() {
  myservo.write(45);
  Serial.println("Right");
  delay(2000);
  khoang_cach();
  myservo.write(90);
   Serial.println("Center");
  delay(2000);
   khoang_cach();
  myservo.write(135);
  Serial.println("Left");
 delay(2000);
  khoang_cach();
} `
int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  return cm;
}
void khoang_cach(){
distance = (sonar.ping_cm());
      
  while (distance == 0) //NewPing is supposed to return 0
  {                     //when ping is out of range
   distance = 255;
    delay(50);
  }
  Serial.print(distance);  
  Serial.println("cm");
  delay(50);
}
