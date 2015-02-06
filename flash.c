#include <stdio.h>
#include <wiringPi.h>

const int LED_PIN = 8;
const int BUTTON_PIN = 9;

void flash(int num_flashes) {
  int i;
  for (i = 0; i < num_flashes; i++) {
    delay(100);
    digitalWrite(LED_PIN, HIGH);
    delay(100);
    digitalWrite(LED_PIN, LOW);
  }
}

int main(void) {

  wiringPiSetup();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pullUpDnControl(BUTTON_PIN, PUD_UP);

  digitalWrite(LED_PIN, LOW);

  while(1) {
    if (digitalRead(BUTTON_PIN) == 0) {
      flash(4);
    }
  }
  return 0;
}
