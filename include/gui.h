#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define WINDOW_TITLE "PONG"
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

typedef struct
{
    SDL_Window *window;
    SDL_Renderer *renderer;
} Gui;

extern Gui gui;

bool guiInit(Gui *gui);
void guiClean(Gui *gui, int exit_status);
bool guiDrawCenterLine(Gui *gui);

bool guiDrawRect(Gui *gui, const SDL_Rect *rect, SDL_Color color);

#endif // GUI_H