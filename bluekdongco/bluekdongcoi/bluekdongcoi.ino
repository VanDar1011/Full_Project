
#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 
#include <SoftwareSerial.h>

#define TRIG_PIN A0 
#define ECHO_PIN A1
#define SENSOR A3
#define MAX_DISTANCE 200  
#define MAX_SPEED 170
#define SPEED_TURN 170
SoftwareSerial bluetoothSerial(9,10); // RX, TX
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);
//
AF_DCMotor motor1(1); 
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
Servo myservo;   

boolean goesForward=false;
int distance = 200; 
int speedSet = 0;
int speedSetTest = 130;
int value;
char command;
boolean isRunning;
// int speedOffset = 5;     
void setup() {
 bluetoothSerial.begin(9600);
 Serial.begin(19200);
  delay(1000);
  myservo.attach(10);
  myservo.write(80);
  pinMode(SENSOR,INPUT);
  delay(1500);
  distance = readPing();
  delay(100);
  value = readIR();
  delay(100);
  command = bluetoothSerial.read();
  if(command == '1'){
    isRunning  = true;
  }
  delay(200);
}
void loop() {
  if(isRunning){
  int distanceR = 0;
 int distanceL = 0;
 delay(40);
 if( value <= 40){
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
 } else {
  moveBackward();
  delay(400);
 } distance = readPing();
 value = readIR();
  } else {
    moveStop();
    }
distance = readPing();

 value = readIR();
 Serial.println(distance);
 Serial.println(value);
   command = bluetoothSerial.read();
  if(command == '2'){
  isRunning = false;
} else if(command == '1'){
  isRunning = true;
} Serial.println(command);
}

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
  Serial.println("Dung");
  } 
  
void moveForward() {

 Serial.println("Di thang");
  
}
void moveForwardTurn() {

    Serial.println("Di thang re");
     
  
}

void moveBackward() {
   Serial.println("Di lui");
}  

void turnRight() {
   Serial.println("Re phai"); 
} 
 
void turnLeft() {
   Serial.println("Re trai");

}  
