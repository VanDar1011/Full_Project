#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>
#define LCD_I2C_ADDR 0x27
LiquidCrystal_I2C lcd(0x27,16,2);
Servo myservo;
const int openLook = 0;
const int closeLook = 90;
const byte ROW_NUM = 4;
const byte COL_NUM = 4;
char keys[ROW_NUM][COL_NUM] = {
{ '1', '2', '3', 'A' },
{ '4', '5', '6', 'B' },
{ '7', '8', '9', 'C' },
{ '*', '0', '#', 'D' }
};
byte pin_rows[ROW_NUM] = { 5,4,3,2 };
byte pin_cols[COL_NUM] = { A3,A2,A1,A0 };
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_cols, ROW_NUM,
COL_NUM);
String password = '1111';

void setup() {
  myservo.attach(6);
  lcd.init();                    
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("Arduinokit.vn");
  lcd.setCursor(0,1);
  lcd.print("Xin chao cac ban");

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
