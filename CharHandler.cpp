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

int maxspeed = 8;
const int tilesize = 80;
const int crop = 21;


void characterdata::PlayerHandle(SDL_Surface* window, LevelData* level )
{
    const Uint8* keystate = SDL_GetKeyboardState(NULL);

    if ((level->Data[VerticalPosition/tilesize+1][(HorizontalPosition+12)/tilesize] > 0 )||(level->Data[VerticalPosition/tilesize+1][(HorizontalPosition+66)/tilesize] > 0))          //Checking if character is on the ground
        {
            VerticalPosition = VerticalPosition/tilesize * tilesize;
            VerticalSpeed = 0;
            if(keystate[SDL_SCANCODE_SPACE] == true)
                VerticalSpeed = -15;
        }
    else                                                                            //If not it starts to fall
        {
            if(VerticalSpeed < 2*maxspeed)
                VerticalSpeed++;

        }
    if (( keystate[SDL_SCANCODE_RIGHT] == true ) && (level->Data[VerticalPosition/tilesize][(HorizontalPosition+67)/tilesize] == 0) && (HorizontalPosition < (level->Width*tilesize)-67))
        {
            HorizontalSpeed = maxspeed;
        }
    else
        if (keystate[SDL_SCANCODE_RIGHT] == true)
            {

                HorizontalSpeed = 0;
                //HorizontalPosition = (HorizontalPosition/tilesize)*tilesize+13;
            }
        else
            if ((keystate[SDL_SCANCODE_LEFT] == true) && (level->Data[VerticalPosition/tilesize][(HorizontalPosition+10)/tilesize] == 0) && (HorizontalPosition > -12))
                {
                    HorizontalSpeed = -maxspeed;
                }
            else
                if (keystate[SDL_SCANCODE_LEFT] == true)
                {
                    HorizontalSpeed = 0;
                    //HorizontalPosition = (HorizontalPosition/tilesize) * tilesize + 13;
                }
                else HorizontalSpeed = 0;
    if((VerticalSpeed < 0) && ((level->Data[(VerticalPosition)/tilesize-1][(HorizontalPosition+13)/tilesize] > 0) || (level->Data[(VerticalPosition)/tilesize-1][(HorizontalPosition+65)/tilesize] > 0)) && (VerticalPosition<0))
    {
        VerticalSpeed=0;
        VerticalPosition = (VerticalPosition/tilesize)*tilesize;
    }



    HorizontalPosition += HorizontalSpeed;
    VerticalPosition += VerticalSpeed;

    //if ((HorizontalPosition > 8*tilesize) && (HorizontalPosition < (level->Width-8)*tilesize))
    //    camerarect.x = HorizontalPosition - 640;
    positionrect.x = HorizontalPosition - camerarect.x;
    positionrect.y = VerticalPosition;

    SDL_BlitSurface(Surface, &animationrect, window, &positionrect);
}
