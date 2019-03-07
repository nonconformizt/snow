#include "header.h"

double Flake::drand(double from, double to) {
    return (to - from) * ( (double)rand() / (double)RAND_MAX ) + from;
}

void Flake::next_frame(SDL_Renderer * rend) {
    if (y >= WINDOW_HEIGHT) {
        start_x = int(drand(0.0, double(WINDOW_WIDTH)));
        x = 0;
        y = drand(-WINDOW_HEIGHT, -50.0);
    } else {
        y += y_speed;
    }
    x = start_x + curve_coef * sin( curve_period * rect.y );
    angle += rot_speed;

    rect.x = int(x);
    rect.y = int(y);

    SDL_RenderCopyEx(rend, texture, nullptr, &rect, angle, nullptr, SDL_FLIP_NONE);
}

Flake::Flake(SDL_Renderer * rend) {
    y_speed = drand(0.8, 2.0);
    rot_speed = drand(-1.8, 1.8);
    curve_coef = drand(10.0, 15.0);
    curve_period = drand(0.005, 0.05);

    char *names[3] = {(char*)"../images/snowflake1.png", (char*)"../images/snowflake2.png", (char*)"../images/snowflake3.png"};
    int rnd_name = rand() % 3 + 1;
    SDL_Surface * flake_srf = IMG_Load(names[rnd_name]);
    texture = SDL_CreateTextureFromSurface(rend, flake_srf);
    SDL_FreeSurface(flake_srf);
    SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);

    rect.w = rect.h = int(drand(15.0, 40.0));

    start_x = int(drand(0.0, double(WINDOW_WIDTH)));
    x = 0;
    y = drand(-WINDOW_HEIGHT, -50.0);
    angle = 0;
}