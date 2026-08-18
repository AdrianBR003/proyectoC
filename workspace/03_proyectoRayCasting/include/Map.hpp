#pragma once
#include <string>
#include <vector>
#include <raylib.h>

class Map
{
private:
    int map_width_pixel;
    int map_height_pixel;
    int map_pixel_size;
    
    std::vector<std::vector<int>> m_mapa;

    void initObstacles();

public:
    Map(int width_pixel, int height_pixel, int map_pixel_size);
    ~Map();

    const std::vector<std::vector<int>> &getMap() const
    {
        return m_mapa;
    }

    void setMap(const std::vector<std::vector<int>> &newMap)
    {
        m_mapa = newMap;
    }
    
    void initMap();

};