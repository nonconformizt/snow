#include "header.h"

int main(int argc, char ** argv)
{
    SDL_Window * win;
    SDL_Renderer * rend;

    if(!SDL_Start(&win, &rend))
        return -1;

    SDL_Surface * flake_srf = IMG_Load("../images/snowflake1.png");

    SDL_Texture * flake_tex = SDL_CreateTextureFromSurface(rend, flake_srf);
    SDL_FreeSurface(flake_srf);

    // struct to hold the position of snowflake
    SDL_Rect flake;

    SDL_QueryTexture(flake_tex, nullptr, nullptr, &flake.w, &flake.h);

    // параметры снежинки
    flake.h = flake.w = 30;
    flake.x = (WINDOW_WIDTH - flake.w) / 2;
    flake.y = 0;

    double angle = 0;
    const double y_speed = 1.00,
                 rot_speed = 1.00, // скорость вращения
                 curve_period = 0.02,
                 curve_coef = 40.00;

    bool close_requested = false;
    while (!close_requested)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if ( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE )
                close_requested = true;

        flake.y += int(y_speed);
        flake.x = int(curve_coef * sin( curve_period * flake.y )) + (WINDOW_WIDTH - flake.w) / 2;
        angle += rot_speed;
        SDL_RenderClear(rend);

        SDL_RenderCopyEx(rend, flake_tex, nullptr, &flake, angle, nullptr, SDL_FLIP_NONE);

        SDL_RenderPresent(rend);
        SDL_Delay(10);
    }


    SDL_Delay(500);
    SDL_Quit();
    return 0;
}