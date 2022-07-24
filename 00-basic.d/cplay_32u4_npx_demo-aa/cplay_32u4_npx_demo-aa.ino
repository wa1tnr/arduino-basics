// Demo program for testing library and board - flip the switch to turn on/off buzzer

#include <Adafruit_CircuitPlayground.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;
uint8_t pixelwhl = 3;

#define INTENSITY 1 // 8 bits

void setup() {
  Serial.begin(9600);
  Serial.println("Circuit Playground test!");

  CircuitPlayground.begin();
  CircuitPlayground.setBrightness(INTENSITY);
}


void loop() {
  uint16_t raw_millis = 0;
  raw_millis = millis();
  bool expired = 0;
  do {
    uint16_t result = ( millis() - raw_millis);
    if (result > 22 ) // 655) 
        { expired = -1; }
  } while (! expired);

  // turn off speaker when not in use
  CircuitPlayground.speaker.enable(false);


#ifdef BLINKENRED
  // test Red #13 LED
  CircuitPlayground.redLED(HIGH);
  delay(100);
  CircuitPlayground.redLED(LOW);
#endif

  /************* TEST CAPTOUCH */
  Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3));
  Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2));
  Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0));
  Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));
  delay(10);

  /************* TEST SLIDE SWITCH */
  if (CircuitPlayground.slideSwitch()) {
    Serial.println("Slide to the left");
  } else {
    Serial.println("Slide to the right");
    CircuitPlayground.speaker.enable(true);
    CircuitPlayground.playTone(500 + pixeln * 500, 100);
  }
  delay(10);

  /************* TEST 10 NEOPIXELS */
  pixelwhl++; pixeln++ ; pixeln++ ; pixeln++; pixeln++ ; pixeln++ ;
  if (pixeln == 11) { pixeln = 0; }
  if (pixeln == 12) { pixeln = 1; }
  if (pixeln == 13) { pixeln = 2; }

  // strip will signal missing pixels as if they were present

#if 0
  if (pixeln == 14) { pixeln = 3; }
  if (pixeln == 15) { pixeln = 4; }
  if (pixeln == 16) { pixeln = 5; }
  if (pixeln == 17) { pixeln = 6; }
#endif

  CircuitPlayground.setPixelColor(pixeln, CircuitPlayground.colorWheel( ((25 * pixelwhl) & 0xFF)));

    // CircuitPlayground.clearPixels();
  delay(10);

  /************* TEST BOTH BUTTONS */
  if (CircuitPlayground.leftButton()) {
    Serial.println("Left button pressed!");
  }
  if (CircuitPlayground.rightButton()) {
    Serial.println("Right button pressed!");
  }
  delay(10);

  /************* TEST LIGHT SENSOR */
  Serial.print("Light sensor: ");
  Serial.println(CircuitPlayground.lightSensor());
  delay(10);

  /************* TEST SOUND SENSOR */
  Serial.print("Sound sensor: ");
  Serial.println(CircuitPlayground.mic.soundPressureLevel(10));
  delay(10);

  /************* TEST ACCEL */
  // Display the results (acceleration is measured in m/s*s)
  Serial.print("X: "); Serial.print(CircuitPlayground.motionX());
  Serial.print(" \tY: "); Serial.print(CircuitPlayground.motionY());
  Serial.print(" \tZ: "); Serial.print(CircuitPlayground.motionZ());
  Serial.println(" m/s^2");
  delay(10);

  /************* TEST THERMISTOR */
  Serial.print("Temperature ");
  Serial.print(CircuitPlayground.temperature());
  Serial.println(" *C");
}
