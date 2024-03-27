#include <Arduino.h>

#define LED_A 13
#define LED_B 12
#define BTN_UP 3
#define BTN_DOWN 4

int current = 0;

void update() {
    analogWrite(LED_A, current);
    analogWrite(LED_B, 255 - current);
}

void setup() {
    Serial.begin(9600);
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(BTN_UP, INPUT);
    pinMode(BTN_DOWN, INPUT);
    update();
}

void loop() {
    // One button increases the light level
    if (digitalRead(BTN_UP) == 0) {
        if (current < 245) {
            current += 10;
        } else {
            current = 255;
        }
        Serial.println("UP");
        Serial.println(current);
        update();
        delay(100);
    }

    // The other button decreases the light level
    if (digitalRead(BTN_DOWN) == 0) {
        if (current > 10) {
            current -= 10;
        } else {
            current = 0;
        }
        Serial.println("DOWN");
        Serial.println(current);
        update();
        delay(100);
    }
}
