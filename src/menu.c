#include "../include/menu.h"
#include <SDL2/SDL_ttf.h>

bool renderMenu(Gui *gui, Menu *menu)
{
    menu->title.font = TTF_OpenFont("../assets/tiny_mono_pixel.ttf", TITLE_SIZE);
    if (!menu->title.font)
    {
        fprintf(stderr, "Error creating Font: %s\n", TTF_GetError());
        return true;
    }
    SDL_SetRenderDrawColor(gui->renderer, 0, 0, 0, 255);
    SDL_RenderClear(gui->renderer);
    menu->title.color = (SDL_Color){255, 255, 255, 255};
    SDL_Surface *title_surface = TTF_RenderText_Blended(menu->title.font, "Pong", menu->title.color);
    if (!title_surface)
    {
        fprintf(stderr, "Error creating title surface: %s\n", TTF_GetError());
        return true;
    }
    menu->title.texture = SDL_CreateTextureFromSurface(gui->renderer, title_surface);
    SDL_FreeSurface(title_surface);
    if (!menu->title.texture)
    {
        fprintf(stderr, "Error creating title texture: %s\n", SDL_GetError());
        return true;
    }

    SDL_QueryTexture(menu->title.texture, NULL, NULL, &menu->title.rect.w, &menu->title.rect.h);
    menu->title.rect.x = (SCREEN_WIDTH - menu->title.rect.w) / 2;
    menu->title.rect.y = 50;

    SDL_RenderCopy(gui->renderer, menu->title.texture, NULL, &menu->title.rect);
    SDL_DestroyTexture(menu->title.texture);
    TTF_CloseFont(menu->title.font);

    SDL_RenderPresent(gui->renderer);

    return false;
}