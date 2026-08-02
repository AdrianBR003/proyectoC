#include "Game.hpp"
#include <raylib.h>
#include <vector>

Game::Game(int screenWidth, int screenHeight, const std::string& windowTitle){
    width = screenWidth; 
    height = screenHeight; 
    title = windowTitle;
    
    //Character
    character_x = 400.0f; 
    character_y = 300.0f;
    character_size = 50.0f;
    character_speed = 200.0f; 

    // MAP
    initMap();

    // Init Window
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

    // Movimiento predictivo character
    float ch_future_X = character_x; 
    float ch_future_Y = character_y;

    // 1. Calculamos la posicion futura del personaje

    if(IsKeyDown(KEY_RIGHT)){
        if( ch_future_X < 800 - character_size){
            ch_future_X += character_speed * GetFrameTime(); 
        }
    }

    if(IsKeyDown(KEY_LEFT)){
        if(ch_future_X > 0){
            ch_future_X -= character_speed * GetFrameTime();
        }
    }

    if(IsKeyDown(KEY_DOWN)){
        if(ch_future_Y < 600 - character_size){
            ch_future_Y += character_speed * GetFrameTime();
        }
        
    }

    if(IsKeyDown(KEY_UP)){
        if(ch_future_Y > 0){
            ch_future_Y -= character_speed * GetFrameTime();
        }
    }

    // 2. Creamos el Rectangle de nuestro personaje usando la posición futura

    Rectangle rec_character = {ch_future_X, ch_future_Y, character_size, character_size};

    /*
        4. Recorremos el array de obstaculos, si en algún momento nos topamos con alguno que ponga un '1' significara que ha ocurrido una colision
        y entonces no modificamos las coordenadas reales, pero en caso de que no, modificamos las coordenadas futuras = reales
    */

    bool isCollision = false; 

    for(size_t i = 0; i < mapa.size(); ++i){
        for(size_t j = 0; j < mapa[i].size(); ++j ){
            if(mapa[i][j] == 1){
                Rectangle rec_obstacle = {(int) i * tamPix_X, (int) j*tamPix_Y, tamPix_X, tamPix_Y};
                isCollision = CheckCollisionRecs(rec_character, rec_obstacle);
                if(isCollision){
                    break;
                }
            }
        }
        if(isCollision){
            break;
        }
    }

    // 5. En caso de que no haya colision, no le pasa las variables futuras, por lo que sería como si no se hubiera movido

    if(!isCollision){
        TraceLog(LOG_INFO, "Coordenada X %.2f -- Coordenada Y %.2f ", ch_future_X, ch_future_Y);
        character_x = ch_future_X; 
        character_y = ch_future_Y; 
    }else{
        TraceLog(LOG_INFO, "COLISION DETECTADA!");
    }

}

void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);


    for(size_t i = 0; i < mapa.size(); ++i){
        for(size_t j = 0; j < mapa[i].size(); ++j ){
            if(mapa[i][j] == 1){
                Rectangle rec_obstacle = {static_cast<float>(i * tamPix_X),static_cast<float>(j * tamPix_Y), tamPix_X, tamPix_Y};
                DrawRectangleRec(rec_obstacle, BLUE);
            }
        }
    }

    // Dibujar el personaje lo ultimo para evitar que lo tapen 
    DrawRectangle(character_x, character_y, character_size, character_size, RED);


    EndDrawing();
}

void Game::initMap(){
    tamPix_X = 50;
    tamPix_Y = 50; 

    int mapX = width/tamPix_X;
    int mapY = height/tamPix_Y;

    mapa.assign(mapX, std::vector<int>(mapY, 0));  

    // Coordenadas donde vamos a colocar el obstaculo 
    size_t obs1_X = 4;
    size_t obs2_Y = 4;

    // Introducimos un obstaculo en el (0,0) (con 50x50 -> 16x12)
    /*
        Usamos el ++i cuando queremos que en esa linea no solo el valor de 'i' aumente, sino tambien 
        en aquello en lo que lo utilizamos antes de pasar a la siguiente linea
    */
    for(size_t i = 0; i < mapa.size(); ++i){
        for(size_t j = 0; j < mapa[i].size(); ++j ){
            if(i==obs1_X && j==obs2_Y){
                mapa[i][j] = 1;
            }
        }
    }
}