#include <SDL2/SDL.h>

void WindowInit(SDL_Window** window, SDL_Surface** ScreenSurface)
{
    SDL_Init( SDL_INIT_VIDEO);
    *window = SDL_CreateWindow("YOLO", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
    *ScreenSurface = SDL_GetWindowSurface( *window );
}
