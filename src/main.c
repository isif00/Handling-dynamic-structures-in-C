#include <stdio.h>
#include "../raylib/src/raylib.h"
#include "../include/memory.h"
#include "../include/queue.h"

int main(void)
{
    // Initialize the window
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Red Square Example");

    SetTargetFPS(60); // Set the frames per second

    // Main game loop
    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE); // Clear the background

        // Draw a red square
        DrawRectangle(screenWidth / 4, screenHeight / 4, screenWidth / 2, screenHeight / 2, RED);

        EndDrawing();
    }

    // Close the window
    CloseWindow();

    return 0;
}
