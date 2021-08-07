// avr - 16 MHz 5V 32u4 ItsyBitsy from Adafruit is test platform 07 August 2021 14:06z
bool bbb;
int countdown;
int timestamped; // hope millis likes this
void setup() {
    Serial.begin(115200);
    while(!Serial); delay(999);
    bbb = -1; // TRUE
    countdown++; // initialize
}
bool dothing() {
    if (bbb) {
        bbb = 0; // falsify it
        timestamped = millis();
        return 1;
    }
    Serial.println("bbb was false!");
    timestamped = millis();
    bbb = -1; // make it true
    return 0;
}
void cruftlooped() { }
void loop() {
    while(dothing());
    Serial.print("Did thing: ");
    Serial.println(timestamped);
    // bbb = 0; // false
    delay(999);
    countdown++;
    if (countdown > 5) { countdown = 0; cruftlooped(); }
}
// END.
