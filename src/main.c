#include "main.h"

int main(int argc, char *argv[])
{
    Game game;
    Gui gui;
    Menu menu;
    strcpy(menu.player1_name, "Guest1");
    strcpy(menu.player2_name, "Guest2");
    menu.paddle1_color = (SDL_Color){255, 255, 255, 255};
    menu.paddle2_color = (SDL_Color){255, 255, 255, 255};

    if (guiInit(&gui))
        guiClean(&gui, EXIT_FAILURE);
    if (menuInit(&gui, &menu))
        menuClean(&menu);
    if (gameInit(&game, 10))
        guiClean(&gui, EXIT_FAILURE);

    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double delta_time = 0.0;
    const double target_frame_time = 1.0 / 60.0; // 60 FPS

    GameState game_state = STATE_MENU;
    bool game_loop = true;
    while (game_loop)
    {
        last = now;
        now = SDL_GetPerformanceCounter();
        delta_time = (double)(now - last) / SDL_GetPerformanceFrequency();
        if (delta_time > 0.05)
            delta_time = 0.05;

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

            if (game_state == STATE_MENU)
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN)
                    game_state = STATE_PLAYING;
            }

            if (game_state == STATE_PLAYING)
            {
                if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
                {
                    gameReset(&game);
                    game_state = STATE_MENU;
                }
            }
        }

        const Uint8 *keystate = SDL_GetKeyboardState(NULL);
        
        SDL_SetRenderDrawColor(gui.renderer, 0, 0, 0, 255);
        SDL_RenderClear(gui.renderer);
        if (game_state == STATE_MENU)
        {
            menuRender(&gui, &menu);
        }
        else
        {
            gameUpdate(&game, keystate, delta_time);
            
            guiDrawCenterLine(&gui);
            if ((game.score_1 != gui.score.last_score_1 || game.score_2 != gui.score.last_score_2))
                guiDrawScore(&gui, game.score_1, game.score_2);

            guiDrawRect(&gui, &game.paddle_1.rect, menu.paddle1_color);
            guiDrawRect(&gui, &game.paddle_2.rect, menu.paddle2_color);
            guiDrawRect(&gui, &game.ball.rect, game.ball.color);

            double frame_time = (double)(SDL_GetPerformanceCounter() - now) / SDL_GetPerformanceFrequency();
            if (frame_time < target_frame_time)
            {
                SDL_Delay((Uint32)((target_frame_time - frame_time) * 1000.0));
            }
            SDL_RenderPresent(gui.renderer);
        }
    }

    guiClean(&gui, EXIT_SUCCESS);
    return 0;
}