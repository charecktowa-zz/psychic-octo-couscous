#ifndef GAME_H_
#define GAME_H_

#define SCREEN_WIDTH (640)
#define SCREEN_HEIGHT (480)

#define RUNNING_STATE (0)
#define GAME_OVER (1)

#define SPEED (300)

#define PI 3.141592653

struct Circle {
        int radius;
        int h;
        int k;
        int new_x;
        int new_y;
        int old_x;
        int old_y;
        float step;
}circle;

#endif
