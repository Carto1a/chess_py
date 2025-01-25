#include "./window.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_surface.h>

typedef struct Board_Private Board_Private;

typedef struct Board {
  void (*Draw)(struct Board *, SDL_Surface *);
  void (*Update)(struct Board *, SDL_Event event);
  Board_Private *_private;
} Board;

Board *Board_Constructor(Window *);
void Board_Desconstructor(Board *);
