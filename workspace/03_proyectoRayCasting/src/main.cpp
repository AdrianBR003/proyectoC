#include "Game.hpp"

int main(){
    /*
        Tenemos que pasarle el tamaño del pixel a todos los objetos que lo necesiten, sobre todo a aquellos que 
        tienen fisicas, por lo que serializamos aqui el valor y lo pasamos a Game y este lo pasara al resto -> sz_pixel
    */

    int width_screen = 800; 
    int height_screen = 600; 
    int pixel_size = 50; 

    int width_pixel = width_screen/pixel_size;
    int height_pixel = height_screen/pixel_size;


    Game miJuego(width_screen, height_screen, "Hola Mundo", width_pixel, height_pixel, 50); // 800 / 50 -> 16 x 12 
    miJuego.Run();
    return 0; 
}