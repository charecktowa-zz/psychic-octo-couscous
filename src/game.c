#include "./game.h"

bool init(SDL_Window *window, SDL_Surface *surface, int *status) {
  bool state = true;

  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    fprintf(stderr, "Could not initialize SDL: %s!\n", SDL_GetError());
    *status = VIDEO_INIT;
    state = false;
  } else {
    /* Creates the window */
    window = SDL_CreateWindow("Ping Pong", SDL_WINDOWPOS_CENTERED,
                              SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                              SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (!window) {
      fprintf(stderr, "Error while creating window: %s!\n", SDL_GetError());
      *status = WINDOW_INIT;
      state = false;
    } else {
      surface = SDL_GetWindowSurface(window);
    }
  }

  return state;
}

bool loadMedia(SDL_Surface *player, int *status) {
  bool state = true;

  /* try to load the images */
  player = SDL_LoadBMP("somepath");

  if (!player) {
    fprintf(stderr, "Could not load player asset: %s\n", SDL_GetError());
    *status = ASSET_LOAD;
    state = false;
  }

  return state;
}
