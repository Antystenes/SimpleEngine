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
    int Selection;
    void MenuHandle(SDL_Surface* window);
};


void Menu::MenuHandle(SDL_Surface* window)
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);
    if (keystate[SDL_SCANCODE_UP])
    {
        CursorPosition.y-=42;
        if (CursorPosition.y < 55)
            CursorPosition.y=139;

    }
    if (keystate[SDL_SCANCODE_DOWN])
    {
        CursorPosition.y+=42;
        if (CursorPosition.y > 139)
            CursorPosition.y=55;
    }
    if (keystate[SDL_SCANCODE_RETURN] || keystate[SDL_SCANCODE_SPACE])
    {
        if(CursorPosition.y == 55)
            Selection = 1;
        if(CursorPosition.y == 97)
            Selection = 2;
        if(CursorPosition.y == 139)
            Selection = 3;
    }
    SDL_BlitSurface( Screen, &ScreenRect, window, &ScreenRect);
    SDL_BlitSurface( Cursor, 0, window, &CursorPosition);
    SDL_Delay(100);
}
//113 76
