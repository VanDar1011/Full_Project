#define BLYNK_TEMPLATE_ID "TMPL6Q2ULC2Vv" //Id cua template tren blynk 
#define BLYNK_TEMPLATE_NAME "smartHome" // ten cua template tren blynk
#define BLYNK_AUTH_TOKEN "xBFmGopuzHwtN2E7aJW4yRWJJ1KKa9Ak"  // ma xac thuc(token) de ket noi voi blynk

#include <BlynkSimpleEsp32.h>

int ledPin = 2;
int p1;

char auth[] = "xBFmGopuzHwtN2E7aJW4yRWJJ1KKa9Ak"; // ma xac thuc(token) de ket noi voi Blynk
char ssid[] = "P.3819"; // ten mang wifi ket noi den(ao vi day la mo phong)
char pass[] = "meomeo..3";
void setup() {
  //không cần phải pinMode cho speakerPin
  
 pinMode(ledPin,OUTPUT);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
 Blynk.run();

}
BLYNK_WRITE(V0) {
  p1 = param.asInt();
  digitalWrite(ledPin, p1);
  delay(100);
}
