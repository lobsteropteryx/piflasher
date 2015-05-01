#Basic Guide to Microcontroller funtionality using a Raspbery Pi B+ 

The code and schematics here are a demonstration of some of the common functionality on a Raspberry Pi.  The circuit reads and write some simple messages over the USART, and flashes an LED when a message is recieved.  In addition, a pushbutton is attached, which will flash the LED and send a message over the USART when pressed.  The following functions are demonstrated:

- Interrupt on Change (pushbutton)
- Reading and writing over the hardware USART
- And of course, flashing an LED!

This program is written in C and compiled using [gcc](http://gcc.gnu.org).  The program is broken into modules, roughly corresponding to individual hardware functions.  The hardware interfacing is done via the [wiringpi](http://www.wiringpi.com) library, which maps Arduino wiring commands onto the Pi.  It's easy to build directly on the Pi, following the [guide](http://www.wiringpi.com/download-and-install).

#Bill of Materials
- [Raspberry Pi B+](https://raspberrypi.org/products/model-b-plus)
- [HC-06](http://abc-rc.pl/templates/images/files/995/1425483439-hc-06-datasheet.pdf)
- 330 ohm resistor
- LED
- Momentary pushbutton

The Pi itself is powerered from a standard USB supply, and the 5V rail from the GPIO header is used to power the HC-06.

#Schematic
![schematic](https://github.com/lobsteropteryx/piflasher/blob/master/piflasher.schematic.svg)


