#ifndef PENDULUM_H
#define PENDULUM_H

#include <SDL2/SDL.h>

class pendulum
{
    public:
        int origin_x;
        int origin_y;
        int lenght;
        int ball_x;
        int ball_y;
        int radius;
        double theta;
        double speedAccelaration;
        
        pendulum(int x, int y, int len, double angle, int r);
        drawCircle(SDL_Renderer* renderer);
        draw(SDL_Renderer* renderer);
        changeLenght(SDL_Event event, int screenHeight);
};

#endif // PENDULUM_H