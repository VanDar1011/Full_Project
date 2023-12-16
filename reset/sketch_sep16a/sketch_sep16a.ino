#include <avr/wdt.h>
 
void ResetBoard( uint8_t time) 
{
  wdt_enable(time);
  while(1) {}
}
 
void setup()
{
 
}
 
void loop() 
{
 ResetBoard( WDTO_60MS);
}
