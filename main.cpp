#include "header.h"

int main(int argc, char ** argv)
{
    srand(time(NULL));

    SDL_Window * win;
    SDL_Renderer * rend;

    if(!SDL_Start(&win, &rend))
        return -1;

    SDL_Surface * bg_surf = IMG_Load("images/background.jpg");
    SDL_Texture * bg = SDL_CreateTextureFromSurface(rend, bg_surf);
    SDL_FreeSurface(bg_surf);

    Flake * flakes[FLAKES_N];
    for (int i = 0; i < FLAKES_N; i++)
        flakes[i] = new Flake(rend);

    bool close_requested = false,
         paused = false;
    while (!close_requested)
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
            if ( e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE )
                close_requested = true;
            else if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_p )
                paused = !paused;

        SDL_RenderClear(rend);

        SDL_RenderCopy(rend, bg, nullptr, nullptr);

        for (int i = 0; i < FLAKES_N; i++)
            flakes[i]->next_frame(rend, paused);

        SDL_RenderPresent(rend);
        SDL_Delay(10);
    }

    for (int i = 0; i < FLAKES_N; flakes[i++]->destroy());
    SDL_DestroyTexture(bg);
    SDL_DestroyRenderer(rend);
    SDL_DestroyWindow(win);
    IMG_Quit();
    SDL_Quit();
    return 0;
}