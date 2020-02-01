#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./exception.h"
#include "./game.h"

int status = 0;

int main(void) {
        return (initSDL(status));
}
