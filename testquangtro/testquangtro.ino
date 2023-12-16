int cambien = 7;// khai báo chân digital 10 cho cảm biến

int Led = 6;//kháo báo chân digital 8 cho đèn LED

void setup (){
Serial.begin(115200);
pinMode(Led,OUTPUT);//pinMode xuất tín hiệu đầu ra cho led

pinMode(cambien,INPUT);//pinMode nhận tín hiệu đầu vào cho cảm biê

}

void loop (){

int value = digitalRead(cambien);//lưu giá trị cảm biến vào biến value
Serial.println(value);

digitalWrite(Led,value);//xuất giá trị ra đèn LED

}
