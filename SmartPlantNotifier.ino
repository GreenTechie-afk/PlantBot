#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include "secrets.h" 

#define LED_PIN D2
#define SENSOR_PIN A0

const char* telegramHost = "api.telegram.org";
const int httpsPort = 443;

bool messageSent = false;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  Serial.println("🌱 Smart Plant Notifier: Booting...");

  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\n✅ Wi-Fi connected!");
  Serial.print("📡 IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  int moisture = analogRead(SENSOR_PIN);
  Serial.print("Soil Moisture: ");
  Serial.println(moisture);

  if (moisture > 800) {
    Serial.println("🔴 DRY – Plant needs water!");
    digitalWrite(LED_PIN, HIGH);

    if (!messageSent) {
      sendTelegramMessage("🌿 ALERT: Your plant is dry! Water it soon");
      messageSent = true;
    }
  } else {
    Serial.println("✅ Moist – No action needed");
    digitalWrite(LED_PIN, LOW);
    messageSent = false;
  }

  delay(5000);
}

void sendTelegramMessage(String message) {
  WiFiClientSecure client;
  client.setInsecure();  // Accept all certs (still uses HTTPS)

  Serial.println("📤 Sending Telegram message...");

  if (!client.connect(telegramHost, httpsPort)) {
    Serial.println("❌ Telegram connection failed");
    return;
  }

  String url = "/bot" + String(botToken) + "/sendMessage?chat_id=" + String(chatID) + "&text=" + message;

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + telegramHost + "\r\n" +
               "User-Agent: ESP8266\r\n" +
               "Connection: close\r\n\r\n");

  delay(1000);  // Allow server to respond
  while (client.available()) {
    String line = client.readStringUntil('\n');
    Serial.println(line);  // Show Telegram's response
  }

  Serial.println("✅ Telegram message sent.");
}
