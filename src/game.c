#include "game.h"
#include "main.h"

bool gameInit(Game *g, int max_score)
{
    if (g == NULL)
    {
        fprintf(stderr, "Error, Game pinter is NULL\n");
        return true;
    }
    if (paddleInit(&g->paddle_1, true))
    {
        fprintf(stderr, "Error initializing player_1 paddle\n");
        return true;
    }
    if (paddleInit(&g->paddle_2, false))
    {
        fprintf(stderr, "Error initializing player_2 paddle\n");
        return true;
    }
    if (ballInit(&g->ball))
    {
        fprintf(stderr, "Error intializing ball\n");
        return true;
    }

    g->score_1 = 0;
    g->score_2 = 0;
    g->max_score = max_score;
    g->game_over = false;

    return false;
}

void gameUpdate(Game *g, const Uint8 *keystate, float dt)
{
    if (g->game_over)
        return;

    paddleUpdate(&g->paddle_1, keystate, dt);
    paddleUpdate(&g->paddle_2, keystate, dt);
    ballUpdate(&g->ball, dt);
    if (ballCheckCollision(&g->ball, &g->paddle_1) || ballCheckCollision(&g->ball, &g->paddle_2))
    {
        printf("Ping\n");
    }

    gameCheckCollision(g);
}

void gameCheckCollision(Game *g)
{
    if (g->ball.rect.x <= 0)
    {
        g->score_2++;
        gameRoundReset(g);
        printf("Punkt dla gracza 2 %d\n", g->score_2);
    }
    else if (g->ball.rect.x >= SCREEN_WIDTH - g->ball.rect.w)
    {
        g->score_1++;
        gameRoundReset(g);
        printf("Punkt dla gracza 1 %d\n", g->score_1);
    }
}

void gameRoundReset(Game *g)
{
    paddleInit(&g->paddle_1, true);
    paddleInit(&g->paddle_2, false);
    ballInit(&g->ball);
}
void gameReset(Game *g)
{
    gameRoundReset(g);
    g->score_1 = 0;
    g->score_2 = 0;
}