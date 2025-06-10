#include "../include/menu.h"
#include <SDL2/SDL_ttf.h>

bool menuInit(Gui *gui, Menu *menu)
{
    if (!gui || !gui->renderer || !menu || !menu->title.texture)
    {
        fprintf(stderr, "Invalid GUI or Menu structure in renderMenu\n");
        return true;
    }

    menu->title.font = TTF_OpenFont("../assets/tiny_mono_pixel.ttf", TITLE_SIZE);
    if (!menu->title.font)
    {
        fprintf(stderr, "Error creating Font: %s\n", TTF_GetError());
        return true;
    }
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

    return false;
}

void menuClean(Menu *menu)
{
    SDL_DestroyTexture(menu->title.texture);
    TTF_CloseFont(menu->title.font);
}

bool menuRender(Gui *gui, Menu *menu)
{
    SDL_SetRenderDrawColor(gui->renderer, 0, 0, 0, 255);
    SDL_RenderClear(gui->renderer);

    SDL_RenderCopy(gui->renderer, menu->title.texture, NULL, &menu->title.rect);

    renderLastRounds(gui, menu);
    SDL_RenderPresent(gui->renderer);
    return false;
}

void renderLastRounds(Gui *gui, Menu *menu)
{
    char buffer[32];
    SDL_Color color = {200, 200, 200, 255};
    int font_size = 18;
    int line_height = 22;
    int count = menu->last_scores_count;
    int total_height = count * line_height;
    int y_start = SCREEN_HEIGHT - total_height - 30;

    TTF_Font *small_font = TTF_OpenFont("../assets/tiny_mono_pixel.ttf", font_size);
    if (!small_font)
        return;

    const char *header = "Ostatnie gry";
    SDL_Surface *header_surface = TTF_RenderText_Blended(small_font, header, color);
    if (header_surface)
    {
        int header_x = (SCREEN_WIDTH - header_surface->w) / 2;
        int header_y = y_start - line_height - 10;
        SDL_Texture *header_texture = SDL_CreateTextureFromSurface(gui->renderer, header_surface);
        SDL_Rect header_rect = {header_x, header_y, header_surface->w, header_surface->h};
        SDL_RenderCopy(gui->renderer, header_texture, NULL, &header_rect);
        SDL_FreeSurface(header_surface);
        SDL_DestroyTexture(header_texture);
    }

    for (int i = 0; i < count; ++i)
    {
        snprintf(buffer, sizeof(buffer), "%d - %d", menu->last_scores[i].score_1, menu->last_scores[i].score_2);
        SDL_Surface *surface = TTF_RenderText_Blended(small_font, buffer, color);
        if (!surface)
            continue;
        int x = (SCREEN_WIDTH - surface->w) / 2;
        int y = y_start + i * line_height;
        SDL_Texture *texture = SDL_CreateTextureFromSurface(gui->renderer, surface);
        SDL_Rect rect = {x, y, surface->w, surface->h};
        SDL_RenderCopy(gui->renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
    TTF_CloseFont(small_font);
}