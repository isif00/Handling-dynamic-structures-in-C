#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "raylib.h"
#include "memory.h"
#include "queue.h"
#include "process.h"
#include "utils.h"
#include "allocation.h"
#include "memoryGr.h"

#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void)
{
    // seed the random number generator
    srand(time(NULL));

    // memory initialization
    struct memoryPartition *memory = NULL;
    initializeMemory(&memory);
    printf("[INFO] Memory partitions initialized\n");

    // initialize process queue
    struct Queue *processQueue = createQueue();
    initializeProcessesQueue(processQueue);
    printf("[INFO] Queue processes initialized\n");

    printQueue(processQueue);

    // // Use firstFit function
    // printf("[INFO] Using first fit algorithm\n");
    // struct process *partition = dequeue(processQueue);
    // firstFit(&memory, partition);

    // // Use bestFit function
    // printf("[INFO] Using best fit algorithm\n");
    // bestFit(&memory, processQueue);

    // // Use worstFit function
    // printf("[INFO] Using worst fit algorithm\n");
    // worstFit(&memory, processQueue);

    // // Use firstFitUntilFull function
    // printf("[INFO] Using first fit until full algorithm\n");
    // firstFitUntilFull(&memory, processQueue);

    // // Use bestFitUntilFull function
    // printf("[INFO] Using best fit until full algorithm\n");
    // bestFitUntilFull(&memory, processQueue);

    // // Use worstFitUntilFull function
    // printf("[INFO] Using worst fit until full algorithm\n");
    // worstFitUntilFull(&memory, processQueue);

    printMemory(memory);
    printQueue(processQueue);

    const int screenWidth = 800;
    const int screenHeight = 1000;
    double currentTime = 0.0;

    InitWindow(screenWidth, screenHeight, "Memory Simulation");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Update

        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the allocations method's buttons
        int buttonWidth = 150;
        int buttonHeight = 40;
        int buttonSpacing = 20;
        int buttonX = (screenWidth - (4 * buttonWidth + 2 * buttonSpacing)) / 2;
        int buttonY = screenHeight - 60;

        if (GuiButton((Rectangle){buttonX, buttonY, buttonWidth, buttonHeight}, "Re-initialize Memory"))
        {
            // Free the memory partitions
            freeMemory(&memory);

            // Initialize new memory partitions
            initializeMemory(&memory);
            printf("[INFO] Memory partitions Re-initialized\n");
        }

        buttonX += buttonWidth + buttonSpacing;

        if (GuiButton((Rectangle){buttonX, buttonY, buttonWidth, buttonHeight}, "Best Fit"))
        {
            struct process *partition = dequeue(processQueue);
            currentTime += GetTime();
            bestFit(&memory, partition);
        }

        buttonX += buttonWidth + buttonSpacing;

        if (GuiButton((Rectangle){buttonX, buttonY, buttonWidth, buttonHeight}, "First Fit"))
        {
            struct process *partition = dequeue(processQueue);
            firstFit(&memory, partition);
        }

        buttonX += buttonWidth + buttonSpacing;

        if (GuiButton((Rectangle){buttonX, buttonY, buttonWidth, buttonHeight}, "Worst Fit"))
        {
            struct process *partition = dequeue(processQueue);
            worstFit(&memory, partition);
        }

        // Draw the memory layout
        drawMemoryLayout(memory, currentTime);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow();

    return 0;
}
