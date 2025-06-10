#ifndef MENU_H
#define MENU_H

#include "gui.h"
#include "file.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define TITLE_SIZE 64

typedef struct
{
    TTF_Font *font;
    SDL_Color color;
    SDL_Texture *texture;
    SDL_Rect rect;
} Title;

typedef struct
{
    LastScores last_scores[10];
    TTF_Font *font;
    SDL_Color color;
    SDL_Texture *texture;
    SDL_Rect rect;
} MenuRounds;

typedef struct
{
    Title title;
    LastScores last_scores[MAX_LINES];
    int last_scores_count;

    char player1_name[16];
    char player2_name[16];
    SDL_Color paddle1_color;
    SDL_Color paddle2_color;
    int final_score;
} Menu;

bool menuInit(Gui *gui, Menu *menu);
void menuClean(Menu *menu);
bool menuRender(Gui *gui, Menu *menu);
void renderLastRounds(Gui *gui, Menu *menu);

#endif // MENU_H