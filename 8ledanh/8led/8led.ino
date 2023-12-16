//chân ST_CP của 74HC595
int latchPin = 11;
//chân SH_CP của 74HC595
int clockPin = 9;
//Chân DS của 74HC595
int dataPin = 12;
 
//Note 1:
int a[] = {};
 
void setup() {
   pinMode(latchPin, OUTPUT);
   pinMode(clockPin, OUTPUT);
   pinMode(dataPin, OUTPUT);
}
 
void loop() { 
   //Note 2: để ý số K ở i<K
   for (int i = 0;i<8;i++) {
      digitalWrite(latchPin, LOW);
      shiftOut(dataPin, clockPin, LSBFIRST, a[i]);  
      //Note 3: MSBFIRST có thể đổi thành LSBFIRST và ngược lại.
      digitalWrite(latchPin, HIGH);
      delay(500);
   }
}
