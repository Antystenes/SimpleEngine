#ifndef MAINMENU_HPP_INCLUDED
#define MAINMENU_HPP_INCLUDED
#include <SDL2/SDL.h>

struct Menu
{
    SDL_Surface* Screen;
    SDL_Surface* Cursor;
    SDL_Rect CursorPosition;
    SDL_Rect ScreenRect;
    Menu(const char* ScreenBMP, const char* CursorBMP)
    {
    Screen = SDL_LoadBMP(ScreenBMP);
    Cursor = SDL_LoadBMP(CursorBMP);
    ScreenRect.x=0;
    ScreenRect.y=0;
    ScreenRect.w=1280;
    ScreenRect.h=720;
    CursorPosition.x=310;
    CursorPosition.y=55;
    Selection = 0;
    }
    //Uint8* keystate;
    int Selection;
    void MenuHandle(SDL_Surface* window);
};



#endif // MAINMENU_HPP_INCLUDED
