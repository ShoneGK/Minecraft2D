#include "raylib.h"

int main()
{
    InitWindow(800, 600, "Minecraft2D");

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLACK);

        DrawFPS(10, 10);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}