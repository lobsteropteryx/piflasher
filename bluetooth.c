#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

#include <wiringPi.h>
#include <wiringSerial.h>

int main(void) {
  int fd;

  if ((fd = serialOpen("/dev/ttyAMA0", 9600)) < 0) {
    fprintf (
      stderr,
      "Unable to open serial device: %s\n",
      strerror(errno)
    );
    return 1;
  }

  printf("This battlestation is fully operational.\n");

  while (1) {
    sleep(500);
    serialPuts(fd, "Sending out an S.O.S. to the world.");
  }

  return 0;
}
