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
        void next_frame();
        void render(SDL_Renderer * rend);
        Flake();

    private:
        // parameters
        const double h, w,
                     y_speed,
                     rot_speed,
                     curve_period,
                     curve_coef;
        // current values
        double x, y;

};

Flake::Flake(void) {
    srand(time(nullptr));

}

Flake::drand(double from, double to)
{
    double f = (double)rand() / RAND_MAX;
    return from + f * (from - to);
}




// returns TRUE if ok, FALSE in case of error
bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer);