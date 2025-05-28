#ifndef MENU_H
#define MENU_H

#include <SDL2/SDL.h>   
#include <SDL2/SDL_ttf.h>   
#include "gui.h"

typedef struct {
    TTF_Font *title_font;
    SDL_Color title_color;

    char player1_name[16];
    char player2_name[16];
    SDL_Color paddle1_color;
    SDL_Color paddle2_color;
    int final_score;
} Menu;

bool renderMenu(Gui *gui, Menu *menu);


#endif // MENU_H