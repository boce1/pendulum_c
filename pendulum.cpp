#include "pendulum.hpp"
#include<iostream>
#include<cmath>

pendulum::pendulum(int x, int y, int len, double angle, int r)
{
    origin_x = x;
    origin_y = y;
    lenght = len;
    theta = angle;
    radius = r;
    speedAccelaration = 0;
}

pendulum::drawCircle(SDL_Renderer* renderer)
{
    const int32_t diameter = (radius * 2);

    int32_t x = (radius - 1);
    int32_t y = 0;
    int32_t tx = 1;
    int32_t ty = 1;
    int32_t error = (tx - diameter);
    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    while (x >= y)
    {
        SDL_RenderDrawPoint(renderer, origin_x + ball_x + x,origin_y + ball_y - y);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x + x,origin_y + ball_y - y);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x + x,origin_y + ball_y + y);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x - x,origin_y + ball_y - y);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x - x,origin_y + ball_y + y);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x + y,origin_y + ball_y - x);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x + y,origin_y + ball_y + x);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x - y,origin_y + ball_y - x);
        SDL_RenderDrawPoint(renderer, origin_x + ball_x - y,origin_y + ball_y + x);

        if (error <= 0)
        {
        	++y;
        	error += ty;
        	ty += 2;
        }

        if (error > 0)
        {
            --x;
        	tx += 2;
        	error += (tx - diameter);
        }
    }
}

pendulum::draw(SDL_Renderer *renderer)
{
    ball_x = lenght * sin(theta);
    ball_y = lenght * cos(theta);

    SDL_SetRenderDrawColor(renderer, 255,255,255,255);
    SDL_RenderDrawLine(renderer, origin_x, origin_y, origin_x + ball_x, origin_y + ball_y);
    drawCircle(renderer);

}