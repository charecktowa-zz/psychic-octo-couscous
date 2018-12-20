#include <SDL2/SDL.h>

#include "main.h"

#include <stdio.h>
#include <stdlib.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
int main(int argc, char *argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        fprintf(stderr, "Could not initialize sdl2: %s", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("Ping Pong",
                                          100, 100,
                                          SCREEN_WIDTH, SCREEN_HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if (window == NULL) {
        fprintf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                SDL_RENDERER_ACCELERATED |
                                                SDL_RENDERER_PRESENTVSYNC);

    if (renderer == NULL) {
        SDL_DestroyWindow(window);
        fprintf(stderr, "SDL_createRenderer Error: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Event e;

    int quit = 0;
    while(!quit) {
        while(SDL_PollEvent(&e)){
            switch (e.type) {
                case SDL_QUIT:
                quit = 1;
                break;
            
            default: {}
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }

        SDL_DestroyWindow(window);
        SDL_Quit();

        return EXIT_SUCCESS;
}