#include <EEPROM.h>

void writeStringIntoEEPROM(int address, String str){
  byte len = str.length();
  EEPROM.write(address,len);
for(int i=0; i < len;i++){
    EEPROM.write(address + 1 + i,str[i]);
}
}
String readStringFromEEPROM(int address){
  int len = EEPROM.read(address);
  char data[len+1];
  for(int i =0 ;i < len ;i++){
    data[i] = EEPROM.read(address+1+i);
  }
  data[len]='\0';
  return String(data);
}

void setup()
{
  Serial.begin(9600);
  String a = "1111";
  writeStringIntoEEPROM(0,a);
  
}

void loop()
{
  Serial.println(readStringFromEEPROM(0));
}
