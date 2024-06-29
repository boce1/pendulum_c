#include <iostream>
#include <SDL2/SDL.h>
#include "pendulum.hpp"
#include <cmath>

const int WIDTH = 1000;
const int HEIGHT = 800;
const double PI = 3.14159;
const double gravityForce = 0.001;

void draw(SDL_Renderer *renderer, pendulum &p);
void thetaChange(pendulum &p, double startAngle, double deltaTime);

int main(int argc, char* argv[]) 
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("hello world", 100, 100, WIDTH, HEIGHT, 0);
    if(window == NULL) 
    {
        return 1;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    int p_lenght = 500;
    int p_radius = 20;
    double startAngle = PI / 4;
    int originX = WIDTH / 2;
    int originY = 0;
    pendulum p(originX, originY, p_lenght, startAngle, p_radius);

    bool running = true;
    SDL_Event event;
    // const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
    Uint64 nowTicks = SDL_GetPerformanceCounter();
    Uint64 lastTicks = 0;
    double deltaTime = 0; 
    int direction;
    while(running)
    {
        lastTicks = nowTicks;
        nowTicks = SDL_GetPerformanceCounter();
        deltaTime = (double)((nowTicks - lastTicks)*1000 / (double)SDL_GetPerformanceFrequency());
        
        //keyboardState = SDL_GetKeyboardState(NULL);
        draw(renderer, p);
        thetaChange(p, startAngle, deltaTime);
        if(SDL_PollEvent(&event)) 
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
        }
        
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}


void draw(SDL_Renderer *renderer, pendulum &p)
{
    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
    SDL_RenderClear(renderer);
    p.draw(renderer);
    SDL_RenderPresent(renderer);;
}

void thetaChange(pendulum &p, double startAngle, double deltaTime)
{
    double pendulumForce = gravityForce * sin(p.theta); // F = m * a
    // lets assume that ball has mass of 1 so accelaration if equal to horizontal component of gravitationa force
    p.speedAccelaration += (-1 * pendulumForce) / p.lenght;
    p.theta += p.speedAccelaration * deltaTime;
    // std::cout << sin(p.theta) << std::endl;
}