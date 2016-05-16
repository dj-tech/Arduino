
#include <WiFiSSLClient.h>
#include <WiFi101.h>
#include <SPI.h>
#include <TelegramBot.h>
// Initialize Wifi connection to the router
char ssid[] = "xxxx";             // your network SSID (name)
char pass[] = "yyyy";           // your network key
// Initialize Telegram BOT
const String BotToken = "xxxx"; 
const String BotName = "yyyy";
const String BotUsername = "zzzz";
WiFiSSLClient client;
TelegramBot bot (BotToken, BotName, BotUsername, client);
const int ledPin =  6;  // the number of the LED pin
void setup() {
  Serial.begin(115200);
  while (!Serial) {}
  delay(3000);
  // attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  while (WiFi.begin(ssid, pass) != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  bot.begin();
  pinMode(ledPin, OUTPUT);
}
void loop() {
  message m = bot.getUpdates(); // Read new messages
  if ( m.text.equals("On")) {
    digitalWrite(ledPin, HIGH);
    bot.sendMessage(m.chat_id, "The Led is now ON");
  }
  else if ( m.text.equals("Off")) {
    digitalWrite(ledPin, LOW);
    bot.sendMessage(m.chat_id, "The Led is now OFF");
  }
}
