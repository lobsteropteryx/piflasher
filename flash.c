#include <unistd.h>
#include <wiringPi.h>

const int LED_PIN = 2;
const int BUTTON_PIN = 3;

void flash(int num_flashes) {
  int i;
  for (i = 0; i < num_flashes; i++) {
    delay(100);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
}

void handle_interrupt(void) {
    flash(4);
}

int main(void) {

  //Use Broadcom numbering
  wiringPiSetupGpio();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pullUpDnControl(BUTTON_PIN, PUD_UP);

  digitalWrite(LED_PIN, LOW);

  wiringPiISR(BUTTON_PIN, INT_EDGE_FALLING, &handle_interrupt);

  while (1) {
    sleep(1);
  }

  return 0;
}
