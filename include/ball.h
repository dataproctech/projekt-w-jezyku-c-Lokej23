#ifndef BALL_H
#define BALL_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct 
{
    SDL_Rect rect;
    float vel;
} Ball; 

bool ballInit(Ball *b);
void ballUpdate(Ball *b, float dt);


#endif // BALL_H