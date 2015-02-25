#include <SDL2/SDL.h>
#include "MapHandler.hpp"
#include "MainMenu.hpp"
#include "CharHandler.hpp"


int MenuLoop(SDL_Window* window, SDL_Surface* screenSurface, SDL_Event* e)
{
    Menu MainScreen("MainMenu", "Cursor");
    while((MainScreen.Selection == 0) && (e->type != SDL_QUIT))
    {
        SDL_PollEvent(e);
        MainScreen.MenuHandle(screenSurface);
        SDL_UpdateWindowSurface( window );
    }
    SDL_FreeSurface(MainScreen.Screen);
    SDL_FreeSurface(MainScreen.Cursor);
    return MainScreen.Selection;
}

void GameplayLoop(SDL_Window* window, SDL_Surface* screenSurface, SDL_Event* e)
{
    int Framestart;
    LevelData LoadedMap;
    LoadedMap.MapLoad("Level1");
    LoadedMap.SurfaceFill("SprSheet1");
    characterdata Player;
    Player.Surface = SDL_LoadBMP("Char.bmp");
    Uint32 colorkey = SDL_MapRGB( Player.Surface->format, 0, 0, 0);
    SDL_SetColorKey( Player.Surface, SDL_TRUE, colorkey);
    do
    {
        Framestart = SDL_GetTicks();
        SDL_PollEvent(e);
        SDL_BlitSurface(LoadedMap.MapSurface, &(screenSurface->clip_rect), screenSurface, &(screenSurface->clip_rect));
        Player.PlayerHandle(screenSurface, &LoadedMap);
        SDL_UpdateWindowSurface( window );
        Framestart = SDL_GetTicks() - Framestart;
        if (Framestart < 1000/60)
            SDL_Delay( 1000/60 - Framestart);
    }while(e->type != SDL_QUIT);
    SDL_FreeSurface(Player.Surface);
    LoadedMap.ClearMapData();
}

void MainLoop(SDL_Window* window, SDL_Surface* screenSurface)
{
    SDL_Event e;
    int Gamestate = 0;
    while ((Gamestate != 3) && (e.type != SDL_QUIT))
    {
        if (Gamestate == 0)
        {
            Gamestate = MenuLoop(window, screenSurface, &e);
        }
        if (Gamestate == 1)
        {
            GameplayLoop(window, screenSurface, &e);
        }
    }
//    LoadedMap.ClearMapData();
}
