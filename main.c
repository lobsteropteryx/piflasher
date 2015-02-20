#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include <wiringPi.h>
#include "flash.h"
#include "button.h"

// Broadcom numbering
const int LED_PIN = 2;
const int BUTTON_PIN = 3;
static bool KEEP_RUNNING = true;


void handle_button_press(void) {
  int flashes = 4;
  printf("Received button press.\n");
  flash_led(LED_PIN, flashes);
}


void handle_SIGINT(int signal) {
  printf("\nInterrupt caught. Shutting down.\n");
  KEEP_RUNNING = false;
}


void setup(void) {
  wiringPiSetupGpio();
  wiringPiISR(BUTTON_PIN, INT_EDGE_FALLING, &handle_button_press);
  signal(SIGINT, handle_SIGINT);
  setup_led(LED_PIN);
  setup_button(BUTTON_PIN);
}


void cleanup(void) {
  cleanup_button(BUTTON_PIN);
  cleanup_led(LED_PIN);
}


int main(void) {
  setup();
  printf("This battle station is fully operational.\n");
  while(KEEP_RUNNING) {
    sleep(1);
  }
  cleanup();
  printf("SEE YOU, SPACE COWBOY.\n");
  return 0;
}
