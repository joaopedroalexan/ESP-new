void handleAlarm(AdafruitIO_Data *data) {
  String valor = data->toString();

  Serial.print(F("valor recebedo do fid: "));
  Serial.println(valor);

  if (valor == "true") {
    AlarmeAtivo = true;
    Serial.println("Alarme Armado Pelo Dashboard / app");
  } else {
    AlarmeAtivo = false;
    Serial.println("Alarme Desarmado pelo DashBoard / App");
  }
}

void ativeWarn(){
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(pinLed, HIGH);
}

void offWarn(){
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(pinLed, LOW);
}