#ifndef BALL_H
#define BALL_H

#include "paddle.h"
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct 
{
    SDL_Rect rect;
    float speed;
    float vx, vy;
    float next_vx, next_vy;
    SDL_Color color;
    bool is_waiting;
    float waiting_timer;
} Ball; 

bool ballInit(Ball *b);
void ballUpdate(Ball *b, float dt);
bool ballCheckCollision(Ball *b, Paddle *p);

#endif // BALL_H