#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./game.h"

int main(int argc, char **argv) {
  int status; //
  SDL_Window *window = NULL;
  SDL_Surface *surface = NULL;

  if (init(window, surface, &status) == true)
    loadMedia(surface, &status); // loads the image for the thin

  // perdón Diosito por usar goto.
  switch (status) {
  case NORMAL_EXIT:
    goto normal;
    break;
  case VIDEO_INIT:
    goto videoErr;
    break;
  case WINDOW_INIT:
    goto windowErr;
    break;
  case ASSET_LOAD:
    goto windowErr;
    break;
  default:
    break; // I do not really know
  }

  printf("%i\n", status);

  /*Here, all the stuff should load normally, so we can start the game*/
  SDL_Event e;
  bool running = true;

  while (running) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT)
        running = false;
    }
  }

normal: // Should end normally closing everything

windowErr:
  SDL_DestroyWindow(window);

videoErr: // should close only SDL
  SDL_Quit();

  exit(EXIT_SUCCESS);
}
