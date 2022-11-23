#include "raylib.h"
#include "raymath.h"

const int screenWidth = 1500;
const int screenHeight = 600;

int hotBarScale = 2;

int main()
{
    InitWindow(screenWidth, screenHeight, "Minecraft2D");

    // setting up the hotbar
    Texture2D hotBar = LoadTexture("Assets/Textures/MC2D/Assets/GUI/hotbar.png");
    Rectangle hotBarSrc = {0,0,182,22};
    Rectangle hotBarDest = {screenWidth/2 - hotBar.width/2 * hotBarScale, screenHeight - 2 - hotBar.height/2 - 30 * hotBarScale, hotBar.width * hotBarScale, hotBar.height * hotBarScale};

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(BLUE);
        
        DrawTexturePro(hotBar, hotBarSrc, hotBarDest, Vector2Zero(), 0, WHITE);

        DrawFPS(10, 10);
     
        EndDrawing();
    }
    CloseWindow();

    return 0;
}