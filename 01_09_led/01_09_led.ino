#include <math.h>
#include "AdafruitIO_WiFi.h"
#include "NewPing.h"

#define WIFI_SSID ""
#define WIFI_PASS ""


#define IO_USERNAME ""
#define IO_KEY ""

AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);


AdafruitIO_Feed *warning_button = io.feed("warning button");

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

//variaveis de controller
bool AlarmeAtivo = false;
unsigned int distancia = 0;
const int LIMITE_DISTANCIA = 15;

void setup() {
  Serial.begin(115200);
  // pinMode(pinNTC, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(pinLed, OUTPUT);
  pinMode(Button, INPUT);


  while (!Serial)
    ;

  // Serial.print("Conectando ao Adafruit IO");
  io.connect();

  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("conected!");


  //vinculo

  warning_button->onMessage(handleAlarm);

  Serial.println("Soliciitando o estado inicial do alarme: ");

  warning_button->get();

  delay(1000);
}

void loop() {
  io.run();

  //leitura do button
  if (digitalRead(Button) == 1) {
    delay(200);
    AlarmeAtivo = !AlarmeAtivo;

    warning_button->save(ativeWarn ? "true" : "false");
    Serial.println(ativeWarn ? "Alarme armado pelo button" : "Alarme desarmado pelo button");
  }

  disstancia = sonar.ping_cm();
  Serial.print("Distancia lida: ");
  Serial.println(distancia);
  Serial.println(" cm");

  //ativação ou desativação do alarme
  if(alarmeAtivo && distancia > 0 && distancia < LIMITE_DISTANCIA){
    ativeWarn();
  }
  else{
    offWarn();
  }
  // delay(1000);
}
