#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <iostream>
#include <cmath>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#undef main

using namespace std;

#define WINDOW_WIDTH (720)
#define WINDOW_HEIGHT (480)

class Flake {
public:
    void next_frame(SDL_Renderer * rend);
    double drand(double from, double to);

    explicit Flake(SDL_Renderer * rend);

private:
    // parameters
    double  y_speed,
            rot_speed,
            curve_coef,
            curve_period,
            angle, x, y, start_x; // current angle
    SDL_Texture * texture;
    SDL_Rect rect = {0, 0, 0, 0};
};



// returns TRUE if ok, FALSE in case of error
bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer);


#endif