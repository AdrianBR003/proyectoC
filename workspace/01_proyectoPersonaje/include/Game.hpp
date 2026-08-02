#pragma once
#include <string>

class Game {
    private:
        int width; 
        int height;
        std::string title;
        float coor_x, coor_y, size, speed;

        void Update();
        void Draw();

    public: 
        Game(int screenWidth, int screenHeight, const std::string& windowTitle);
        ~Game();
        void Run();
};