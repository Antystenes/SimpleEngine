#include <fstream>
#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
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

void LevelData::ClearMapData()
{
    SDL_FreeSurface(MapSurface);
    for(int i=0; i<Height; i++)
        Data.pop_back();
    Width=0;
    Height=0;
}

void LevelData::SurfaceFill(const char* SpriteSheet)
{
    SDL_Rect Position;
    SDL_Rect Tile;
    Tile.x=0;
    Tile.h = 80;
    Tile.w = 80;
    SDL_Surface* sprites = SDL_LoadBMP(SpriteSheet);
    MapSurface = SDL_CreateRGBSurface(0, Width*80, Height*80, 16, 0, 0, 0, 0);
    for(int i=0; i<Height; i++)
    {
        for(int j=0; j<Width; j++)
        {
            Position.x=j*80;
            Position.y=i*80;
            Tile.y=(Data[i][j]-1)*80;
            SDL_BlitSurface( sprites, &Tile, MapSurface, &Position);
        }
    }
    SDL_FreeSurface(sprites);
}

void LevelData::MapLoad(const char* Level)
{
    std::ifstream Map;
    Map.open(Level);
    Map >> Width;
    Map >> Height;
    int a;
    for (int i=0; i < Height; i++)
    {
        std::vector<int> row;
        for(int j=0; j<Width; j++)
        {
        Map >> a;
        row.push_back(a);
        }
        Data.push_back(row);
        row.clear();
    }
    Map.close();
}
