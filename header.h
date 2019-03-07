#include <iostream>
#include <cmath>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#undef main

using namespace std;

#define WINDOW_WIDTH (720)
#define WINDOW_HEIGHT (480)


// returns TRUE if ok, FALSE in case of error
bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer);