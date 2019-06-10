#include <M5Stack.h>
#include <WiFi.h>
#include <esp8266-google-home-notifier.h>

const char* ssid     = "SSID";
const char* password = "パスワード";
// 通知を送りたいGoogle Homeの名前
const char* room     = "寝室";

GoogleHomeNotifier ghn;

void setup() {
  Serial.begin(115200);
  Serial.println("");

  Serial.print("Connecting to Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");

  Serial.println("Connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  M5.begin();
  M5.Lcd.println("M5Stack is running successfully!");
}

void handleBtnA() {
  Serial.println("BtnA pressed."); 
  M5.Lcd.println("BtnA pressed.");
  handleBtn("ご飯ができましたよ！");
}

void handleBtn(char* message) { 
  Serial.println("Connecting to Google Home...");
  if (ghn.device(room, "ja") != true) {
    Serial.println(ghn.getLastError());
    return;
  }

  Serial.print("Found Google Home(");
  Serial.print(ghn.getIPAddress());
  Serial.print(":");
  Serial.print(ghn.getPort());
  Serial.println(")");

  if (ghn.notify(message) != true) {
    Serial.println(ghn.getLastError());
    return;
  }

  Serial.println(message); 
}

void loop() {
  M5.update();
  if(M5.BtnA.wasPressed()) {
    handleBtnA();
  }
}
