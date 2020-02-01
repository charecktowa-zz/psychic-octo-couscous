#ifndef _GAME_H
#define _GAME_H

#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* This header tries to handle properly any error that could happen */
#include "./exception.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int exception_type;

bool drawRender(SDL_Window *window);
bool createWindow(void);
bool initSDL(int status);

#endif
