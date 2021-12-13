#include <ESP8266WiFi.h>

uint8_t redPin = D0;
uint8_t greenPin = D1;
uint8_t bluePin = D2;

const char* ssid     = "FiberHGW_ZTEH3D_2.4GHz";
const char* password = "TDxcyXhuhg";

String R = "00";
String G = "00";
String B = "00";
byte r;
byte g;
byte b;

WiFiServer server(80); //port

unsigned long currentTime = millis();
unsigned long previousTime = 0;
const long timeoutTime = 2000;

IPAddress local_IP(192, 168, 1, 43);  //change these with your board's addresses (I recomemnd using initial adresses)
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns1(192, 168, 1, 1);

void setup()
{
  Serial.begin(115200);

  if (!WiFi.config(local_IP, gateway, subnet, dns1)) {
    Serial.println("STA Failed to configure");
  }

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); //You can find your board's initial IP address with this line
  server.begin(80);
}
void loop()
{
  WiFiClient client = server.available();

  if (client) {
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();

        if (c == 'r') {
          for (byte i = 0; i < 2; i++) {
            R[i] = client.read();
          }
          r = R.toInt();
        }
        else if (c == 'g') {
          for (byte i = 0; i < 2; i++) {
            G[i] = client.read();
          }
          g = G.toInt();
        }
        else if (c == 'b') {
          for (byte i = 0; i < 2; i++) {
            B[i] = client.read();
          }
          b = B.toInt();
        }
        else  {
          analogWrite(redPin, r);
          analogWrite(greenPin, g);
          analogWrite(bluePin, b);
        }

        analogWrite(redPin, r);
        analogWrite(greenPin, g);
        analogWrite(bluePin, b);

        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
          }
        }
      }
    }
  }
}
