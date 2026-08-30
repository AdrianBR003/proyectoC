#include "Character.hpp"
#include <raylib.h>
#include <vector>
#include <string> 
#include <cmath> 


Character::Character(Rectangle rectangle, float vision_distance, float vision_angle, float fov, std::string name, float speed)
    : ch_rectangle(rectangle), ch_vision_distance(vision_distance), ch_vision_angle(vision_angle), ch_fov(fov), ch_name(name), ch_speed(speed) 
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

/*
    Metodo para calcular el cono de vision. La idea es calcular los vectores cada X pasos, para ello conocemos el punto de origen pero necesitamos calcular 
    ese avance de cada uno de los vectores de vision. Luego, una vez que avancen comprobamos si ese avance ha hecho que choque contra algo que estuviera 
    en ese pixel, en la clase Map. Para comprobarlo, es necesario serializar el vector e indicar si había algo, en caso de que no, sigue avanzando hasta encontrar algo, 
    entonces ya tienes la coordenada final de ese vector (linea de vision) y avanza con la siguiente linea de vision y así sucesivamente hasta completar el arco de vision. 
*/ 


void Character::UpdateVision(const Map& mapa, int size_pixel){
    // 1. Primero limpiamos el vector de puntos 
    vision_points.clear();

    // 2. Definimos el origen del rayo en el centro del personaje 
    Vector2 origen = { ch_rectangle.x + ch_rectangle.width/2.0f, ch_rectangle.y + ch_rectangle.height/2.0f };

    // 3. Decicimos cuantos rayos lanzar, por ejemplo 40 rayos para el arco de vision
    int num_rayos = 40; 
    float angulo_inicio = ch_vision_angle - (ch_fov / 2.0f); // Si el angulo de vision es de 60 grados, empieza en 30 grados y le quita el total (fov) / 2, para que empiece en -30 y así el rango vaya de -30 pase por 0 y luego hasta + 30
    float paso_angulo = ch_fov / static_cast<float>(num_rayos);

    // 4. Lanzamos cada rayo 
    for (int i = 0; i< num_rayos; i++){
        float angulo_actual = angulo_inicio + (i*paso_angulo); // Aumenta cada grado

        // Calculamos el vector de direccion unitario usando trigonometria 
        Vector2 direccion = {cosf(DEG2RAD*angulo_actual), sinf(DEG2RAD*angulo_actual)}; // Pilla la direccion del vector 
        Vector2 punto_final = origen; // Parte del origen y ahora lo iremos avanzando hasta encontrar un obstaculo o el tamanyo maximo

        for (float dist = 0.0f; dist < ch_vision_distance; dist+=4.0f){

         // el ultimo parametro es el paso de cada comprobacion del vector (diría que se podría aumentar si cada pixel es de 50)
            Vector2 punto_actual = {
                origen.x + direccion.x*dist,
                origen.y + direccion.y*dist
            };

            // Desserializamos el vector a coordenadas de nuestra matrix (mapa)

            int celda_x = static_cast<int>(punto_actual.x) / size_pixel; 
            int celda_y = static_cast<int>(punto_actual.y) / size_pixel; 

            // Comprobamos la colision usando el metodo isMuro de tu clase Map
            if(mapa.isMuro(celda_x,celda_y)){
                punto_final = punto_actual; // Encontro un obstaculo, por lo que detenemos el for y copiamos el punto final del vector, para saber hasta donde dibujarlo
                break; 
            }

            punto_final = punto_actual; // Si no chocó, que se siga extendiendo hasta llegar al límite
        }

        // Guardamos el punto donde termino el rayo
        vision_points.push_back(punto_final);

    }
}

void Character::DrawVision() const{
    Vector2 origen = {ch_rectangle.x + ch_rectangle.width/2.0f, ch_rectangle.y + ch_rectangle.height/2.0f};

    // Dibujamos una linea por cada punto de impacto que calculamos
    for (const auto& punto_impacto : vision_points){
        DrawLineV(origen, punto_impacto, ColorAlpha(YELLOW, 0.5f));
    }
}