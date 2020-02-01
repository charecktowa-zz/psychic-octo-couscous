#include "./exception.h"
#include "./game.h"

void SDL_INIT_Error() {
  fprintf(stderr, "Could not initialize video, %s\n", SDL_GetError());
  SDL_Quit();
}

void SDL_WINDOW_Error() {
  fprintf(stderr, "Could not create the window, %s!\n", SDL_GetError());
  SDL_Quit();
}

/* The function receives a value and then knows which
   function will hanlde the error properly */
void exceptionHandler(int exception) {
  switch (exception) {
  case SDL_ERROR:
    SDL_INIT_Error();
    break;

  case WINDOW_CREATION_ERROR:
    SDL_WINDOW_Error();
    break;
  }
}
