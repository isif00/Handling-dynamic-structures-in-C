#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../raylib/src/raylib.h"
#include "../include/memory.h"
#include "../include/queue.h"
#include "../include/process.h"
#include "../include/utils.h"

int main(void)
{
    // memory initialization
    initializeMemory();

    // initialize process queue
    struct Queue *processQueue = createQueue();

    // add a process to the queue
    enqueue(processQueue, createProcess(randomizer(50, 1000), randomizer(50, 1000), randomizer(50, 1000), randomizer(50, 1000)));
    enqueue(processQueue, createProcess(randomizer(50, 1000), randomizer(50, 1000), randomizer(50, 1000), randomizer(50, 1000)));
    enqueue(processQueue, createProcess(randomizer(50, 1000), randomizer(50, 1000), randomizer(50, 1000), randomizer(50, 1000)));

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
