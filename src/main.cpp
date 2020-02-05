#define FW_NAME "Sonoff 4CH"
#define FW_VERSION "0.1.0"

#include <Homie.h>

void setup() {
    Serial.begin(115200);
    Serial << endl << endl;

    Homie_setFirmware(FW_NAME, FW_VERSION);
    Homie.setup();
}

void loop() {
    Homie.loop();
}
