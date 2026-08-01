#include <raylib.h>

int main() {
    // 1. Inicializamos la ventana directamente
    InitWindow(800, 600, "Prueba de Fuego");
    SetTargetFPS(60);

    // 2. Bucle principal
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        // VAMOS A PINTARLO DE ROJO. Si ves blanco, es que OpenGL está roto.
        ClearBackground(RED); 
        
        // Un texto simple para ver si renderiza
        DrawText("Si ves esto, funciona!", 200, 200, 20, WHITE);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}