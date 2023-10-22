#include <raylib.h>
#include <iostream>

int main(void) {
    const int screenWidth = 1200;
    const int screenHeight = 1200;

    InitWindow(screenWidth, screenHeight, "Okno");

    Vector2 ballPosition = { screenWidth / 2, screenHeight / 2 };
    Vector2 point = { GetRandomValue(0, screenWidth), GetRandomValue(0, screenHeight) };
    int score = 0;

    Image image = LoadImage("helicopter.png");
    ImageResize(&image, 250, 250);
    Texture2D texture = LoadTextureFromImage(image);

    SetTargetFPS(165);

    while (!WindowShouldClose()) {
        if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT))) { ballPosition.x += 4; }
        if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT))) { ballPosition.x -= 4; }
        if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP))) { ballPosition.y -= 8; }
        if (IsKeyPressed(KEY_F1)) { score = 0; }
        if (IsKeyPressed(KEY_R)) { point.x = GetRandomValue(50, GetScreenWidth() - 50); point.y = GetRandomValue(50, GetScreenHeight() - 50); score--; }

        ballPosition.y += 4;

        if (ballPosition.y > screenHeight - 70) {
            ballPosition.y = screenHeight - 70;
        }

        if (ballPosition.x < 50) {
            ballPosition.x = 50;
        }

        if (ballPosition.y < 50) {
            ballPosition.y = 50;
        }

        if (ballPosition.x > screenWidth - 50) {
            ballPosition.x = screenWidth - 50;
        }

        if (CheckCollisionCircles(ballPosition, 100, point, 10)) {
            score++;
            std::cout << score << std::endl;
            point.x = GetRandomValue(10, screenWidth - 10);
            point.y = GetRandomValue(10, screenHeight - 20);
        }

            Vector2 texturePosition = { ballPosition.x - texture.width / 2, ballPosition.y - texture.height / 2 };

        BeginDrawing();

        ClearBackground(GREEN);
        DrawCircleV(ballPosition, 100, GREEN);
        DrawText(TextFormat("Wynik: %i", score), 10, 10, 20, LIGHTGRAY);
        DrawCircleV(point, 10, BLACK);
        DrawRectangle(0, screenHeight - 20, screenWidth, 20, BLACK);
        DrawTexture(texture, texturePosition.x, texturePosition.y, WHITE);

        EndDrawing();
    }

    CloseWindow();
    UnloadTexture(texture);
    UnloadImage(image);
    return 0;
}
