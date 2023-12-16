#include <WiFi.h>
#include <PubSubClient.h>

// WiFi
const char *ssid = "P.3819"; // Enter your WiFi name
const char *password = "meomeo..3";  // Enter WiFi password
#define led 2
// MQTT Broker
const char *mqtt_broker = "broker.emqx.io";
const char *topic = "test";
const char *mqtt_username = "device1";
const char *mqtt_password = "test123";
const int mqtt_port = 1883;
int ledState = 0;
WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  // Set software serial baud to 115200;
  Serial.begin(115200);
  pinMode(led, OUTPUT);
  // connecting to a WiFi network
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println("Connected to the WiFi network");
  //connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("Public emqx mqtt broker connected");
    } else {
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
    }
  }
  // publish and subscribe

  client.subscribe(topic);
}

void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message arrived in topic: ");
  Serial.println(topic);
  Serial.print("Message:");
  char chuoi_ro[100];
  chuoi_ro[0] = '\0';
  char chuoi[2];
  for (int i = 0; i < length; i++) {
    //Serial.print((char) payload[i]);
    char c = (char) payload[i];
    chuoi[0] = c;
    chuoi[1] = '\0';
    strncat(chuoi_ro, chuoi, 1);
    // Mảng chứa ký tự và ký tự kết thúc chuỗi '\0'
    
    Serial.print(c);
  }
  if (strcmp(chuoi_ro, "b") == 0) {
   ledState = 1;
  } else {
    ledState = 0;
  }
 
  Serial.println();
  Serial.println("-----------------------");
}

void loop() {
  client.loop();
   if(ledState == 1){
   digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
  // mess_loop();
}
void mess_loop() {
  client.publish(topic, "Hi EMQX I'm ESP32 ^^");
  delay(2000);
}
