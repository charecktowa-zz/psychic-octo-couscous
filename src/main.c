#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./game.h"

int main(int argc, char **argv) {
  int status; //
  SDL_Window *window = NULL;
  SDL_Surface *surface = NULL;
  /*Player*/

  if (init(window, surface, &status) == true)
    loadMedia(); // loads the image for the thing

  // perdón Diosito por usar goto.
  else {
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
    default:
      break; // I do not really know
    }
  }

normal: // Should end normally closing everything

windowErr:
  SDL_DestroyWindow(window);

videoErr: // should close only SDL
  SDL_Quit();
}
