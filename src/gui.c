#include "../include/gui.h"
#include <SDL2/SDL.h>

bool guiInit(Gui *gui)
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return true;
    }

    gui->window = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!gui->window)
    {
        fprintf(stderr, "Error creating window: %s\n", SDL_GetError());
        return true;
    }

    gui->renderer = SDL_CreateRenderer(gui->window, -1, 0);
    if (!gui->renderer)
    {
        fprintf(stderr, "Error creating renderer: %s\n", SDL_GetError());
        return true;
    }

    return false;
}

void guiClean(Gui *gui, int exit_status)
{
    SDL_DestroyRenderer(gui->renderer);
    SDL_DestroyWindow(gui->window);

    // wychodzenie z bibliotek
    SDL_Quit();
    exit(exit_status);
}

bool guiDrawCenterLine(Gui *gui)
{
    if (SDL_SetRenderDrawColor(gui->renderer, 110, 110, 110, 255))
    {
        fprintf(stderr, "Error initializing middle line: %s\n", SDL_GetError());
        return true;
    }

    SDL_Rect line;
    line.w = 10;
    line.h = SCREEN_HEIGHT;
    line.x = 395.0f;
    line.y = 0;

    if (SDL_RenderFillRect(gui->renderer, &line))
    {
        fprintf(stderr, "Error filling middle line: %s\n", SDL_GetError());
        return true;
    }

    return false;
}

bool guiDrawRect(Gui *gui, const SDL_Rect *rect, SDL_Color color)
{
    if (SDL_SetRenderDrawColor(gui->renderer, color.r, color.g, color.b, color.a))
    {
        fprintf(stderr, "Error setting render color: %s\n", SDL_GetError());
        return true;
    }
    if (SDL_RenderFillRect(gui->renderer, rect))
    {
        fprintf(stderr, "Error filling rect: %s\n", SDL_GetError());
        return true;
    }

    return false;
}