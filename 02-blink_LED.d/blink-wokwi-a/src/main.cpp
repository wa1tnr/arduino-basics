// Uno R3 wokwi vscode sim  blinkie with featurezz
// blink-a.ino
// Fri Jul  7 16:18:22 UTC 2023

#include <Arduino.h>
#define ARE_YOU_THERE                                                          \
    "it's in the bag - working program 17:34:22z  keiota  bialto"              \
    "\n\nobjective: make a thing happen every n blinks but not every 1 blink " \
    ";)\n"

// was: Feather M0 Express

#define SDELAY 4
#define SDELAYR 1200
#define LDELAY 4000
#define LDELAYR 400
// #define LED 6 // D13
#define LED 21 // D13

void trapped_in_error() {
    do {
        digitalWrite(LED, 1);
        delay((SDELAY / 4));
        digitalWrite(LED, 0);
        delay((SDELAYR / 8));
        Serial.print("  *FOUND ERROR* ");
        delay(100);
    } while (-1);
}

void pip_short() {
    Serial.write('s');
    digitalWrite(LED, 1);
    delay(SDELAY);
    digitalWrite(LED, 0);
    delay(SDELAYR);
}

void pip_long() {
    Serial.write('l');
    digitalWrite(LED, 1);
    delay(LDELAY);
    digitalWrite(LED, 0);
    delay(LDELAYR);
}

void found_error(void) {
    for (int i = 5; i > 0; i--) {
        // foreshadowing:
        pip_short();
        pip_long();
    }
    trapped_in_error();
}

void consequences() { Serial.write('Q'); }

const int SCALING = 14;
uint16_t not_every = 0;

void reset_not_every() { not_every = 0; }

void interstice() { // the artist formerly known as void dont_not_every()
    not_every++;
    bool expired = (not_every == SCALING);
    if (expired) {
        consequences();
        reset_not_every();
    }
}

void sdelay() {
    bool condition_holds = -1;
    int j = millis();
    do {
        int k = millis();
        if ((k - j) > 80) {
            condition_holds = 0;
        }
    } while (condition_holds);
}

void ldelay() {
    bool condition_holds = -1;
    int j = millis();
    do {
        int k = millis();
        if ((k - j) > 880) {
            condition_holds = 0;
        }
    } while (condition_holds);
}

void blink() {
    bool state = 0;
    state = !state;
    digitalWrite(LED, state);
    sdelay();
    state = !state;
    digitalWrite(LED, state);
    ldelay();
}

void blinking() {
    do {
        blink();
        // time slicer:
        interstice();
    } while (-1);
}

void setup(void) {
    delay(800);
    Serial.begin(9600);
    Serial.println(ARE_YOU_THERE);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, 1);
    blinking();
    Serial.println("ERROR");
}

void loop(void) {
    // error: program flow should never reach here:
    found_error(); // does not return!
}

// [ https://github.com/wa1tnr/arduino-basics/tree/main/02-blink_LED.d/blink-a ]

// Fri Jul  7 15:39:10 UTC 2023
// END
// bad man put setup way above functions it calls
