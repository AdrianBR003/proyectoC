#include "Game.hpp"
#include <raylib.h>

Game::Game(int screenWidth, int screenHeight, const std::string& windowTitle){
    width = screenWidth; 
    height = screenHeight; 
    title = windowTitle;
    coor_x = 400.0f; 
    coor_y = 300.0f;
    size = 50.0f;
    speed = 200.0f; 

    InitWindow(width, height, title.c_str());
    SetTargetFPS(60);
}

Game::~Game(){
    CloseWindow();
}

void Game::Run(){
    while(!WindowShouldClose()){
        Update();
        Draw();
    }
}

void Game::Update(){
    TraceLog(LOG_INFO, "Coordenada X %.2f -- Coordenada Y %.2f ", coor_x, coor_y);

    if(IsKeyDown(KEY_RIGHT)){
        if(coor_x < 800 - size){
            coor_x += speed * GetFrameTime();
        }
    } 

    if(IsKeyDown(KEY_LEFT)){
        if(coor_x > 0){
            coor_x -= speed * GetFrameTime();
        }
    } 

    if(IsKeyDown(KEY_DOWN)){
        if(coor_y < 600 - size){
        coor_y += speed * GetFrameTime();
        }
    }  

    if(IsKeyDown(KEY_UP)){
        if(coor_y > 0){
            coor_y -= speed * GetFrameTime();
        }
    } 
}
 
void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(coor_x, coor_y, size, size, RED);
    EndDrawing();
}