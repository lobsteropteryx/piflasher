#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <wiringPi.h>
#include <wiringSerial.h>

#include "bluetooth.h"

int open_bluetooth_port(char *port, int baud) {
  int fd;
  fd = serialOpen(port, baud);
  return fd;
}


