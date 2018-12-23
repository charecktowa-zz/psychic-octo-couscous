#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "./game.h"

/**/ 

int main (void){

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

        /*add a bigger ball to the game*/
        SDL_Surface *surface = IMG_Load("resources/ball.png");
        if (surface == NULL) {
            fprintf(stderr, "SDL_CreateSurface Error: %s\n", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (texture == NULL) {
            fprintf(stderr, "Error creating texture: %s\n", SDL_GetError());
            return (EXIT_FAILURE);
        }

        SDL_Rect dest;
        SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
        dest.w /= 4;
        dest.h /= 4;

        /*starts sprite in the center of the screen*/
        float x_pos = (SCREEN_WIDTH - dest.w) / 2;
        float y_pos = (SCREEN_HEIGHT - dest.h) / 2;

        float x_vel = SPEED;
        float y_vel = SPEED;

        bool up = false;
        bool down = false;
        bool quit = false;

        SDL_Event e;

        while (!quit) {

            /*Clears the screen with black*/
            SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            SDL_RenderClear(renderer);

            /*Collision of the ball*/
            if (x_pos <= 0) {
                x_pos = 0;
                x_vel = -x_vel;
            }

            if (y_pos <= 0) {
                y_pos = 0;
                y_vel = -y_vel;
            }

            if (x_pos >= SCREEN_WIDTH - dest.w) {
                x_pos = SCREEN_WIDTH - dest.w;
                x_vel = -x_vel;
            }

            if (y_pos >= SCREEN_HEIGHT - dest.h) {
                y_pos = SCREEN_HEIGHT - dest.h;
                y_vel = -y_vel;
            }

            /*update positions*/
            x_pos += x_vel / 60;
            y_pos += y_vel / 60;

            /*set positions in the struct*/
            dest.y = (int) y_pos;
            dest.x = (int) x_pos;

            SDL_RenderCopy(renderer, texture, NULL, &dest);

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
            SDL_Delay(1000/60);

            while(SDL_PollEvent(&e)) {
                switch (e.type) {
                    case SDL_QUIT :
                    quit = true;
                    break;

                    case SDL_KEYDOWN :
                        switch (e.key.keysym.scancode) {
                            case SDL_SCANCODE_W :
                            down = true;
                            break;

                            case SDL_SCANCODE_S :
                            up = true;
                            break;
                        }
                    break;
                    case SDL_KEYUP:
                        switch (e.key.keysym.scancode) {
                            case SDL_SCANCODE_W:
                            up = false;
                            break;

                            case SDL_SCANCODE_S:
                            down = false;
                            break;                            
                        }                  
                        break;   
                }
            }

            /*determine velocity*/

        }

        SDL_DestroyWindow(window);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyTexture(texture);

        atexit(SDL_Quit);
        return (EXIT_SUCCESS);
}
