#include "../include/game.h"

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
        printf("Ping ");
    }
}