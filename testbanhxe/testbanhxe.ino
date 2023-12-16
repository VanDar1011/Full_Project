#include <AFMotor.h>
// 
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
//AF_DCMotor motest(3, MOTOR12_1KHZ);
unsigned long time; 
void setup() {  
    
    Serial.begin(9600);           // mở cổng Serial monitor 9600 bps 
    
    Serial.println("Hello my racing");     
    motor1.setSpeed(200);     // chọn tốc độ maximum 255`/255
    motor2.setSpeed(200);
    motor3.setSpeed(200);     // chọn tốc độ maximum 255`/255
    motor4.setSpeed(200);  
//  motest.setSpeed(255);
}  
 
void loop() {  
   Serial.print("tien");       
   motor1.run(FORWARD);
    motor2.run(FORWARD);
   motor3.run(FORWARD);
   motor4.run(FORWARD);
   delay(2000);
// // motest.run(FORWARD);
  Serial.print("lui");  
   motor1.run(BACKWARD);     // động cơ lùi  
   motor2.run(BACKWARD);
   motor3.run(BACKWARD);
  motor4.run(BACKWARD);
 delay(2000);
/// motest.run(BACKWARD);
    Serial.print("tack");     
   motor1.run(RELEASE);      //   dừng động cơ
    motor2.run(RELEASE);
   motor3.run(RELEASE);      //   dừng động cơ
  motor4.run(RELEASE);
//// motest.run(RELEASE);
     
 delay(2000);
} 
