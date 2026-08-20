#include "Game.hpp"
#include "Character.hpp"
#include "Map.hpp"
#include <raylib.h>
#include <vector>

Game::Game(int width_screen, int height_screen, const std::string& title_screen,
    int width_pixel, int height_pixel, int pixel_size) :
    // Variables pantalla
    game_width_screen(width_screen),
    game_height_screen(height_screen),
    game_title_screen(title_screen),
    // Variables serializadas
    game_width_pixel(width_pixel),
    game_height_pixel(height_pixel),
    game_pixel_size(pixel_size),

    // Como tenemos las variables serializadas, son estas las que le pasamos a los 
    // objetos como mapa, character y demas. Le pasamos las variables para el tamanyo y demas SERIALIZADAS

    mapaComplete(game_width_pixel, game_height_pixel, game_pixel_size),
    character({static_cast<float>(3*game_pixel_size),static_cast<float>(3*game_pixel_size),static_cast<float>(1*game_pixel_size),static_cast<float>(1*game_pixel_size)},
     250.0f, (90.0f * (PI / 180.0f)), 60.0f, "Heroe", 100),
    centinela({static_cast<float>(3*game_pixel_size),static_cast<float>(3*game_pixel_size),static_cast<float>(1*game_pixel_size),static_cast<float>(1*game_pixel_size)},
     250.0f, (90.0f * (PI / 180.0f)), 60.0f, "Centinela", 100)
    {

    // Init Window
    InitWindow(game_width_screen, game_height_screen, game_title_screen.c_str());
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

    // Calculo de colision y movimiento en GAME

    bool isCollision = false; 
    // Rectangle pos futura 
    Rectangle char_posi_future = {0, 0, 0, 0};
    Rectangle rec_obstacle = {0, 0, 0, 0};

    const std::vector<std::vector<int>> mapa_vector = mapaComplete.getMap();

    TraceLog(LOG_INFO, "Coordenada Anterior X %.2f -- Coordenada Anterior Y %.2f ", character.getPosX(), character.getPosY());

    char_posi_future = character.getFutureBounds(game_width_screen, game_height_screen, mapa_vector.size()); // Le pasa la posicion del personaje

    TraceLog(LOG_INFO, "MAPA Coordenadas X %.2d -- Coordenada Y %.2d ", game_width_pixel, game_height_pixel);

    TraceLog(LOG_INFO, "Coordenada Futura X %.2f -- Coordenada Futura Y %.2f ", char_posi_future.x, char_posi_future.y);


    // static_cast<float>(i * game_width_pixel)
    for(size_t i = 0; i < mapa_vector.size(); ++i){
        for(size_t j = 0; j < mapa_vector[i].size(); ++j ){
            if(mapa_vector[i][j] == 1){
                rec_obstacle = {static_cast<float>(i * game_pixel_size), static_cast<float>(j*game_pixel_size),static_cast<float>(1*game_pixel_size), static_cast<float>(1*game_pixel_size)};
                TraceLog(LOG_INFO, "Obstaculo Coordenada X %.2f -- Coordenada Y %.2f -- Ancho %.2f -- Alto %.2f ", rec_obstacle.x, rec_obstacle.y, rec_obstacle.width, rec_obstacle.height);
                isCollision = CheckCollisionRecs(char_posi_future, rec_obstacle);
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
        character.setPosX(char_posi_future.x);
        character.setPosY(char_posi_future.y); 
    }else{
        TraceLog(LOG_INFO, "COLISION DETECTADA!");
    }

    // Calculo del RayCasting 

    character.UpdateVision(mapaComplete, game_pixel_size);
    centinela.UpdateVision(mapaComplete, game_pixel_size);
}

void Game::Draw(){
    BeginDrawing();
    ClearBackground(RAYWHITE);


    for(size_t i = 0; i < mapaComplete.getMap().size(); ++i){
        for(size_t j = 0; j < mapaComplete.getMap()[i].size(); ++j ){
            if(mapaComplete.getMap()[i][j] == 1){
                Rectangle rec_obstacle = {static_cast<float>(i * game_pixel_size),static_cast<float>(j * game_pixel_size), static_cast<float>(1* game_pixel_size), static_cast<float>(1* game_pixel_size)};
                DrawRectangleRec(rec_obstacle, BLUE);
            }
        }
    }

    // Dibujar el personaje lo ultimo para evitar que lo tapen 
    DrawRectangle(character.getPosX(), character.getPosY(), character.getSize(), character.getSize(), RED);
    DrawRectangle(centinela.getPosX(), centinela.getPosY(), centinela.getSize(), centinela.getSize(), PURPLE);

    // Raycasting 

    character.DrawVision();
    centinela.DrawVision();

    EndDrawing();
}

