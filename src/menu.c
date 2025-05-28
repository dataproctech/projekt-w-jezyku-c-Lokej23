#include "../include/menu.h"
#include <SDL2/SDL_ttf.h>

bool renderMenu(Gui *gui, Menu *menu)
{
    menu->title_font = TTF_OpenFont("../assets/tiny_mono_pixel.ttf", 48);
    if (!menu->title_font)
    {
        fprintf(stderr, "Error creating Font: %s\n", TTF_GetError());
        return true;
    }
    SDL_SetRenderDrawColor(gui->renderer, 0, 0, 0, 255);
    SDL_RenderClear(gui->renderer);
    menu->title_color = (SDL_Color){255, 255, 255, 255};
    SDL_Surface *title_surface = TTF_RenderText_Blended(menu->title_font, "Pong", menu->title_color);
    if (!title_surface)
    {
        fprintf(stderr, "Error creating title surface: %s\n", TTF_GetError());
        return true;
    }
    SDL_Texture *title_texture = SDL_CreateTextureFromSurface(gui->renderer, title_surface);
    SDL_FreeSurface(title_surface);
    if (!title_texture)
    {
        fprintf(stderr, "Error creating title texture: %s\n", SDL_GetError());
        return true;
    }

    SDL_Rect title_rect;
    SDL_QueryTexture(title_texture, NULL, NULL, &title_rect.w, &title_rect.h);
    title_rect.x = (SCREEN_WIDTH - title_rect.w) / 2;
    title_rect.y = 50;

    SDL_RenderCopy(gui->renderer, title_texture, NULL, &title_rect);
    SDL_DestroyTexture(title_texture);
    TTF_CloseFont(menu->title_font);

    SDL_RenderPresent(gui->renderer);

    return false;
}