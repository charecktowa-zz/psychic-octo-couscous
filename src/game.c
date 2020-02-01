#include "./game.h"

bool drawRender(SDL_Window *window) {
  SDL_Surface *screenSurface = NULL;

  /* Gets the surface from the specified window
   * It;
   */
  screenSurface = SDL_GetWindowSurface(window);
  fprintf(stdout, "Drawing Render!\n");

  if (screenSurface = NULL) {
    exception_type = RENDER_FAILED;
    exceptionHandler(exception_type);
  } else {
    SDL_Delay(2000);
  }

  return exception_type;
}

bool createWindow(void) {

  SDL_Window *window = NULL;

  window = SDL_CreateWindow("Ping Pong", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT,
                            SDL_WINDOW_SHOWN);

  if (window == NULL) {
    exception_type = WINDOW_CREATION_ERROR;
    exceptionHandler(exception_type);
  } else {
    fprintf(stdout, "Window created correctly.\n");

    drawRender(window);
  }
  return (exception_type);
}

/* Initialize SDL, and then calls another functions to
   create the window                                     */
bool initSDL(int status) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    exception_type = VIDEO_ERROR;
    status = exception_type;
    exceptionHandler(exception_type);
  } else {
    /*If the SDL video inits, then starts creating the window*/
    createWindow();
  }

  return (status);
}
