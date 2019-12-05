#ifndef _GAME_H_
#define _GAME_H_

#include <SDL2/SDL.h>

#include <stdbool.h>
#include <stdio.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

/* Depending on the game state will display diferent windows */
enum GAME_STATE { RUNNING, PLAYER_X_WON, PLAYER_Y_WON, TIME_OUT };

SDL_Window *window = NULL;
SDL_Surface *surface = NULL;

/* function prototypes */
bool init(SDL_Window *window, SDL_Surface *surface);
bool loadMedia();
void closeResources(bool state);

#endif
