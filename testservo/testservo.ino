#include <AFMotor.h>
 
#include <Servo.h> 
 
int i;
 
Servo servo1;
 \
void setup() {  
 
    Serial.begin(9600);           // mở cổng monitor 9600 bps  
    
    Serial.println("Test servo!");     
    
    servo1.attach(10);    // Khai báo chân servo
 
}
 
void loop() {
 
//    for (i=0; i<255; i++) {   // chạy từ 0 đến 255 giá trị     
// 
//        servo1.write(i);    
//        
//        delay(3); // đợi 3 mili dây
//    }    
// 
//    for (i=255; i!=0; i--) {
//        servo1.write(i-255); 
//        delay(3);  
//    }   
servo1.write(80);
delay(1000);
servo1.write(30);
delay(1000);
servo1.write(150);
delay(1000);

}
