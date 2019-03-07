#include "header.h"

double Flake::drand(double from, double to) {
    return (to - from) * ( (double)rand() / (double)RAND_MAX ) + from;
}

void Flake::next_frame(SDL_Renderer * rend) {
    y += y_speed;
    x = start_x + curve_coef * sin( curve_period * rect.y );
    angle += rot_speed;

    rect.x = int(x);
    rect.y = int(y);

    SDL_RenderCopyEx(rend, texture, nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);
}

Flake::Flake(SDL_Renderer * rend) {
    y_speed = drand(0.5, 2.5);
    rot_speed = drand(0.2, 2.0);
    curve_coef = drand(10.0, 35.0);
    curve_period = drand(0.005, 0.07);

    SDL_Surface * flake_srf = IMG_Load("../images/snowflake1.png");
    texture = SDL_CreateTextureFromSurface(rend, flake_srf);
    SDL_FreeSurface(flake_srf);
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);

    rect.w = rect.h = int(drand(15.0, 40.0));

    start_x = int(drand(double(rect.w), double(WINDOW_WIDTH - rect.w)));
    x = y = 0;
    angle = 0;
}