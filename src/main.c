#include "main.h"

int main(int argc, char *argv[])
{
    Game game;
    Gui gui;
    if (guiInit(&gui))
        guiClean(&gui, EXIT_FAILURE);
    if (gameInit(&game, 10))
        guiClean(&gui, EXIT_FAILURE);

    Uint32 current_time = SDL_GetTicks();
    Uint32 last_time = current_time;
    float delta_time = 0.0f;

    bool game_loop = true;
    while (game_loop)
    {
        current_time = SDL_GetTicks();
        delta_time = (current_time - last_time) / 1000.0f;
        last_time = current_time;

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                guiClean(&gui, EXIT_SUCCESS);
                game_loop = false;
                break;
            default:
                break;
            }
        }

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        gameUpdate(&game, keystate, delta_time);

        SDL_SetRenderDrawColor(gui.renderer, 0, 0, 0, 255);
        SDL_RenderClear(gui.renderer);

        guiDrawRect(&gui, &game.paddle_1.rect, game.paddle_1.color);
        guiDrawRect(&gui, &game.paddle_2.rect, game.paddle_2.color);
        guiDrawRect(&gui, &game.ball.rect, game.ball.color);


        SDL_RenderPresent(gui.renderer);
        SDL_Delay(16); // 60 fps
    }

    guiClean(&gui, EXIT_SUCCESS);
    return 0;
}