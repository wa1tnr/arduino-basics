// Sat 11 Feb 02:54:33 UTC 2023

// dfu-util now accessed as well (st-link was already working)

// arduino-basics/03-serial_print.d/stm32f4.d/stm32f4_print-a/n_sketch_stm32_print.cpp

// stm32f407 discovery - basic blinks arduino ide driven development

#if 0

dfu access, STM32F407VGT6 Discovery

  1. use USB micro-B port (not the usual one for ST-LINK

  2. patch PA9 to 5V (to commute 5v from VBUS at the micro-B connector)
  
  3. strap PB2 to GND

  4. strap B00T0 to VDD 

JP2 and JP3 (unpopulated side of the board) may be borrowed.

Had the two jumpers up top (CN3) disabled for the dfu-util test (open: ST-LINK mode not Discovery mode)

#endif



// END.
