#include "main.h"

int main(int argc, char *argv[])
{
    Game game;
    Gui gui;
    if (guiInit(&gui))
        guiClean(&gui, EXIT_FAILURE);
    if (gameInit(&game, 10))
        guiClean(&gui, EXIT_FAILURE);

    // Uint32 current_time = SDL_GetTicks();
    // Uint32 last_time = current_time;
    // float delta_time = 0.0f;
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta_time = 0.0;
    const double target_frame_time = 1.0 / 60.0; // 60 FPS

    bool game_loop = true;
    while (game_loop)
    {
        // current_time = SDL_GetTicks();
        // delta_time = (current_time - last_time) * 0.001f;
        // last_time = current_time;
        last = now;
        now = SDL_GetPerformanceCounter();
        delta_time = (double)(now - last) / SDL_GetPerformanceFrequency();
        if (delta_time > 0.05)
            delta_time = 0.05;

        printf("%lf\n", delta_time * 60);

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
        // SDL_Delay(1000 / 60); // 60 fps
        double frame_time = (double)(SDL_GetPerformanceCounter() - now) / SDL_GetPerformanceFrequency();
        if (frame_time < target_frame_time)
        {
            SDL_Delay((Uint32)((target_frame_time - frame_time) * 1000.0));
        }
    }

    guiClean(&gui, EXIT_SUCCESS);
    return 0;
}