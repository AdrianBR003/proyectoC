#pragma once
#include <string>
#include <vector>
#include <raylib.h>

class Game {
    private:
        int width; 
        int height;
        std::string title;
        float character_x, character_y, character_size, character_speed;

        // Array del mapa para generar obstaculos, inizializo con todos los pixeles de la pantalla
        /*
            No podemos renderizar un map constantemente con todos los pixeles de la pantalla, porque serían muchisimos a tener en cuenta
            por lo que tenemos que intentar hacerlos mas grandes para que sean bastantes menos. Por eso, vamos a dividir el numero de 
            filas y columnas entre el tamaño de los pixeles, por ejemplo, quiero pixeles de 10x10, entonces: 

            mapX = width/tamPix_X
            mapY = height/tamPix_Y

            Entonces por ejemplo tendremos un vector de 80x60

            NOTA: No podemos inicializar aqui los valores, debe de ser en Game.cpp

        */
        int tamPix_X;
        int tamPix_Y;
        int mapX;
        int mapY;
        std::vector<std::vector<int>> mapa; 

        void initMap();
        void Update();
        void Draw();
        void drawObstacle(Rectangle rec);

    public: 
        Game(int screenWidth, int screenHeight, const std::string& windowTitle);
        ~Game();
        void Run();
};