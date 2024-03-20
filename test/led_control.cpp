#include <Arduino.h>

#define RED_LED 2
#define GREEN_LED 3
#define YELLOW_LED 4

void toggle(int pin, bool state) {
    digitalWrite(pin, state ? HIGH : LOW);
}

void shutdown() {
    toggle(RED_LED, false);
    toggle(GREEN_LED, false);
    toggle(YELLOW_LED, false);
}


void setup() {
    Serial.begin(9600);
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
    shutdown();
}

void loop() {

    if (!Serial.available()) {
        return;
    }

    char command = Serial.read();
    switch (command) {
        case 'r':
            shutdown();
            toggle(RED_LED, true);
            break;
        case 'g':
            shutdown();
            toggle(GREEN_LED, true);
            break;
        case 'y':
            shutdown();
            toggle(YELLOW_LED, true);
            break;
        case 'o':
            shutdown();
            break;
        case 'a':
            toggle(RED_LED, true);
            toggle(GREEN_LED, true);
            toggle(YELLOW_LED, true);
            break;
        default:
            break;
    }
}
