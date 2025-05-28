#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

#define WINDOW_TITLE "PONG"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define SCORE_SIZE 24

typedef struct
{
    SDL_Color color;
    SDL_Rect rect;
    SDL_Texture *texture;
    int last_score_1;
    int last_score_2;
} Score;

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    TTF_Font *font;
    Score score;
} Gui;
extern Gui gui;



bool guiInit(Gui *gui);
void guiClean(Gui *gui, int exit_status);
bool guiDrawCenterLine(Gui *gui);
bool guiDrawScore(Gui *gui, int score_1, int score_2);

bool guiDrawRect(Gui *gui, const SDL_Rect *rect, SDL_Color color);

#endif // GUI_H