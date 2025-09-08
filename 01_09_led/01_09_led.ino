#include <math.h>
#include "AdafruitIO_WiFi.h"
#include "NewPing.h"

#define WIFI_SSID "..."
#define WIFI_PASS "..."


#define IO_USERNAME "..."
#define IO_KEY "..."

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


AdafruitIO_Feed *botaoled = io.feed("botaoled");

// --- Configuração
// #define pinNTC 34
#define Button 26
#define BUZZER_PIN 27
#define pinLed 13
#define TRIG_PIN 12
#define ECHO_PIN 14

//config do ultrasom
#define MAX_DISTANCE 100
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() {
  Serial.begin(115200);
  // pinMode(pinNTC, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(Button, INPUT);


  while (!Serial)
    ;

  // Serial.print("Conectando ao Adafruit IO");
  // io.connect();

  // while(io.status() < AIO_CONNECTED){
  // Serial.print(".");
  // delay(500);
  // }

  // Serial.println();
  // Serial.println(io.statusText());


  // botaoled -> onMessage(handleLed);

  // delay(1000);
}

void loop() {

  // Serial.print(F("DISTANCIA LIDA: "));
  // Serial.println(sonar.ping_cm());
  // delay(500);
  // testebuzzer();
  // testeled();
  // pushbutton(Button);
  // io.run();

  // delay(1000);
}
