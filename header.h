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
        double drand(double from, double to);
        Flake(SDL_Renderer * rend);

    private:
        // parameters
        double  y_speed,
                rot_speed,
                curve_coef,
                curve_period;
        SDL_Texture * texture;
        SDL_Rect rect;

};

Flake::Flake(SDL_Renderer * rend) {
    y_speed = drand(0.5, 1.5);
    rot_speed = drand(0.5, 1.5);
    curve_coef = drand(20.0, 50.0);
    curve_period = drand(0.01, 0.08);

    SDL_Surface * flake_srf = IMG_Load("../images/snowflake1.png");
    texture = SDL_CreateTextureFromSurface(rend, flake_srf);
    SDL_FreeSurface(flake_srf);
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);

    rect.w = rect.h = int(drand(25.0, 35.0));

    rect.x = int(drand(rect.w, WINDOW_WIDTH - rect.w));
    rect.y = -rect.h;

}

double Flake::drand(double from, double to)
{
    srand(time(nullptr));
    double f = (double) rand() / RAND_MAX;
    return from + f * (from - to);
}




// returns TRUE if ok, FALSE in case of error
bool SDL_Start(SDL_Window ** window, SDL_Renderer ** renderer);