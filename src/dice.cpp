
#include <Arduino.h>

#define BTN 2

#define LED_A 3
#define LED_B 4
#define LED_C 5
#define LED_D 6
#define LED_E 7
#define LED_F 8
#define LED_G 9

int CODES[] = {
        0X5B, 0X4F,
        0X66, 0X6D,
        0X7D, 0X07,
};

void display(int num) {
    Serial.begin(9600);
    digitalWrite(LED_A, num & 0x01);
    digitalWrite(LED_B, num & 0x02);
    digitalWrite(LED_C, num & 0x04);
    digitalWrite(LED_D, num & 0x08);
    digitalWrite(LED_E, num & 0x10);
    digitalWrite(LED_F, num & 0x20);
    digitalWrite(LED_G, num & 0x40);
}

void setup() {
    pinMode(BTN, INPUT);
    pinMode(LED_A, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(LED_C, OUTPUT);
    pinMode(LED_D, OUTPUT);
    pinMode(LED_E, OUTPUT);
    pinMode(LED_F, OUTPUT);
    pinMode(LED_G, OUTPUT);
    // 全亮
    display(0x7F);
}

void loop() {
    if (digitalRead(BTN) == 0) {
        int num = random(0, 5);
        display(CODES[num]);
        delay(1000);
    }
}
