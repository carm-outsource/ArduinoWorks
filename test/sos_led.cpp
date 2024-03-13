#include <Arduino.h>

void toggle(int time) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(time);
    digitalWrite(LED_BUILTIN, LOW);
    delay(time);
}

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

    for (int i = 0; i < 3; ++i) {
        toggle(500);
    }
    
    for (int i = 0; i < 3; ++i) {
        toggle(200);
    }

}
