#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
// #include <UrlEncode.h>

const char* ssid = "SSID";
String Username = "Username";
String password="wifipassword";
const char* Password = "panel_password";
String PhoneNumber = "Dedicated_number";
String Smsclass = "1";
String RecNumber = "Recipient_number";
String MessageBody;
String url = "https://raygansms.com/SendMessageWithUrl.ashx?Username=" + Username + "&Password=" + Password + "&PhoneNumber=" + PhoneNumber + "&MessageBody=" + MessageBody + "&RecNumber=" + RecNumber + "&Smsclass=" + Smsclass;

WiFiClient client;
HTTPClient httpClient;


void setup() {
  Serial.begin(9600);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());  ///////////
  httpClient.begin(client, url);

  int httpCode = httpClient.GET();
  if (httpCode > 0) {
    String payload = httpClient.getString();  /////
    Serial.println(httpCode);
    Serial.println(payload);
  } else {
    Serial.println("Error on HTTP request");
  }
}

void loop() {
  httpClient.GET();
  String MessageBody = httpClient.getString();
  httpClient.end();
  Serial.println(MessageBody);
  delay(5000);
}