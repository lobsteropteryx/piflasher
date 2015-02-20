#include <wiringPi.h>
#include "flash.h"

void setup_led(int pin) {
  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
}


void flash_led(int pin, int num_flashes) {
  int i;
  for (i = 0; i < num_flashes; i++) {
    delay(100);
    digitalWrite(pin, HIGH);
    delay(100);
    digitalWrite(pin, LOW);
  }
}


void cleanup_led(int pin) {
  pinMode(pin, INPUT);
}

