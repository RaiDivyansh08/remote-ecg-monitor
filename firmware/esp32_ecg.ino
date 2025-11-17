#include <WiFi.h>
#include <WebSocketsServer.h>

const char* ssid     = "Redmi Note 111s";     // <-- Your WiFi Name
const char* password = "0987654321";     // <-- Your WiFi Password

WebSocketsServer webSocket = WebSocketsServer(81);

const int analogPin = 34; // AD8232 OUTPUT -> GPIO34 (ADC1)
const int SAMPLE_RATE = 250; // Hz
const unsigned long INTERVAL_US = 1000000UL / SAMPLE_RATE;

unsigned long lastSampleMicros = 0;

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {
  if(type == WStype_CONNECTED){
    Serial.printf("Client %u connected\n", num);
  } else if(type == WStype_DISCONNECTED){
    Serial.printf("Client %u disconnected\n", num);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(analogPin, INPUT);

  Serial.println();
  Serial.println("ECG ESP32 Starting...");

  // Uncomment below if you want FIXED IP:
  // IPAddress local_IP(192,168,1,50);
  // IPAddress gateway(192,168,1,1);
  // IPAddress subnet(255,255,255,0);
  // WiFi.config(local_IP, gateway, subnet);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.printf("Connecting to %s", ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(300);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());

  webSocket.begin();
  webSocket.onEvent(webSocketEvent);

  lastSampleMicros = micros();
}

void loop() {
  webSocket.loop();
  unsigned long now = micros();
  if ((now - lastSampleMicros) >= INTERVAL_US) {
    lastSampleMicros += INTERVAL_US;
    int raw = analogRead(analogPin); // 0-4095
    webSocket.broadcastTXT(String(raw));
  }
  delay(0);
}
