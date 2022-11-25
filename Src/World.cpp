#include "raylib.h"
#include "raymath.h"

// debugging
#include <iostream>

int screenWidth = 600;
int screenHeight = 300;

int hotBarScale = 2;

int main()
{
    // allow the window to be resized by the user
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    InitWindow(screenWidth, screenHeight, "Minecraft2D");

    // setting up the hotbar
    Texture2D hotBar = LoadTexture("Assets/Textures/MC2D/Assets/GUI/hotbar.png");
    Rectangle hotBarSrc = {0,0,182,22};
    Rectangle hotBarDest = {screenWidth/2 - hotBar.width/2 * hotBarScale, screenHeight - hotBar.height/2 - 20 * hotBarScale, hotBar.width * hotBarScale, hotBar.height * hotBarScale};

    while (!WindowShouldClose())
    {
        // if the current screen dimensions are diffrent
        // from the old screen dimensions, recalculate all GUI components
        if(IsWindowResized()){
            screenHeight = GetScreenHeight();
            screenWidth = GetScreenWidth();
            hotBarDest.x = screenWidth/2 - hotBar.width/2 * hotBarScale;
            hotBarDest.y = screenHeight - hotBar.height/2 - 20 * hotBarScale;
            std::cout << "Display Resized : " << "(" << screenWidth << "," << screenHeight << ")" << std::endl;
        }
        
        BeginDrawing();

        ClearBackground(BLUE);
        
        DrawTexturePro(hotBar, hotBarSrc, hotBarDest, Vector2Zero(), 0, WHITE);

        DrawFPS(10, 10);
     
        EndDrawing();
    }
    CloseWindow();

    return 0;
}