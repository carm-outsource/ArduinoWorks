#include <Arduino.h>

#define RED_LED 2
#define GREEN_LED 3
#define YELLOW_LED 4


void setup() {
    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(YELLOW_LED, OUTPUT);
}

void color(int r, int g, int b) {
    analogWrite(RED_LED, r);
    analogWrite(GREEN_LED, g);
    analogWrite(YELLOW_LED, b);
}

void change(int r, int g, int b) {
    color(r * 36, g * 36, b * 36);
    delay(100);
}


void loop() {
    int i, j, k;
    for (i = 1; i <= 7; i++) {
        for (j = 1; j <= 7; j++) {
            for (k = 1; k <= 7; k++) change(i, j, k);
            for (k = 6; k >= 2; k--) change(i, j, k);
        }
        for (j = 6; j >= 2; j--) {
            for (k = 1; k <= 7; k++) change(i, j, k);
            for (k = 6; k >= 2; k--) change(i, j, k);
        }
    }
    for (i = 6; i >= 2; i--) {
        for (j = 6; j >= 2; j--) {
            for (k = 6; k >= 2; k--) change(i, j, k);
            for (k = 1; k <= 7; k++) change(i, j, k);
        }
        for (j = 6; j >= 2; j--) {
            for (k = 1; k <= 7; k++) change(i, j, k);
            for (k = 6; k >= 2; k--) change(i, j, k);
        }
    }


}
