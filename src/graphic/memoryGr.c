#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "memory.h"
#include "process.h"

// Function to draw a memory partition
void drawMemoryPartition(struct memoryPartition *partition, int yPos, double actualTime)
{
    // Set the color based on whether the partition is free or not
    Color color = partition->free ? GREEN : RED;

    // Draw the filled rectangle representing the partition
    DrawRectangle(20, yPos, 180, 70, color);

    // Draw the borders around the rectangle
    DrawRectangleLinesEx((Rectangle){20, yPos, 180, 70}, 2, BLACK);

    // Draw the text indicating the partition details with vertical spacing
    DrawText(TextFormat("ID: %d", partition->address), 30, yPos + 10, 18, WHITE);
    DrawText(TextFormat("Size: %d", partition->size), 30, yPos + 30, 18, WHITE);

    // If the partition is not free and has an allocated process
    if (!partition->free && partition->allocatedProcess != NULL)
    {
        // Get the process information
        struct process *allocatedProcess = partition->allocatedProcess;

        // Check if allocatedProcess is not NULL before accessing its members
        if (allocatedProcess != NULL)
        {
            // Calculate the remaining time
            double TimePassed = actualTime - allocatedProcess->arrivalTime;

            printf("Time passed: %.2f\n", TimePassed);
            // Display the remaining time
            DrawText(TextFormat("Time: %.2fs", TimePassed), 30, yPos + 50, 12, YELLOW);

            // Check if the countdown timer has reached 0
            if (TimePassed >= allocatedProcess->executionDuration)
            {
                printf("Process with id %d has completed.\n", allocatedProcess->id);

                // Deallocate the process from the partition
                partition->free = true;
                free(partition->allocatedProcess);
                partition->allocatedProcess = NULL;
            }
        }
    }
}

// Function to draw the memory layout
void drawMemoryLayout(struct memoryPartition *memory, double actualTime)
{
    int yPos = 20; // Starting y-position

    while (memory != NULL)
    {
        // Draw the current memory partition
        drawMemoryPartition(memory, yPos, actualTime);

        // Move to the next row
        yPos += 71;

        // Move to the next partition in the linked list
        memory = memory->next;
    }
}