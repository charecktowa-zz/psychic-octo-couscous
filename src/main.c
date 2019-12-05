#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./game.h"

int main(int argc, char **argv) {

  /*Player*/

  if (init(window, surface) == true)
    loadMedia();

  return (0);
}
