 
#include <AFMotor.h>  // khai bao thu vien cho dong cơ
#include <NewPing.h> // khai báo thư viện để tính khoảng cách cho sr 04
#include <Servo.h>  // khai báo thư viện cho servo
#include <SoftwareSerial.h> // khai báo thư viện cho Bluetooth

#define TRIG_PIN A0 
#define ECHO_PIN A1
#define SENSOR A3
#define MAX_DISTANCE 200  
#define MAX_SPEED 170
#define SPEED_TURN 160
SoftwareSerial bluetoothSerial(9,10); // RX, TX
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
//
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo myservo;  
int speedSet = 0;
int speedSpan = 150;
int distance = 200; 
int speedSetTest = 130;
int value;
char c;
char command;
boolean isRunning; 
void setup() {
 bluetoothSerial.begin(9600);
 Serial.begin(19200);
  delay(1000);
  myservo.attach(10);
  myservo.write(80);
  pinMode(SENSOR,INPUT);
  delay(1500);
 
 }
void loop() {
//  char a = bluetoothSerial.read();
//  if(a == '1' || a == '2'){
//    command = a;
//  }
if (bluetoothSerial.available()){
  delay(10);
   command = bluetoothSerial.read();
 
}

//Serial.println(c);
  
  distance = readPing();
  value = readIR();
  Serial.println(command);
  Serial.println(distance);
  Serial.println(value);
//  if(command == '2'){
//  isRunning = false;
//} else if(command == '1'){
//  isRunning = true;
//}
if(command == '1'){
      
  int distanceR = 0;
 int distanceL = 0;
 if( value <= 50){
 if(distance <= 15 )
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(200);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR >= distanceL)
  { 
    turnRight();
    delay(680);
    moveStop();
    delay(100);
    moveForwardTurn();
    delay(150);
    moveStop();
    delay(100);
    turnRight();
    delay(650);
    moveStop();
  }else
  {
 
    turnLeft();
    delay(680);
    moveStop();
    delay(100);
    moveForwardTurn();
    delay(150);
    moveStop();
    delay(100);
    turnLeft();
    delay(650);
    moveStop();
  }  
  }else 
 {
  moveForward();
  }
 } else{
   moveBackward();
   delay(350);
   int distanceR = 0;
 int distanceL = 0;
  moveStop();
  delay(100);
  distanceR = lookRight();
  delay(100);
  distanceL = lookLeft();
delay(100);
  if(distanceR >= distanceL)
  { 
    turnRight();
    delay(800);
    moveStop();
   
  }else
  {
 
    turnLeft();
    delay(800);
    moveStop();
  }
}
}

  if(command == '2'){
 
    moveStop();
    }
}
//    value = readIR();
//    Serial.print("value1 :");
//    Serial.println(value);
//   
//distance = readPing();
//   command = bluetoothSerial.read();




int lookRight()
{
    myservo.write(30); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(80); 
    return distance;
}

int lookLeft()
{
    myservo.write(150); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(80); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 210;
  }
  return cm;
}
int readIR(){
  delay(70);
  int cm = analogRead(SENSOR);
  return cm;
}

void moveStop() {
   motor1.run(RELEASE); 
   motor4.run(RELEASE);
   motor2.run(RELEASE); 
   motor3.run(RELEASE);
  } 
  
void moveForward() {
   motor2.run(FORWARD);      
   motor3.run(FORWARD); 
   motor1.run(FORWARD);      
   motor4.run(FORWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor1.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
     motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
   
  }
}
void moveForwardTurn() {
     motor2.setSpeed(SPEED_TURN);
   motor3.setSpeed(SPEED_TURN);
   motor1.setSpeed(SPEED_TURN);
   motor4.setSpeed(SPEED_TURN);
   motor1.run(FORWARD);      
   motor4.run(FORWARD); 
    motor2.run(FORWARD);      
   motor3.run(FORWARD); 
     
  
}

void moveBackward() {
   motor2.run(BACKWARD);      
   motor3.run(BACKWARD); 
   motor1.run(BACKWARD);      
   motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    motor1.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
  }
}  

void turnRight() {

   motor2.setSpeed(SPEED_TURN + 50);
   motor3.setSpeed(SPEED_TURN);
   motor1.setSpeed(SPEED_TURN + 50);
   motor4.setSpeed(SPEED_TURN);
   motor1.run(FORWARD);
   motor4.run(BACKWARD);   
   motor2.run(FORWARD);
   motor3.run(BACKWARD);   
   
} 
 
void turnLeft() {
   motor4.setSpeed(SPEED_TURN + 50);
   motor1.setSpeed(SPEED_TURN);
   motor3.setSpeed(SPEED_TURN + 50);
   motor2.setSpeed(SPEED_TURN);
   motor1.run(BACKWARD);     
   motor4.run(FORWARD);
      motor2.run(BACKWARD);      
   motor3.run(FORWARD);  

}  
