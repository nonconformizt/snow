#include "header.h"


bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer)
{
    if ( SDL_Init( SDL_INIT_VIDEO ) != 0) {
        cout << "Initialization failed! \n";
        return false;
    }

    *window = SDL_CreateWindow("LAB 20 Task 3",
                               SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED,
                               WINDOW_WIDTH,
                               WINDOW_HEIGHT,
                               SDL_WINDOW_ALLOW_HIGHDPI);
    if ( *window == NULL ) {
        cout << "Cannot create window\n";
        SDL_Quit();
        return false;
    }

    *renderer = SDL_CreateRenderer( *window, -1, SDL_RENDERER_ACCELERATED );
    if ( *renderer == NULL ) {
        cout << "Cannot create renderer\n";
        SDL_DestroyWindow( *window );
        SDL_Quit();
        return false;
    }
    SDL_RenderClear( *renderer );
    SDL_RenderPresent( *renderer );
    return true;
}
