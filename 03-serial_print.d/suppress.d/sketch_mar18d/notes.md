#### Sat 18 Mar 20:46:14 UTC 2023


Simple demonstration of:


`if (false) Serial.begin(9600);`

How that suppresses inclusion of the hardware serial lib object code,
or some similar idea that lowers the size of the compiled binary in
the Arduino IDE environment.

Savings are significant.


END.
