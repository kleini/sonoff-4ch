#define FW_NAME "Sonoff 4CH"
#define FW_VERSION "1.0.0"

#include <Homie.h>

#include "ButtonNode.hpp"
#include "RelayNode.hpp"

const int PIN_BUTTON1 = 0;
const int PIN_RELAY3 = 4;
const int PIN_RELAY2 = 5;
const int PIN_BUTTON2 = 9;
const int PIN_BUTTON3 = 10;
const int PIN_RELAY1 = 12;
const int PIN_LED = 13;
const int PIN_BUTTON4 = 14;
const int PIN_RELAY4 = 15;

RelayNode relay1("relay1", PIN_RELAY1);
RelayNode relay2("relay2", PIN_RELAY2);
RelayNode relay3("relay3", PIN_RELAY3);
RelayNode relay4("relay4", PIN_RELAY4);
ButtonNode button1("button1", PIN_BUTTON1, []() {
  relay1.toggleRelay();
});
ButtonNode button2("button2", PIN_BUTTON2, []() {
  relay2.toggleRelay();
});
ButtonNode button3("button3", PIN_BUTTON3, []() {
  relay3.toggleRelay();
});
ButtonNode button4("button4", PIN_BUTTON4, []() {
  relay4.toggleRelay();
});

void setup() {
  Serial.begin(115200);
  Serial << endl << endl;

  pinMode(PIN_BUTTON1, INPUT);
  pinMode(PIN_LED, OUTPUT);

  Homie_setFirmware(FW_NAME, FW_VERSION);
  Homie.disableResetTrigger();
  Homie.setLedPin(PIN_LED, LOW);

  Homie.setup();
}

void loop() {
  Homie.loop();
}
