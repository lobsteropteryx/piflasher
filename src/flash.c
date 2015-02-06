
#include <stdio.h>
#include <wiringPi.h>

const int LED_PIN = 8;
const int BUTTON_PIN = 9;

int main(void) {

  wiringPiSetup();

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pullUpDnControl(BUTTON_PIN, PUD_UP);

  digitalWrite(LED_PIN, LOW);

  /*
  while(1) {
    digitalWrite(LED_PIN, LOW);
    delay(500);
    digitalWrite(LED_PIN, HIGH);
    delay(500);
  }
  */

  while(1) {
    if (digitalRead(BUTTON_PIN) ) {
      digitalWrite(LED_PIN, LOW);
    } else {
      digitalWrite(LED_PIN, HIGH);
    }
  }
  return 0;
}




