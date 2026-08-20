#pragma once
#include <string>
#include <vector> 
#include <raylib.h>
#include <Map.hpp>

class Character{
    private:

        float ch_speed; 
        std::string ch_name; 
        Rectangle ch_rectangle;         
        
        // Cono de vision
        float ch_vision_distance; // Distancia maxima vision
        float ch_vision_angle; // Angulo central hacia donde mira (rad)
        float ch_fov; // Cambio de vision total

        std::vector<Vector2> vision_points; // Cono de vision compueto de vectores (lineas)


    public: 
        Character(Rectangle rectangle, float vision_distance, float vision_angle, float fov, std::string name, float speed);
        ~Character();

    // Metodos Cono vision

        void UpdateVision(const Map& mapa, int size_pixel);
        void DrawVision() const; 

    // Metodos genericos

    Rectangle getFutureBounds(int game_width_pixel, int game_height_pixel, int size_map); 

    Rectangle getRectangle() const { return ch_rectangle; }
    float getPosX() const { return ch_rectangle.x; }
    float getPosY() const { return ch_rectangle.y; }
    float getVision_Distance() const { return ch_vision_distance; }
    int getSize() const { return ch_rectangle.width; }
    std::string getName() const { return ch_name; }

    void setRectangle(Rectangle rectangle) { ch_rectangle = rectangle; }
    void setPosX(float pos_x) { ch_rectangle.x = pos_x; }
    void setPosY(float pos_y) { ch_rectangle.y = pos_y; }
    void setVision_Distance(float vision_distance) { ch_vision_distance = vision_distance; }
    void setSize(int size){ ch_rectangle.width = size; ch_rectangle.height = size; }; 
    void setName(std::string name) { ch_name = name; }

};
