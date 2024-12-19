# GT911 Library

This is a library for the GT911 capacitive touch screen

Modified by R Petrilak For the Waveshare ESP32 Touch 4.3B Board

Initial Library Version = 1.0.2
Removed the Reset and Interrupt from the reset routine as they are handled
outside of this library using an I2C IO Expander instead of the Digital IO pins of the ESP32.

Also removed the Wire.begin from the constructor as Wire will be started in the Setup. Probably
should check instead if it has already been started and start if necessary.

