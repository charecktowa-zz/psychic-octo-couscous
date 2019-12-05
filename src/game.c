#include "./game.h"

bool init(SDL_Window *window, SDL_Surface *surface) {
  bool state = true;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Could not initialize SDL: %s!\n", SDL_GetError());
    state = false;
    closeResources(state);
  } else {
    /* Creates the window */
    window = SDL_CreateWindow("Ping Pong", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
      fprintf(stderr, "Error while creating window: %s!\n", SDL_GetError());
      state = false;
      closeResources(state);
    } else {
      surface = SDL_GetWindowSurface(window);
    }
  }

  return state;
}

bool loadMedia(void) {
  bool state = true;

  /* try to load the images */

  return state;
}

void closeResources(bool state) {
  fprintf(stdout, "Closing resources...\n");
  SDL_Quit();

  /* Depending of the state it will exit with 0 or 1 */
  state ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}
