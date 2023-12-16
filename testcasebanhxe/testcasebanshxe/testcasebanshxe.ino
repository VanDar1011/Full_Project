#include <AFMotor.h>
AF_DCMotor motor1(1, MOTOR12_1KHZ); // create motor #1, 1KHz pwm
AF_DCMotor motor2(2, MOTOR12_1KHZ); // motor #2
AF_DCMotor motor3(3, MOTOR12_1KHZ); // motor #3
AF_DCMotor motor4(4, MOTOR12_1KHZ); // motor #4
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
moveForward();
}
void moveForward() {
  Serial.println("All motors ahead - fast");  
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);  
  motor1.setSpeed(200); 
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void moveBackward() {
  Serial.println("All motors backward - fast");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  motor1.setSpeed(200); 
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);
}

void moveleft() {
  Serial.println("Pivot left");
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD); 
  motor1.setSpeed(200); 
  motor2.setSpeed(200);  
  motor3.setSpeed(200); 
  motor4.setSpeed(200);
}

void moveright() {
  Serial.println("Pivot right");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD); 
  motor1.setSpeed(200); 
  motor2.setSpeed(200);  
  motor3.setSpeed(200); 
  motor4.setSpeed(200);
}

void moveStop() {
  uint8_t i;
  for (i=255; i!=0; i--) {
    motor1.setSpeed(i); 
    motor2.setSpeed(i); 
    motor3.setSpeed(i); 
    motor4.setSpeed(i);
    delay(10);
    }
   Serial.println("All motors stop");
   motor1.run(RELEASE);
   motor2.run(RELEASE);
   motor3.run(RELEASE);
   motor4.run(RELEASE);   
}

void avoidLeft() {
  moveStop();
  moveBackward();
  delay(1500);
  moveleft();
  delay(900);
}

void avoidRight() {
  moveStop();
  moveBackward();
  delay(1500);
  moveleft();
  delay(900);
}
