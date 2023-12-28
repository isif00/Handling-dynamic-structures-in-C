#include <stdio.h>
#include <stdlib.h>
#include "../include/raylib.h"
#include "../../include/memory.h"
#include "../../include/process.h"

// Function to draw a memory partition
void drawMemoryPartition(struct memoryPartition *partition, int yPos)
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

    // If the partition is not free and the countdown timer is running
    if (!partition->free && partition->allocatedProcess != NULL)
    {
        // Get the process information
        struct process *allocatedProcess = partition->allocatedProcess;

        // Calculate the remaining time
        double remainingTime = allocatedProcess->executionDuration - (GetTime() - allocatedProcess->arrivalTime);

        // Display the remaining time
        DrawText(TextFormat("Time: %.2fs", remainingTime), 30, yPos + 50, 12, YELLOW);

        // Check if the countdown timer has reached 0
        if (remainingTime <= 0)
        {
            printf("Process with id %d has completed.\n", allocatedProcess->id);

            // Deallocate the process from the partition
            partition->free = true;
            free(partition->allocatedProcess);
            partition->allocatedProcess = NULL;
        }
    }
}

// Function to draw the memory layout
void drawMemoryLayout(struct memoryPartition *memory)
{
    int yPos = 20; // Starting y-position

    while (memory != NULL)
    {
        // Draw the current memory partition
        drawMemoryPartition(memory, yPos);

        // Move to the next row
        yPos += 71; // Add some padding between partitions

        // Move to the next partition in the linked list
        memory = memory->next;
    }
}