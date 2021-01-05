README.md  for blink-a.ino

Tue Jan  5 21:31:50 UTC 2021

Current target: ItsyBitsy 32u4 5V 16 MHz

Copied from one directory level up for this version
of blink-a.ino (now named blink-avr-a.ino).

Just in case there's a need for differentiation
(blink-a.ino designed for Feather M0 Expresds
(a SAMD21 target board).


02 January 2021

The program demonstrates that a bool(ean) can be
passed, directly, as an argument to digitalWrite().

It shows how there can be a finite time interval
between events, without blocking - by using
millis() instead of the more pedestrian delay().

The program also shows the syntax to negate a boolean:

  state = !state;
  digitalWrite(LED, state);

This program makes use of a 'do .. while' loop within
the main (Arduino required) loop().

Using while() in this way, as a test at the end of
the loop, for a condition; here it is set to
always true (-1).

Since 1111 1111 as a signed 8-bit integer is the
representation for '-1' this makes good sense.
