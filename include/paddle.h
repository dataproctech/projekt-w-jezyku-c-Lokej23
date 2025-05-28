#ifndef PADDLE_H
#define PADDLE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct
{
    SDL_Rect rect;
    SDL_Scancode keyUp;
    SDL_Scancode keyDown;
    float speed;
    SDL_Color color;
    bool is_left;
} Paddle;

bool paddleInit(Paddle *p, bool is_left);
void paddleUpdate(Paddle *p, const Uint8 *keystate, float dt);

#endif // PADDLE_H