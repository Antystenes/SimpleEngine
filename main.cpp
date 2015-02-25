#include <SDL2/SDL.h>
#include "WindowInitializer.hpp"
#include "GameEngine.hpp"

int main()
{
    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    WindowInit(&window, &screenSurface);
    MainLoop(window, screenSurface);
    SDL_DestroyWindow( window );
    SDL_Quit();
    return 0;
}
