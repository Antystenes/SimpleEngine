#ifndef MAPHANDLER_HPP_INCLUDED
#define MAPHANDLER_HPP_INCLUDED


#include <vector>
#include <SDL2/SDL.h>
#include <string.h>
#include <fstream>
/*struct LevelList
{
    int Current;
    std::vector <char*> List;
    LevelList(const char* ListDir)
    {
        std::ifstream ListFile;
        ListFile.open(ListDir);
        ListFile >> Current;
        for (int i=0; i<Current; i++)
        {
            char *a;
            ListFile >> *a;
            List.push_back(a);
        }
        Current = 1;
    }
};*/
struct LevelData
{
    int Height;
    int Width;
    std::vector < std::vector <int> > Data;
    void MapLoad(const char* Level);
    SDL_Surface* MapSurface;
    void SurfaceFill(const char* SpriteSheet);
    LevelData()
    {
        MapSurface = NULL;
        Height = 0;
        Width = 0;
    }
    void ClearMapData();
};
#endif // MAPHANDLER_HPP_INCLUDED

