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
    SDL_Color color;
} Ball; 

bool ballInit(Ball *b);
void ballUpdate(Ball *b, float dt);
bool ballCheckCollision(Ball *b, Paddle *p);

#endif // BALL_H