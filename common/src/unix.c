#include "common.h"
#include <stddef.h>
#define _POSIX_C_SOURCE 199309L
#include <time.h>
#include <sys/types.h>
#include <string.h>

int sleep(unsigned int milliseconds) {
  struct timespec spec;

  spec.tv_sec = milliseconds / 1000;
  spec.tv_nsec = (__syscall_slong_t)((milliseconds % 1000) * 1000000);

  return nanosleep(&spec, NULL);
}
