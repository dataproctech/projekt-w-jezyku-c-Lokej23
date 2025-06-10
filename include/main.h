#ifndef MAIN_H
#define MAIN_H

#include "gui.h"
#include "menu.h"
#include "file.h"
#include "game.h"
#include "paddle.h"
#include "ball.h"

typedef enum {
    STATE_MENU,
    STATE_PLAYING,
    STATE_PAUSE,
} GameState;

#endif // MAIN_H