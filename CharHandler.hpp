#ifndef CHARHANDLER_HPP_INCLUDED
#define CHARHANDLER_HPP_INCLUDED
#include <SDL2/SDL.h>
#include "MapHandler.hpp"
struct characterdata
{
    int Lives;
    SDL_Rect animationrect;
    SDL_Rect positionrect;
    SDL_Rect camerarect;
    int HorizontalPosition;
    int VerticalPosition;
    int HorizontalSpeed;
    int VerticalSpeed;
    SDL_Surface* Surface;
    void PlayerHandle(SDL_Surface* window, LevelData* Level );
    characterdata() : HorizontalPosition(0), VerticalPosition(0), HorizontalSpeed(0), VerticalSpeed(0), Lives(1)
    {
        camerarect.x=0;
        camerarect.y=0;
        camerarect.w=1280;
        camerarect.h=720;
        positionrect.x = 0;
        positionrect.y = 0;
        animationrect.x=0;
        animationrect.y=0;
        animationrect.h=80;
        animationrect.w=80;}
};

#endif // CHARHANDLER_HPP_INCLUDED
