#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./exception.h"
#include "./game.h"

int status = 0;

int main(void) {
  /*TODO:
   * Change how the funtion receives and returns the status of the exit game
   */
  return (initSDL(status));
}
