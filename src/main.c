#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./game.h"

int main (int argc, char** argv[]){

        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            fprintf(stderr, "Could not initialize SDL2: %s ", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Window *window = SDL_CreateWindow("Ping Pong",
                                              100, 100,
                                              SCREEN_WIDTH, SCREEN_HEIGHT,
                                              SDL_WINDOW_SHOWN);

        if (window == NULL) {
            fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Renderer *renderer = SDL_CreateRenderer(window, -1,
                                                    SDL_RENDERER_ACCELERATED |
                                                    SDL_RENDERER_PRESENTVSYNC);

        if (renderer == NULL) {
            SDL_DestroyWindow(window);
            fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Surface *surface = IMG_Load("psychic-octo-couscous/resources/ball.png");
        if (surface == NULL) {
            fprintf(stderr, "SDL_CreateSurface Error: %s\n", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (texture == NULL) {
            fprintf("Error creating texture: %s\n", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Rect dest;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        dest.x = (SCREEN_WIDTH - dest.w) / 2;
        float y_pos = SCREEN_HEIGHT;

        bool up = false;
        bool down = false;
        bool quit = false;

        SDL_Event e;

        while (!quit) {

            /*Clears the screen with black*/
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            /*Draws Player One*/
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); /*red color*/

            SDL_Rect player1 = {10, 240/2, 30, 150};
            SDL_RenderFillRect(renderer, &player1);

            /*Draws Player Two*/
            SDL_SetRenderDrawColor(renderer, 44, 62, 80, 1); /*madison color*/

            SDL_Rect player2 = {600, 240/2, 30, 150};
            SDL_RenderFillRect(renderer, &player2);
    
            /*Shows what was drawn*/
            SDL_RenderPresent(renderer);

            while(SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT :
                    quit = true;
                    break;

                    case SDL_KEYDOWN :
                    switch (e.key.keysym.scancode) {
                        case SDL_SCANCODE_W :
                        case SDL_SCANCODE_DOWN :
                        down = true;
                        break;
                    }
                }
            }
        }

        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);

        atexit(SDL_Quit);
        return (EXIT_SUCCESS);
}