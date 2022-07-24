#define DATE_STAMP "Fri Aug 20 04:54:49 UTC 2021"
#define PPSHRED "  77i-iv-32u4-5v-16mhz"
// also tested fine ItsyBitsy RP2040
// ./some/path/to/arduino-1.8.15/examples/01.Basics/BareMinimum/BareMinimum.ino

void init_gpio(void) {
    pinMode(LED_BUILTIN, 1);
    digitalWrite(LED_BUILTIN, 0);
}

void cpl(int pin) {
    bool state = digitalRead(pin);
    state = !state;
    digitalWrite(pin, state);
}

#define BLINK_LONG 3000
#define BLINK_SHORT  30

void blink(void) {
    cpl(LED_BUILTIN);
    delay(BLINK_SHORT);
    cpl(LED_BUILTIN);
    delay(BLINK_LONG);
}

void init_serial(void) {
    Serial.begin(115200);
    while (!Serial) {
        blink();
    }
    Serial.println("\n" DATE_STAMP PPSHRED);
}

void setup(void) {
    init_gpio();
    init_serial();
}

void loop(void) {
    while (-1);
    Serial.println("ERROR .. loop fall-thru.");
}

// END.
