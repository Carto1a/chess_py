#include "common.h"
#include <sys/types.h>
#include <time.h>

int sleep(unsigned int milliseconds) {
  struct timespec spec;

  if (milliseconds <= 999) {
    spec.tv_nsec = milliseconds * 1000000;
  } else {
    spec.tv_sec = milliseconds / 1000;
  }

  return nanosleep(&spec, NULL);
}
