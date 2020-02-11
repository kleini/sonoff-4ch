#define FW_NAME "Sonoff 4CH"
#define FW_VERSION "0.2.0"

#include <Homie.h>

const int PIN_LED = 13;

void setup() {
  Serial.begin(115200);
  Serial << endl << endl;

  pinMode(PIN_LED, OUTPUT);

  Homie_setFirmware(FW_NAME, FW_VERSION);
  Homie.disableResetTrigger();
  Homie.setLedPin(PIN_LED, LOW);

  Homie.setup();
}

void loop() {
  Homie.loop();
}
