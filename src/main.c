#include "main.h"

int main(int argc, char *argv[])
{
    Game game;
    if (guiInit(&gui))
        guiClean(&gui, EXIT_FAILURE);
    if (gameInit(&game, 10))
        guiClean(&gui, EXIT_FAILURE);

    bool game_loop = true;
    while (game_loop)
    {
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