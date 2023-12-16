#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
#include <Keypad.h>
#define LCD_I2C_ADDR 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);
//Servo servo;
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
byte pin_rows[ROW_NUM] = { 5, 4, 3, 2 };
byte pin_cols[COL_NUM] = { A3, A2, A1, A0 };
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_cols, ROW_NUM,
                       COL_NUM);
String password = "1111";
bool codeEntered = false;
String pwd = "";
int n = 0;
int resetPwd = 0;
void setup() {
  Serial.begin(9600);

  servo.attach(6);
  servo.write(90);
  lcd.init();
  lcd.backlight();
  // introScreen();

  // put your setup code here, to run once:



}

void loop() {
  char key = keypad.getKey();
  if (key != NO_KEY) {
    lcd.setCursor(0, 1);
    lcd.print(key);
  }
}
void checkCode() {
  delay(50);
  char key = keypad.getKey();
  if (key != NO_KEY) {
    pwd += key;
    lcd.setCursor(n, 1);
    lcd.print("*");
    n++;
  }
  if (n == 4) {

    if (pwd.equalsIgnoreCase(password)) {
      codeEntered = true;
    } else {
      lcd.setCursor(0, 0);
      lcd.print("Mat khau sai");
      resetPwd++;
      if (resetPwd == 4) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Thu lai sau 5s");
        delay(10000);
        resetPwd = 0;
      }
      lcd.setCursor(0, 1);
      lcd.print("Nhap lai mkhau");
      delay(500);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Nhap mat khau");
      lcd.setCursor(0, 1);

      pwd = "";
    }
    n = 0;
  }
}
void grantAccess() {
  lcd.setCursor(0, 0);
  lcd.print("Mat khau dung");
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Wel come");
  codeEntered = false;
  pwd = "";
  delay(200);
  servo.write(180);
  delay(1000);
  servo.write(90);
  delay(1000);
}
void introScreen() {
  lcd.clear();
  lcd.setCursor(3, 0);
  lcd.print("Smart Home");
  lcd.setCursor(2, 1);
  lcd.print("Welcome back");
  delay(600);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nhap mat khau");
  lcd.setCursor(0, 1);
}
