#ifndef GAME_H
#define GAME_H

#include "paddle.h"
#include "ball.h"
#include "gui.h"
#include <stdbool.h>

typedef struct
{
    Paddle paddle_1;
    Paddle paddle_2;
    Ball ball;
    int score_1;
    int score_2;
    int max_score;
    bool game_over;
} Game;

bool gameInit(Game *g, int max_score);
void gameUpdate(Game *g, const Uint8 *keystate, float dt);
void gameCheckCollision(Game *g);
void gameRoundReset(Game *g);

#endif // GAME_H