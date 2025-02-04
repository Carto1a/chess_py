#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define NOCOMM

#include "common.h"
#include <windows.h>
// windows API, don't move
#include <synchapi.h>

int sleep(unsigned int milliseconds) {
  Sleep(milliseconds);
  return 1;
}
