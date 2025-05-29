#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>   
#include <SDL2/SDL_ttf.h>   
#include "gui.h"

#define TITLE_SIZE 64

typedef struct
{
    TTF_Font *font;
    SDL_Color color;
    SDL_Texture *texture;
    SDL_Rect rect;
} Title;


typedef struct {
    Title title;

    char player1_name[16];
    char player2_name[16];
    SDL_Color paddle1_color;
    SDL_Color paddle2_color;
    int final_score;
} Menu;

bool renderMenu(Gui *gui, Menu *menu);


#endif // MENU_H