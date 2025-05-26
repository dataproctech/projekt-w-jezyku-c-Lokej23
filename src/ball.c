#include "ball.h"
#include "game.h"
#include "main.h"
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

void ballUpdate(Ball *b, float dt)
{
    b->rect.x += b->vx * dt;
    b->rect.y += b->vy * dt;

    if (b->rect.y <= 0 || b->rect.y >= SCREEN_HEIGHT - b->rect.h)
        b->vy = -b->vy;
}

bool ballCheckCollision(Ball *b, Paddle *p)
{
    if (b == NULL || p == NULL)
        return false;

    if (b->rect.x < p->rect.x + p->rect.w &&
        b->rect.x + b->rect.w > p->rect.x &&
        b->rect.y < p->rect.y + p->rect.h &&
        b->rect.y + b->rect.h > p->rect.y)
    {
        float og_direction = b->vx;
        b->vx = -b->vx;

        // odbijanie od paletki
        if (og_direction > 0)
            b->rect.x = p->rect.x - b->rect.w;
        else
            b->rect.x = p->rect.x + p->rect.w;

        // zwiększenie prędkości
        b->speed *= 1.05f;
        if (b->speed > 700.0f)
            b->speed = 700.0f; // maksymalna prędkość

        return true;
    }

    return false;
}