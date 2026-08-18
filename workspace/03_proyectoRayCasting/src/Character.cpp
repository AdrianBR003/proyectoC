#include "Character.hpp"
#include <raylib.h>
#include <vector>
#include <string> 


Character::Character(Rectangle rectangle, float vision_distance, std::string name, float speed)
    : ch_rectangle(rectangle), ch_vision_distance(vision_distance), ch_name(name), ch_speed(speed) 
{
   
}

Character::~Character(){}

/*
    Hay que pasarle el tamanyo de la pantalla en los pixeles originales para que se los reste, porque el movimiento como tal
    no está serializado por pixeles, sino que se mueve con los pixeles originales y con la velocidad que definimos, para que así
    sea más controlado. 
*/
Rectangle Character::getFutureBounds(int game_width_screen, int game_height_screen, int size_map){
    
    // Movimiento predictivo character
    float ch_future_X = this->ch_rectangle.x;
    float ch_future_Y = this->ch_rectangle.y;

    // 1. Calculamos la posicion futura del personaje

    if(IsKeyDown(KEY_RIGHT)){
        if( ch_future_X < game_width_screen - this->ch_rectangle.width ){
            ch_future_X += this->ch_speed * GetFrameTime(); 
        }
    }

    if(IsKeyDown(KEY_LEFT)){
        if(ch_future_X > 0){
            ch_future_X -= this->ch_speed * GetFrameTime();
        }
    }

    if(IsKeyDown(KEY_DOWN)){
        if(ch_future_Y < game_height_screen - this->ch_rectangle.height ){
            ch_future_Y += this->ch_speed * GetFrameTime();
        }
        
    }

    if(IsKeyDown(KEY_UP)){
        if(ch_future_Y > 0){
            ch_future_Y -= this->ch_speed * GetFrameTime();
        }
    }

    // 2. Creamos el Rectangle de nuestro personaje usando la posición futura

    return {ch_future_X, ch_future_Y, this->ch_rectangle.width, this->ch_rectangle.height};

}