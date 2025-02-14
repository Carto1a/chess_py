#include <SDL2/SDL_video.h>
#include <stdbool.h>

typedef struct Window_Private Window_Private;

typedef struct Window {
  void (*Draw)(struct Window *);
  void (*Process_Events)(struct Window *);
  bool (*Is_Running)(struct Window *);
  float zoom_level;
  SDL_Window *(*Get_Window)(struct Window *);
  SDL_Surface *(*Get_Sufece)(struct Window *);
  Window_Private *_private;
} Window;

Window *Window_Construct();
void Window_Desconstruct(Window *);
