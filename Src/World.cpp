#include "raylib.h"
#include "raymath.h"

#include "Config.hpp"

// debugging
#include <iostream>

int screenWidth = 600;
int screenHeight = 300;

int main()
{
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidth, screenHeight, "Minecraft2D (DEBUG)");

    // configuring the hotBar
    hotBar.x = 0;
    hotBar.y = 0;
    hotBar.width = 182;
    hotBar.height = 22;
    hotBar.scale = 2;
    hotBar.screenX = screenWidth;
    hotBar.screenY = screenHeight;
    hotBar.texture = LoadTexture("Assets/Textures/MC2D/assets/minecraft/textures/gui/widgets.png");

    hotBar.src = (Rectangle){hotBar.x,
                              hotBar.y,
                              hotBar.width,
                              hotBar.height};

    hotBar.dest = (Rectangle){hotBar.screenX / 2 - hotBar.width / 2 * hotBar.scale,
                               hotBar.screenY - hotBar.height / 2 - 20 * hotBar.scale,
                               hotBar.width * hotBar.scale,
                               hotBar.height * hotBar.scale};

    // main game loop
    while (!WindowShouldClose())
    {
        // if the current screen dimensions are diffrent
        // from the old screen dimensions, recalculate all GUI components
        if (IsWindowResized())
        {
            screenHeight = GetScreenHeight();
            screenWidth = GetScreenWidth();
            hotBar.dest.x = screenWidth / 2 - hotBar.width / 2 * hotBar.scale;
            hotBar.dest.y = screenHeight - hotBar.height / 2 - 20 * hotBar.scale;
        }

        BeginDrawing();

        ClearBackground(BLUE);

        DrawTexturePro(hotBar.texture, hotBar.src, hotBar.dest, Vector2Zero(), 0, WHITE);

        DrawFPS(10, 10);

        EndDrawing();
    }
    
    CloseWindow();

    return 0;
}