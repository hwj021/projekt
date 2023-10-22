#include <raylib.h>

int main(void){
    const int screenwidth = 800;
    const int screenheight = 800;

    InitWindow(screenwidth, screenheight, "Okno");

    Vector2 ballPosition = { screenwidth/2, screenheight/2 };

    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    
    {
        if (IsKeyDown(KEY_RIGHT)){ ballPosition.x = ballPosition.x + 2;}
        if (IsKeyDown(KEY_LEFT)){ ballPosition.x = ballPosition.x - 2;}
        if (IsKeyDown(KEY_UP)){ ballPosition.y = ballPosition.y - 2;}
        if (IsKeyDown(KEY_DOWN)){ ballPosition.y = ballPosition.y + 2;}
        BeginDrawing();


        ClearBackground(ORANGE);

        DrawCircleV(ballPosition, 100, YELLOW);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}