#include "gui.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

bool guiInit(Gui *gui)
{
    if (SDL_Init(SDL_INIT_EVERYTHING))
    {
        fprintf(stderr, "Error initializing SDL: %s\n", SDL_GetError());
        return true;
    }

    if (TTF_Init())
    {
        fprintf(stderr, "Error initializing SDL_ttf: %s\n", TTF_GetError());
        return false;
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

    gui->font = TTF_OpenFont("../assets/tiny_mono_pixel.ttf", SCORE_SIZE);
    if (!gui->font)
    {
        fprintf(stderr, "Error creating Font: %s\n", TTF_GetError());
        return true;
    }
    gui->score.color = (SDL_Color){255, 255, 255, 255};
    gui->score.last_score_1 = -1;
    gui->score.last_score_2 = -1;

    return false;
}

void guiClean(Gui *gui, int exit_status)
{
    SDL_DestroyTexture(gui->score.texture);
    TTF_CloseFont(gui->font);
    SDL_DestroyRenderer(gui->renderer);
    SDL_DestroyWindow(gui->window);

    // wychodzenie z bibliotek
    TTF_Quit();
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

    for (int y = 0; y < SCREEN_HEIGHT; y += 20)
    {
        SDL_Rect line;
        line.w = 2;
        line.h = 10;
        line.x = 395.0f;
        line.y = y;

        if (SDL_RenderFillRect(gui->renderer, &line))
        {
            fprintf(stderr, "Error filling middle line: %s\n", SDL_GetError());
            return true;
        }
    }

    return false;
}

bool guiDrawScore(Gui *gui, int score_1, int score_2)
{
    if (gui->score.texture)
        SDL_DestroyTexture(gui->score.texture);

    gui->score.last_score_1 = score_1;
    gui->score.last_score_1 = score_2;

    char score[32];
    sprintf(score, "%d  %d", score_1, score_2);

    SDL_Surface *score_surface = TTF_RenderText_Blended(gui->font, score, gui->score.color);
    if (!score_surface)
    {
        fprintf(stderr, "Error creating surface: %s\n", SDL_GetError());
        return true;
    }

    gui->score.texture = SDL_CreateTextureFromSurface(gui->renderer, score_surface);
    SDL_FreeSurface(score_surface);
    if (!gui->score.texture)
    {
        fprintf(stderr, "Error creating score texture: %s\n", SDL_GetError());
        return true;
    }

    SDL_QueryTexture(gui->score.texture, NULL, NULL, &gui->score.rect.w, &gui->score.rect.h);
    gui->score.rect.x = (SCREEN_WIDTH - gui->score.rect.w) / 2;
    gui->score.rect.y = 10;

    SDL_RenderCopy(gui->renderer, gui->score.texture, NULL, &gui->score.rect);

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