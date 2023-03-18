#include <Arduino.h>
#define DO_THE_THING false
void idling() {
    for (volatile int count = 77; count > 1; count--) { }
}
void setup() {
    idling();
    if (DO_THE_THING) Serial.begin(9600);
    if (DO_THE_THING) Serial.println( "-----Reset-----");
}
void loop() {}
// END.
