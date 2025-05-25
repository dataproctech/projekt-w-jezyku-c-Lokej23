#include "ball.h"
#include <time.h>

bool ballInit(Ball *b)
{
    if (b == NULL)
    {
        fprintf(stderr, "Ball pointer is NULL\n");
        return true;
    }
    b->rect.w = 10; // szerokość i wysokośc piłki
    b->rect.h = 10;
    b->rect.x = 395.0f; // pozycja na ekranie
    b->rect.y = 295.0f; 

    b->speed = 350.0f;

    srand((unsigned)time(NULL));
    int dirx = rand() % 2 ? 1 : -1;
    int diry = rand() % 2 ? 1 : -1;
    b->vx = dirx * b->speed;
    b->vy = diry * (b->speed / 2.0f); // aby było ukośnie

    b->color = (SDL_Color){255, 255, 255, 255};

    return false;
}