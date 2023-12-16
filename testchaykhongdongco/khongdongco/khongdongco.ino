
#include <AFMotor.h>  
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A0 
#define ECHO_PIN A1
#define SENSOR A3
#define MAX_DISTANCE 200  
#define MAX_SPEED 190
#define MAX_SPEED_OFFSET 10

NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

Servo myservo;   

boolean goesForward=false;
int distance = 200; 
int speedSet = 0;
int value;
void setup() {
  Serial.begin(9600);
  myservo.attach(10);
  myservo.write(80);
  pinMode(SENSOR,INPUT);
  delay(1500);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  value = readIR();
  delay(100);
  value = readIR();
  delay(100);
}

void loop() {
 int distanceR = 0;
 int distanceL = 0;
 delay(40);
  if(value <= 40){
 if(distance<=15 )
 {
  moveStop();
  delay(100);
  moveBackward();
  delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  { 
    turnRight();
    moveStop();
  }else
  {
    turnLeft();
    moveStop();
  }  
  }else 
 {
  moveForward();
 }} else {
  moveBackward();
 }
 distance = readPing();
 value = readIR();
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
  Serial.println("Xe dung");
  delay(50);
  } 
  
void moveForward() {
 Serial.println("Xe di thang");
  delay(50);

}

void moveBackward() {
   Serial.println("Xe lui");
  delay(50);
 
}  

void turnRight() {
  Serial.println("Xe re phai");
  delay(50);
} 
 
void turnLeft() {
   Serial.println("Xe re trai");
  delay(50);
}  
