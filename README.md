# Sonoff 4CH

Homie IoT based firmware for Sonoff 4CH and 4CH Pro.

The device needs to be configured in self-locking mode. Other modes are not intended and not tested but may work.

## Implementation details

Passed through button press from STM32 normally takes about 75ms. RF signals sometimes result in wrong button presses but those then last only for the 75ms.
Therefore when configuring the minimal button press down time down to 70ms, sometimes the wrong relays turn on. This can not be solved on the ESP8285.
The software therefore currently keeps the minimal button down time up to 90ms, which then avoids to turn on the wrong relays on wrongly received RF signals.
The drawback is now, that the button on the remote needs to be pressed a little bit longer.

After some more testing the wrongly triggered buttons only happen, if the RF remote is very near to the Sonoff 4CH Pro. Across larger distances the received
RF signals are never interpreted wrong and not wrong button presses appear.

## Links

[Itead Wiki](https://www.itead.cc/wiki/Sonoff_4CH_Pro)
[Tasmota](https://github.com/arendst/Tasmota/wiki/sonoff-4ch-pro)
