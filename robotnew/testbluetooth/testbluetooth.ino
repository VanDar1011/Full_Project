 
#include <AFMotor.h>  // khai bao thu vien cho dong cơ
#include <NewPing.h> // khai báo thư viện để tính khoảng cách cho sr 04
#include <Servo.h>  // khai báo thư viện cho servo
//#include <SoftwareSerial.h> // khai báo thư viện cho Bluetooth

#define TRIG_PIN A0 
#define ECHO_PIN A1
#define SENSORR A3
#define SENSORL A4
#define MAX_DISTANCE 200  
#define MAX_SPEED 180
#define SPEED_TURN_BACK 200
#define SPEED_TURN 200
//SoftwareSerial bluetoothSerial(9,10); // RX, TX
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
//
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

Servo myservo;
int in1 = 2;
int in2 = 13;  
int speedSet = 0;
int distance = 200; 
int valueR;
int valueL;
//boolean turnR;
//boolean turnL;
//char c;
//char command;
void setup() {
 //Serial.begin(9600);
  //delay(1000);
  myservo.attach(10);
  myservo.write(80);
  pinMode(SENSORR,INPUT);
  pinMode(SENSORL,INPUT);
  delay(1500);
 pinMode (in1, OUTPUT);
 pinMode (in2, OUTPUT);
 }
void loop() {
  distance = readPing();
  valueR = readIRR();
   valueL = readIRL();
 // Serial.println(command);
  //Serial.println(distance);
  //Serial.println(valueR);
  //Serial.println(valueL);
//  if(command == '2'){
//  isRunning = false;
//} else if(command == '1'){
//  isRunning = true;
//}
//if(command == '1'){
  digitalWrite (in1, HIGH);// bat tin hieu quay hai motor choi quet
  digitalWrite (in2, LOW); //bat tin hieu quay hai motor choi quet
  
 if( valueR <= 50 && valueL <= 50){
  int distanceR = 0;
  int distanceL = 0;
 if(distance <= 15 )
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(600);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR >= distanceL)
  { 
    if(distanceR < 15){
      moveBackward();
      delay(600);
    }
    else{
    
    turnRight();
   delay(700);
    moveStop();
    }
  }else
  {
 if(distanceL < 15){
  moveBackward();
   delay(600);
 } else {
    turnLeft();
    delay(700);
    moveStop();
 }
  }  
  }else 
 {
  moveForward();
  }
 } else
 {if((valueL > 50 && valueR < 50) || (valueR > 50 && valueL > 50)){
   moveBackward();
   delay(400);
   moveStop();
    delay(100);
    turnRightBack();
    delay(800);
    moveStop(); 
}
  if(valueR > 50 && valueL < 50)
  {
  moveBackward();
   delay(400);
    moveStop();
  delay(100);
    turnLeftBack();
    delay(800);
    moveStop();
  }
 }
}


 // if(command == '2'){
//   digitalWrite (in1, LOW);
//  digitalWrite (in2, LOW);
//    moveStop();
   // }
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
int readIRR(){
  delay(70);
  int cm = analogRead(SENSORR);
  return cm;
}

int readIRL(){
  delay(70);
  int cm = analogRead(SENSORL);
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
//void moveForwardTurn() {
//   motor2.setSpeed(SPEED_TURN);
//   motor3.setSpeed(SPEED_TURN);
//   motor1.setSpeed(SPEED_TURN);
//   motor4.setSpeed(SPEED_TURN);
//   motor1.run(FORWARD);      
//   motor4.run(FORWARD); 
//    motor2.run(FORWARD);      
//   motor3.run(FORWARD); 
//     
//}

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
void turnRightBack() {

   motor2.setSpeed(SPEED_TURN_BACK + 50);
   motor3.setSpeed(SPEED_TURN_BACK);
   motor1.setSpeed(SPEED_TURN_BACK + 50);
   motor4.setSpeed(SPEED_TURN_BACK);
   motor1.run(FORWARD);
   motor4.run(BACKWARD);   
   motor2.run(FORWARD);
   motor3.run(BACKWARD);   
       
} 
 
void turnLeftBack() {
   motor4.setSpeed(SPEED_TURN_BACK + 50);
   motor1.setSpeed(SPEED_TURN_BACK);
   motor3.setSpeed(SPEED_TURN_BACK + 50);
   motor2.setSpeed(SPEED_TURN_BACK);
   motor1.run(BACKWARD);     
   motor4.run(FORWARD);
   motor2.run(BACKWARD);      
   motor3.run(FORWARD);  
}
