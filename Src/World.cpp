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
    hotBars.x = 0;
    hotBars.y = 0;
    hotBars.width = 182;
    hotBars.height = 22;
    hotBars.scale = 2;
    hotBars.screenX = screenWidth;
    hotBars.screenY = screenHeight;
    hotBars.texture = LoadTexture("Assets/Textures/BareBones/assets/minecraft/textures/gui/widgets.png");

    hotBars.src = (Rectangle){hotBars.x,
                              hotBars.y,
                              hotBars.width,
                              hotBars.height};

    hotBars.dest = (Rectangle){hotBars.screenX / 2 - hotBars.width / 2 * hotBars.scale,
                               hotBars.screenY - hotBars.height / 2 - 20 * hotBars.scale,
                               hotBars.width * hotBars.scale,
                               hotBars.height * hotBars.scale};

    while (!WindowShouldClose())
    {
        // if the current screen dimensions are diffrent
        // from the old screen dimensions, recalculate all GUI components
        if (IsWindowResized())
        {
            screenHeight = GetScreenHeight();
            screenWidth = GetScreenWidth();
            hotBars.dest.x = screenWidth / 2 - hotBars.width / 2 * hotBars.scale;
            hotBars.dest.y = screenHeight - hotBars.height / 2 - 20 * hotBars.scale;
        }

        BeginDrawing();

        ClearBackground(BLUE);

        DrawTexturePro(hotBars.texture, hotBars.src, hotBars.dest, Vector2Zero(), 0, WHITE);

        DrawFPS(10, 10);

        EndDrawing();
    }
    CloseWindow();

    return 0;
}