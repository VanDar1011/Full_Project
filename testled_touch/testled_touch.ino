const int pinLedGround = 6 ;
const int pinTouchLedGround = 8;
const int pinResistanceOptical = 7;
bool stateLedGround = false;
bool flagResistance = true;
bool flagLedGroundDay = true;
bool loopState = true;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(pinLedGround, OUTPUT);
  pinMode(pinTouchLedGround, INPUT);
  pinMode(pinResistanceOptical, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if ((digitalRead(pinResistanceOptical) == LOW) && (flagResistance == true )) {
    stateLedGround = true;
    if (digitalRead(pinTouchLedGround) == HIGH) {
      flagResistance = false;
      stateLedGround = false;
    }
    loopState = true;
    Serial.println("dat1");
  }
  if ((digitalRead(pinResistanceOptical) == LOW) && (flagResistance == false )) {
    if (digitalRead(pinTouchLedGround) == HIGH) {
      stateLedGround = !stateLedGround;
      Serial.println("dat2");
    } 
    if(digitalRead(pinResistanceOptical) == HIGH){
      flagLedGroundDay = true;
   Serial.println("dat3");
    }
    loopState = true;
  }
  if (digitalRead(pinResistanceOptical) == HIGH) {
    if(stateLedGround == true && loopState == true ) {
          stateLedGround = false;
          loopState = false;
          Serial.println("tat led khi nhan cam bien lan dau");
    } 
    else {
         if (flagResistance == false) {
      flagResistance = true;
      Serial.println("abc1");
    }

    if (true) {
      if (digitalRead(pinTouchLedGround) == HIGH) {
        stateLedGround = !stateLedGround;
      }
      
      Serial.println("abc3");
    }
    if (stateLedGround == true && flagLedGroundDay == true) {

      stateLedGround = false;
      flagLedGroundDay  = false;
      Serial.println("abc4");
    }
    }
 
  }

  Serial.println(stateLedGround);
  if (stateLedGround == true) {
    digitalWrite(pinLedGround, HIGH);
  }
  else {
    digitalWrite(pinLedGround, LOW);
  }
  delay(1000);

}
