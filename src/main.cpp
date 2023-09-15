#include <raylib.h>

int main(void){
    const int screenwidth = 800;
    const int screenheight = 800;

    InitWindow(screenwidth, screenheight, "Big Juicy Window");

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawCircle(400, 400, 150, BROWN);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}