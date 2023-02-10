#define SER_MSG "Fri 10 Feb 00:36:53 UTC 2023"

#define BLINK_ITER 111

// initial testing for git-hosted code

// arduino-basics/03-NEW_SERIAL_CONN_print.d/stm32f4.d/stm32f4_print-a/n_sketch_stm32_print.cpp

// stm32f407 discovery - basic blinks arduino ide driven development

//  reasonable bounds on initializing the port pins in a for loop construct. ;)

//  st-flash  write  sketch_feb09a.ino.bin  0x08000000
//  st-flash  reset

#include <Arduino.h>

#define TESTING 5 // maximum: 5  minimum: 0

// #define NEW_SERIAL_CONN SerialUSB
#define NEW_SERIAL_CONN SerialUSB

// board edge:
const int EDGE_GREEN = PA_9;
const int EDGE_RED   = PD_5;

// cluster:
const int GREEN  = PD_12;
const int ORANGE = PD_13;
const int RED    = PD_14;
const int BLUE   = PD_15;

const int memory[] = { EDGE_GREEN, EDGE_RED, GREEN, ORANGE, RED, BLUE };

const int memMAX = 6 - 1; // number of elements in array, zero-referenced

const int SELECTED_TEST_PIN = TESTING;
const int thisPIN = memory[SELECTED_TEST_PIN]; // selects LED

const int ON_TIME = 4 ; // milliseconds
const int OFF_TIME = 1400;


void cpl(int gpio_pin) { // toggle
  bool state = digitalRead(gpio_pin);
  state = !state;
  digitalWrite(gpio_pin, state);
}


void blink() {
  cpl(thisPIN);
  delay(ON_TIME);
  cpl(thisPIN);
  delay(OFF_TIME);
}


void gpio_setup() {
  int count = memMAX + 1;
  for (int nowPIN = 0; nowPIN < count; nowPIN++) {
    pinMode(memory[nowPIN], 1); // output
  }
  digitalWrite(thisPIN, 0);
  cpl(EDGE_RED);
}


void serial_setup() {
  NEW_SERIAL_CONN.begin(9600);
}


void print_message() {
  NEW_SERIAL_CONN.println(SER_MSG);
  delay(500);
}

#define PRINT_ITER 1 // how many times the message prints consecutively

void logon_message() {
// int iterations = PRINT_ITER ;
  if (PRINT_ITER > 1) {
    for (int index = PRINT_ITER; index > 0; index--) {
      print_message();
    }
  }
  if (PRINT_ITER == 1) {
    print_message();
  }
}

#define WANT_LOGON
#ifdef WANT_LOGON
  const int WANTED_LOGON = -1;
#endif
#ifndef WANT_LOGON
  const int WANTED_LOGON = 0;
#endif


void setup() {
  delay(800);
  gpio_setup();
  serial_setup();
  int blinks = BLINK_ITER ;
  for (int i = blinks; i > 0; i--) {
    blink();
    if (WANTED_LOGON) { logon_message(); }
  }
}

void loop() {
  // empty
}

// END.
