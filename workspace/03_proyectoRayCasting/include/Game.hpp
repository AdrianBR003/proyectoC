#pragma once
#include <string>
#include <vector>
#include <raylib.h>
#include "Character.hpp"
#include "Map.hpp"


class Game {
    private:
    // Variables no serializadas para el tamaño de la pantalla
        int game_width_screen; 
        int game_height_screen;
        std::string game_title_screen;
    // Variables serializadas para los elementos del juego
        int game_width_pixel; 
        int game_height_pixel; 
        int game_pixel_size; 
    // Otros objetos
        Character character;
        Character centinela;
        Map mapaComplete;

        void Update();
        void Draw();

    public: 
        Game(int game_width_screen, int game_height_screen, const std::string& game_title_screen,
             int game_width_pixel, int game_height_pixel, int game_pixel_size);
        ~Game();
        void Run();
};