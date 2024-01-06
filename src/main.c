#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"
#include "memory.h"
#include "queue.h"
#include "process.h"
#include "utils.h"
#include "allocation.h"
#include "memoryGr.h"
#include "queueGr.h"
#include "stack.h"
#include "stackGr.h"

#define MAX_PROCESSES 10
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

int main(void)
{
    // seed the random number generator
    srand(time(NULL));

    // timer state
    bool timerState = false;

    // active button
    int firstPartButton = 1;

    // memory initialization
    struct memoryPartition *memory = NULL;
    initializeMemory(&memory);
    printf("[INFO] Memory partitions initialized\n");

    // initialize process queue
    struct Queue *processQueue = createQueue();

    // Create an array to store processes
    struct process processArray[MAX_PROCESSES];

    // Filling up the  Queue
    initializeProcessesQueue(processQueue, processArray);

    // #################################################
    // Initialize the Queue with the higher priority
    struct Queue *highPriorityQueue = createQueue();

    // Create an array to store processes
    struct process highPriorityprocessArray[MAX_PROCESSES];

    // Filling up the  Queue
    initializeProcessesQueue(highPriorityQueue, highPriorityprocessArray);

    // Stack initialization
    struct Stack queuesStack;
    initializeStack(&queuesStack, highPriorityQueue);
    push(&queuesStack, highPriorityQueue);
    initializeQueuesStack(&queuesStack);

    // ##################################################################
    // setting up the screen proprietiSSes
    const int screenWidth = 1700;
    const int screenHeight = 900;
    double currentTime = 0.0;

    InitWindow(screenWidth, screenHeight, "Memory Simulation");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        // Draw
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw the menu buttons
        int buttonWidth = 150;
        int buttonHeight = 40;
        int buttonSpacing = 20;

        // Draw the Parts buttons
        float buttonX = (screenWidth - (2 * buttonWidth + 2 * buttonSpacing)) / 2;
        int buttony = screenHeight - 180;

        // Draw the method's buttons
        float methodsbuttonX = (screenWidth - (5 * buttonWidth + 2 * buttonSpacing)) / 2;
        int methodsbuttonY = screenHeight - 120;

        // Draw the tillFull method's buttons
        float tillFullMethodsbuttonX = (screenWidth - (3 * buttonWidth + 2 * buttonSpacing)) / 2;
        int tillFullMethodsbuttonY = screenHeight - 60;

        if (GuiButton((Rectangle){buttonX, buttony, buttonWidth, buttonHeight}, "Part 1"))
        {
            firstPartButton = 1;
        }

        buttonX += buttonWidth + buttonSpacing;

        if (GuiButton((Rectangle){buttonX, buttony, buttonWidth, buttonHeight}, "Part 2"))
        {
            firstPartButton = 0;
        }

        if (firstPartButton)
        {
            // Draw the process queue
            drawVerticalQueue(processQueue, processArray);

            // Draw the method's buttons
            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Re-initialize Memory"))
            {
                // Free the memory partitions
                freeMemory(&memory);

                // Initialize new memory partitions
                initializeMemory(&memory);
                printf("[INFO] Memory partitions Re-initialized\n");
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Re-initialize process queue"))
            {
                // initialize process queue
                processQueue = createQueue();

                // Create an array to store processes
                struct process newprocessArray[MAX_PROCESSES];

                // Filling up the  Queue
                initializeProcessesQueue(processQueue, processArray);
                drawVerticalQueue(processQueue, processArray);
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Best Fit"))
            {
                struct process *partition = dequeue(processQueue);
                timerState = true;
                bestFit(&memory, partition);
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "First Fit"))
            {
                struct process *partition = dequeue(processQueue);
                timerState = true;
                firstFit(&memory, partition);
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Worst Fit"))
            {
                struct process *partition = dequeue(processQueue);
                worstFit(&memory, partition);
            }

            // Draw the tillFull method's buttons
            if (GuiButton((Rectangle){tillFullMethodsbuttonX, tillFullMethodsbuttonY, buttonWidth, buttonHeight}, "Best Fit until full"))
            {
                timerState = true;
                bestFitUntilFull(&memory, processQueue);
            }

            tillFullMethodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){tillFullMethodsbuttonX, tillFullMethodsbuttonY, buttonWidth, buttonHeight}, "First Fit until full"))
            {
                timerState = true;
                firstFitUntilFull(&memory, processQueue);
            }

            tillFullMethodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){tillFullMethodsbuttonX, tillFullMethodsbuttonY, buttonWidth, buttonHeight}, "Worst Fit until full"))
            {
                timerState = true;
                worstFitUntilFull(&memory, processQueue);
            }
        }
        else if (!firstPartButton)
        {
            // Draw the process queue
            drawVerticalQueue(highPriorityQueue, highPriorityprocessArray);

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Re-initialize Memory"))
            {
                // Free the memory partitions
                freeMemory(&memory);

                // Initialize new memory partitions
                initializeMemory(&memory);
                printf("[INFO] Memory partitions Re-initialized\n");
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Best Fit"))
            {
                if (!isStackEmpty(&queuesStack))
                {
                    if (!isEmpty(highPriorityQueue))
                    {
                        printf("first queu");
                        struct process *highPriorityPartition = dequeue(highPriorityQueue);
                        timerState = true;
                        bestFit(&memory, highPriorityPartition);
                    }
                    else
                    {
                        printf("second queue");
                        highPriorityQueue = pop(&queuesStack);
                    }
                }
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "First Fit"))
            {
                if (!isStackEmpty(&queuesStack))
                {
                    if (!isEmpty(highPriorityQueue))
                    {
                        struct process *highPriorityPartition = dequeue(highPriorityQueue);
                        timerState = true;
                        firstFit(&memory, highPriorityPartition);
                    }
                    else
                    {
                        printf("second queue");
                        highPriorityQueue = pop(&queuesStack);
                    }
                }
            }

            methodsbuttonX += buttonWidth + buttonSpacing;

            if (GuiButton((Rectangle){methodsbuttonX, methodsbuttonY, buttonWidth, buttonHeight}, "Worst Fit"))
            {
                if (!isStackEmpty(&queuesStack))
                {
                    if (!isEmpty(highPriorityQueue))
                    {
                        printf("first queu");
                        struct process *highPriorityPartition = dequeue(highPriorityQueue);
                        timerState = true;
                        worstFit(&memory, highPriorityPartition);
                    }
                    else
                    {
                        printf("second queue");
                        highPriorityQueue = pop(&queuesStack);
                    }
                }
            }

            // Draw the queues stack
            printStack(&queuesStack);
            drawVerticalStack(&queuesStack);
        }

        // Draw the memory layout
        drawMemoryLayout(memory, &timerState);

        // Draw the memory table
        drawMemoryTable(memory);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
