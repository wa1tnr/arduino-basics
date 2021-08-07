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

void cruftlooped() {
    bbb = 0;
}

bool dothing() {
    bbb = -1;
    countdown++;
    if (countdown > 5) {
        countdown = 0;
        cruftlooped();
    }
    if (bbb) {
        Serial.print("bbb was true! ");
        timestamped = millis();
        Serial.println(timestamped);
        delay(800);
        return 1;
    }
    Serial.print("bbb was false! ");
    timestamped = millis();
    Serial.println(timestamped);
    delay(800);
    return 0;
    Serial.println("Fall-thru case.  ERROR.");
}

void loop() {
    while(dothing()); // loop forever until dothing() returns false
    Serial.print("Did thing: ");
    Serial.println(timestamped);
    delay(999);
    // Note how 'Did thing:' message means
    // the loop started over
    // and got past the 'dothing()' function
}
// END.
