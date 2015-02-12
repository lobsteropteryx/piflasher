#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <unistd.h>

#include <wiringPi.h>

// Broadcom numbering
const int LED_PIN = 2;
const int BUTTON_PIN = 3;
static bool KEEP_RUNNING = true;


void handle_button_press(void);
void flash_led(int);
void handle_SIGINT(int);
void setup(void);
void cleanup(void);


int main(void) {
  setup();

  wiringPiISR(BUTTON_PIN, INT_EDGE_FALLING, &handle_button_press);
  signal(SIGINT, handle_SIGINT);

  printf("Waiting for button presses. (Ctrl+C to exit.)\n");
  while (KEEP_RUNNING) {
    sleep(1);
  }

  cleanup();
  printf("SEE YOU SPACE COWBOY.\n");
  return 0;
}

void setup(void) {
  wiringPiSetupGpio();
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pullUpDnControl(BUTTON_PIN, PUD_UP);

  digitalWrite(LED_PIN, LOW);
}


void handle_button_press(void) {
  printf("Received button press.\n");
  flash_led(4);
}


void flash_led(int num_flashes) {
  int i;
  for (i = 0; i < num_flashes; i++) {
    delay(100);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
}


void handle_SIGINT(int signal) {
  printf("\nInterrupt caught. Shutting down.\n");
  KEEP_RUNNING = false;
}


void cleanup(void) {
  pinMode(LED_PIN, INPUT);
  pullUpDnControl(BUTTON_PIN, PUD_OFF);
}
