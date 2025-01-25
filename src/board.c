#include "./board.h"
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_rect.h>
#include <stdio.h>
#include <stdlib.h>

struct Board_Private {
  SDL_Rect rect;
  SDL_Rect original;
  Window *main_window;
};

static void Draw(Board *, SDL_Surface *);
static void Update(Board *, SDL_Event);

Board *Board_Constructor(Window *window) {
  Board *board = malloc(sizeof(Board));

  board->Draw = Draw;
  board->Update = Update;
  board->_private = malloc(sizeof(Board_Private));

  SDL_Rect rect = {50, 50, 100, 100};
  board->_private->rect = rect;
  board->_private->original = rect;
  board->_private->main_window = window;

  return board;
}

void Draw(Board *this, SDL_Surface *surface) {
  SDL_FillRect(surface, &this->_private->rect,
               SDL_MapRGB(surface->format, 255, 0, 0));
}

void Update(Board *this, SDL_Event event) {
  switch (event.type) {
  case SDL_MOUSEWHEEL:
    float zoom_level = this->_private->main_window->zoom_level;
    SDL_FPoint mouse_pos_normalize = {.x = .0, .y = .0};

    int x, y = 0;
    int width, height = 0;
    SDL_GetMouseState(&x, &y);
    SDL_GetWindowSize(
        this->_private->main_window->Get_Window(this->_private->main_window),
        &width, &height);

    SDL_FPoint rect_pos_normalize = {.x = (float)this->_private->rect.x / width,
                                     .y = (float)this->_private->rect.y /
                                          height};

    mouse_pos_normalize.x = ((float)x / width);
    mouse_pos_normalize.y = ((float)y / height);

    this->_private->rect.w = zoom_level * this->_private->original.w;
    this->_private->rect.h = zoom_level * this->_private->original.h;

    float mouse_dis_center = 0;

    this->_private->rect.y = ;
    this->_private->rect.y = event.wheel.y;
    /* this->_private->rect.x += event.wheel.y; */
    /* this->_private->rect.x += (mouse_pos_normalize.x - rect_pos_normalize.x)
     * * */
    /*                           event.wheel.y * zoom_level; */
    /**/
    /* this->_private->rect.y += (mouse_pos_normalize.y - rect_pos_normalize.y)
     * * */
    /*                           event.wheel.y * zoom_level; */

    printf("mouse x: %f\n", mouse_pos_normalize.x);
    printf("rect nor x: %f\n", rect_pos_normalize.x);
    printf("width x: %d\n", width);
    printf("rect x: %d\n", this->_private->rect.x);
    printf("calculo x: %f\n", (mouse_pos_normalize.x - rect_pos_normalize.x));
    /* this->_private->rect.y += */
    /*     (mouse_pos_normalize.y - rect_pos_normalize.y) * event.wheel.y * -2;
     */

    printf("zoom level: %f\n", zoom_level);
    printf("x: %f\n",
           (mouse_pos_normalize.x - rect_pos_normalize.x) * event.wheel.y);
    printf("y: %f\n", (mouse_pos_normalize.y - rect_pos_normalize.y));
    break;
  };
}

void Board_Desconstructor(Board *this) {
  free(this->_private);
  free(this);
}
