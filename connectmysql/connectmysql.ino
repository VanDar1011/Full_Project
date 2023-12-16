#include <WiFi.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>

char ssid[] = "P.3819";
char pass[] = "meomeo..3";

char user[] = "root";
char password[] = "";
char host[] = "127.0.0.1";
char db[] = "iot";

WiFiClient client;
MySQL_Connection conn((Client *)&client);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  if (conn.connect(host, 3307, user, password)) {
    Serial.println("Connected to MySQL server");
  } else {
    Serial.println("Connection failed");
  }
}

void loop() {
  MySQL_Cursor *cur_mem = new MySQL_Cursor(&conn);
  cur_mem->execute("SELECT * FROM led");
  MySQL_Row *row = NULL;
  do {
    row = cur_mem->get_next_row();
    if (row != NULL) {
      for (int i = 0; i < cur_mem->get_fields_num(); i++) {
        Serial.print(row->values[i]);
        Serial.print("\t");
      }
      Serial.println();
    }
  } while (row != NULL);
  delay(5000);
  delete cur_mem;
  conn.close();
}
