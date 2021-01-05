// blink-avr-a.ino
// Tue Jan  5 21:31:50 UTC 2021
// ItsyBitsy 32u4 5V 16 MHz

// was:
// blink-a.ino
// Sat Jan  2 05:35:02 UTC 2021
// Feather M0 Express

#define SDELAY 4
#define SDELAYR 1200
#define LDELAY 4000
#define LDELAYR 400
#define LED 13 // D13

void found_error(void) {
    for (int i = 5; i > 0; i--) {
        digitalWrite(LED, 1); delay(SDELAY);
        digitalWrite(LED, 0); delay(SDELAYR);
    }
    for (int i = 5; i > 0; i--) {
        digitalWrite(LED, 1); delay(LDELAY);
        digitalWrite(LED, 0); delay(LDELAYR);
    }
    do {
        digitalWrite(LED, 1); delay((SDELAY / 4));
        digitalWrite(LED, 0); delay((SDELAYR / 8));
    } while (-1); // loop forever 'do-while, forever'
}

void setup(void) {
    pinMode(LED, OUTPUT);
    digitalWrite(LED, 1); delay(1000);
    digitalWrite(LED, 0); delay(1000);
    digitalWrite(LED, 1); delay(1000);
    digitalWrite(LED, 0); delay(1000);
}

void loop(void) {
    bool state = 0;
    int j = millis();
    do {
        int k = millis();
        if ((k - j) > 200) {
            state = !state;
            digitalWrite(LED, state);
            j = k;
        }
    } while (-1);
    // error: program flow should never reach here:
    found_error(); // does not return!
}
// END.
