#pragma once

/*
    La clase Scene tiene la finalidad de quitarle la carga de lógica del juego a la clase 'Game', la cual 
    sólo debería de encargarse de los parametros de la pantalla, o la ejecución del propio juego, pero la lógica 
    depende de Scene y de sus hijos. 
*/

class Scene{
    public:
        virtual ~Scene() = default; // Destructor virtual para asegurar limpieza de memoria

        // Métodos virtuales
        virtual void Update(float deltaTime) = 0; // Para evitar lo de los FPS
        virtual void Draw() = 0; 


}