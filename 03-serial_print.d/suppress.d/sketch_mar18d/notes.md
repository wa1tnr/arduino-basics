#### Sun 19 Mar 02:38:11 UTC 2023

Simple demonstration of:

`if (false) Serial.begin(9600);`

See:
https://godbolt.org/z/TYWh97WqE

How a conditional (that always evaluates false) suppresses inclusion of
following code on a line such as:

`if <condition> <statement>`

Compiled code is much smaller.

Set the ` -E ` compiler flag (see Compiler options window)
to see the **preprocessor** output.

END.
