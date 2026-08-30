#pragma once
#include "Scene.hpp"
#include "Character.hpp"
#include "Map.hpp"
#include <vector> 
#include <raylib.h>

/*
    Clase hija de Scene, encargada de gestionar la escena principal del juego, como es el escenario, 
    los personajes involucrados y demas.

*/

enum class GameState{
    PLAYING,
    GAME_OVER,
    WIN
};

class GameplayScene : public Scene{
    private: 
        GameState current_state; 
        int screen_witdh; 
        int screen_height; 

        // Entidades del nivel
        Character jugador; 
        std::vector<Character> camaras; 
        Map mapa; 
        Rectangle exit_zone; 

        // Metodos internos de logica
        void CheckDetection();
        void ResetGame();

    public: 
        GameplayScene(int screen_width, int screen_height);
        ~GameplayScene() override = default; 

        // Implementacion obligatoria 
        void Update(float deltaTime) override; 
        void Draw() override; 

};
