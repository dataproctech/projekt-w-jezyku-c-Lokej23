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

    // oczekiwanie
    b->is_waiting = true;
    b->waiting_timer = 0.5f;
    b->vx = 0; // prędkość w czasie czekania
    b->vy = 0;

    srand((unsigned)time(NULL));
    int dirx = rand() % 2 ? 1 : -1;
    int diry = rand() % 2 ? 1 : -1;
    b->next_vx = dirx * b->speed;
    b->next_vy = diry * (b->speed / 2.0f); // aby było ukośnie

    b->color = (SDL_Color){255, 255, 255, 255};

    return false;
}

void ballUpdate(Ball *b, float dt)
{
    if (b->is_waiting)
    {
        b->waiting_timer -= dt;
        if (b->waiting_timer <= 0)
        {
            // wystrzelenie piłki
            b->is_waiting = false;
            b->vx = b->next_vx;
            b->vy = b->next_vy;
        }
        return; // brak aktualizacji pozycji podczas czekania
    }
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
        b->speed *= 1.15f;
        if (b->speed > 1000.0f)
            b->speed = 1000.0f; // maksymalna prędkość

        return true;
    }

    return false;
}