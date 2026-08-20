#include <raylib.h>
#include <vector>
#include "Map.hpp"

Map::Map(int width_pixel, int height_pixel, int pixel_size) : map_width_pixel(width_pixel),
                                                              map_height_pixel(height_pixel),
                                                              map_pixel_size(pixel_size)
{

    // Despues de crear el vector, lo rellenamos de los obstaculos del mapa
    initMap();
};

Map::~Map() {}

void Map::initMap()
{
    // Inicializacion de los obstaculos (metodo initObstacle) con los pixeles serializados
    m_mapa = std::vector<std::vector<int>>(map_height_pixel, std::vector<int>(map_width_pixel, 0));
    initObstacles();
}

void Map::initObstacles()
{

    // Coordenadas donde vamos a colocar el obstaculo
    /*
        Entonces resumiendo con la serialización:

        Tamanyo de pantalla: height -> 800, width --> 600
        Tamanyo pixeles: 50
        Tamanyo serializado pantalla: height_pixel --> 16
        Tamanyo serializado pantalla: width_pixel --> 12

        Entonces ahora para colocarlo, si lo ponemos en el 1x1, será como si en la realidad
        rellenamos en la matriz original, desde la coordenada 0 pones 16 en vertical y 12 en horizontal

    */

    size_t obs1_X = 2;
    size_t obs2_Y = 2;

    // Introducimos un obstaculo en el (0,0) (con 50x50 -> 16x12)
    /*
        Usamos el ++i cuando queremos que en esa linea no solo el valor de 'i' aumente, sino tambien
        en aquello en lo que lo utilizamos antes de pasar a la siguiente linea
    */
    for (size_t i = 0; i < m_mapa.size(); ++i)
    {
        for (size_t j = 0; j < m_mapa.size(); ++j)
        {
            if (i == obs1_X && j == obs2_Y)
            {
                m_mapa[i][j] = 1;
            }
        }
    }
}

bool Map::isMuro(int x, int y) const
{

    for (size_t i = 0; i < m_mapa[i].size(); i++)
    {
        for (size_t j = 0; j < m_mapa[j].size(); j++)
        {
            if (x < 0 || y < 0 || x >= static_cast<int>(m_mapa[0].size()) || y >= static_cast<int>(m_mapa.size()))
            {
                return false;
            }
            return m_mapa[y][x] == 1;
        }
    }
    return false;
}