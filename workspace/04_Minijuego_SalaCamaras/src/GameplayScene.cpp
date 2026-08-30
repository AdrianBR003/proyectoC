#include "GameplayScene.hpp"
#include <raylib.h>

GameplayScene::GameplayScene(int w, int h) :

                                             screen_witdh(w),
                                             screen_height(h),
                                             current_state(GameState::PLAYING), // Inicializamos el juego como JUGANDO
                                             mapa(w, h, 50),
                                             jugador({5.0f, 5.0f, 100.0f, 100.0f}, 10, 10, 10, "Jugador", 100)
{
    // Colocamos la salida verde
    exit_zone = { static_cast<float>(w - 120), static_cast<float>(h-120), 80.0f, 80.0f }; 

    // Añadimos un par de camaras estáticas de prueba en el vector

    // Camara 1: x = 300 , y = 200 
    camaras.push_back(Character({5.0f, 5.0f, 300.0f, 200.0f}, 10, 10, 10, "Camara1", 100)); // Necesitariamos crear un objeto sin velocidad
    // Camara 2: x = 500 , y = 400 
    camaras.push_back(Character({5.0f, 5.0f, 500.0f, 400.0f}, 10, 10, 10, "Camara1", 100)); // Necesitariamos crear un objeto sin velocidad

}

void GameplayScene::Update(float deltaTime){
    if (current_state == GameState::PLAYING){
        // 1. Aquí actualizamos el movimiento del jugador usando deltaTime

        // 2. Luego comprobamos si la casilla corresponde a una pixel vacio, a la salida o al area de un enemigo

        // 3. Actuamos en base a lo anterior y actualizamos GameState en caso de perder o ganar
    } else{ 
        // Si perdemos o ganamos, entramos aquí, en ambos casos poner un boton para reiniciar la partida. 

    }
}