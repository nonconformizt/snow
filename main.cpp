#include "header.h"

int main(int argc, char ** argv)
{
    srand(time(NULL));

    SDL_Window * win;
    SDL_Renderer * rend;

    if(!SDL_Start(&win, &rend))
        return -1;

    SDL_Surface * bg_surf = IMG_Load("../images/background.jpg");
    SDL_Texture * bg = SDL_CreateTextureFromSurface(rend, bg_surf);
    SDL_FreeSurface(bg_surf);

    Flake flakes[FLAKES_N] {{rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}, {rend}};

    bool close_requested = false;
    while (!close_requested)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if ( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE )
                close_requested = true;

        SDL_RenderClear(rend);

        SDL_RenderCopy(rend, bg, nullptr, nullptr);

        for (int i = 0; i < FLAKES_N; ++i)
            flakes[i].next_frame(rend);

        SDL_RenderPresent(rend);
        SDL_Delay(10);
    }


    SDL_Delay(500);
    SDL_Quit();
    return 0;
}