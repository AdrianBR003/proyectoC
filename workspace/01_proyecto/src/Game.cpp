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
    if(IsKeyDown(KEY_RIGHT)) coor_x += speed * GetFrameTime();
    if(IsKeyDown(KEY_LEFT)) coor_x -= speed * GetFrameTime();
    if(IsKeyDown(KEY_DOWN)) coor_y += speed * GetFrameTime(); // Sumar para bajar
    if(IsKeyDown(KEY_UP)) coor_y -= speed * GetFrameTime();   // Restar para subir
}

void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);
    DrawRectangle(coor_x, coor_y, size, size, RED);
    EndDrawing();
}