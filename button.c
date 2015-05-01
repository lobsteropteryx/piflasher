#include <wiringPi.h>
#include "button.h"

void setup_button(int pin) {
  pinMode(pin, INPUT);
  pullUpDnControl(pin, PUD_UP);
}


void cleanup_button(int pin) {
  pullUpDnControl(pin, PUD_OFF);
}
