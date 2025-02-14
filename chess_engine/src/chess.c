#include "chess/chess.h"
#include <assert.h>
#include <stdarg.h>
#include <stdio.h>

#ifdef WIN32
#include <vadefs.h>
#endif

static char error_message[512] = {0};

void chess_set_error(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  // NOTE: tenho que ver melhor oque isso faz.
  int write_size = vsnprintf(error_message, sizeof(error_message), fmt, args);
  assert(expr)
  va_end(args);
}

const char *chess_get_error() { return error_message; }
