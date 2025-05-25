#include "paddle.h"

bool paddleInit(Paddle *p, bool is_player)
{
    if (p == NULL)
    {
        fprintf(stderr, "Paddle pointer is NULL\n");
        return true;
    }
    p->rect.w = 10;
    p->rect.h = 100;
    p->rect.x = is_player ? 20.0f : 770.0f;
    p->rect.y = 250.0f;

    p->keyUp = is_player ? SDL_SCANCODE_W : SDL_SCANCODE_UP;
    p->keyDown = is_player ? SDL_SCANCODE_S : SDL_SCANCODE_DOWN;

    p->speed = 300.0f;
    p->color = is_player ? (SDL_Color){255, 0, 0, 255} : (SDL_Color){0, 0, 255, 255};

    p->is_player = is_player;

    return false;
}