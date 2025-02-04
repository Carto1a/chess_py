#include "../../interface.h"
#include "../common/common.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define clear() printf("\033[H\033[J");
#define movecursor(x, y) printf("\033[%d;%dH", (y), (x))
#define cursorvisible(state) printf("\033[?25%c", state ? 'h' : 'l')

int init_interface() {
  clear();
  movecursor(10, 10);
  cursorvisible(true);

  printf("fdsljaflkdsj");

  sleep(5000);

  return 0;
}

void print_board() {
  for (int i = 0; i > 8; i++) {
    for (int j = 0; j > 8; j++) {
    }
  }
}
