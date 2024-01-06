#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "raylib.h"
#include "memory.h"
#include "process.h"

// Function to draw a memory partition
void drawMemoryPartition(struct memoryPartition *partition, int yPos, bool *timerState)
{
    // Set the color based on whether the partition is free or not
    Color color = partition->free ? GREEN : RED;

    // Draw the filled rectangle representing the partition
    DrawRectangle(20, yPos, 180, 70, color);

    // Draw the borders around the rectangle
    DrawRectangleLinesEx((Rectangle){20, yPos, 180, 70}, 2, BLACK);

    // Draw the text indicating the partition details with vertical spacing
    DrawText(TextFormat("ID: %d", partition->address), 30, yPos + 10, 18, WHITE);
    DrawText(TextFormat("SIZE: %d", partition->size), 30, yPos + 30, 18, WHITE);

    // If the partition is not free and has an allocated process
    if (!partition->free && partition->allocatedProcess != NULL)
    {
        // Get the process information
        struct process *allocatedProcess = partition->allocatedProcess;

        // Check if allocatedProcess is not NULL before accessing its members
        if (allocatedProcess != NULL)
        {
            // Calculate the remaining time based on the partition's timerState
            if (partition->timerState)
            {
                double currentTime = GetTime();
                double elapsedTime = currentTime - partition->startTime;
                double remainingTime = allocatedProcess->executionDuration - elapsedTime;

                // Display the remaining time
                DrawText(TextFormat("Time: %.2fs", remainingTime), 30, yPos + 50, 12, YELLOW);
                if (remainingTime <= 0)
                {
                    printf("Process with id %d has completed.\n", allocatedProcess->id);

                    // Deallocate the process from the partition
                    partition->free = true;
                    free(partition->allocatedProcess);
                    partition->allocatedProcess = NULL;

                    // Merge the partition with the next partition if it is free
                    if (partition->next != NULL && partition->next->free)
                    {
                        partition->size += partition->next->size;
                        partition->next = partition->next->next;
                    }
                    partition->timerState = false;
                }
            }
        }
    }
}

// Function to draw the memory layout
void drawMemoryLayout(struct memoryPartition *memory, bool *timerState)
{
    DrawText("Memory Layout", 20, 20, 25, BLACK);

    int yPos = 65;

    while (memory != NULL)
    {
        // Draw the current memory partition
        drawMemoryPartition(memory, yPos, timerState);

        // Move to the next row
        yPos += 71;

        // Move to the next partition in the linked list
        memory = memory->next;
    }
}

void drawMemoryTable(struct memoryPartition *memory)
{
    int tableX = 970;
    int tableY = 65;
    int rowHeight = 40;
    int colWidth = 170;
    int fontSize = 20;
    int rowSpacing = 5;
    int colSpacing = 5;

    // Draw table header
    DrawText("Memory Table", tableX, 30, 25, BLACK);

    DrawRectangle(tableX - 10, 64, 4 * colWidth + 3 * colSpacing + 20, rowHeight, GRAY);
    DrawRectangleLinesEx((Rectangle){tableX - 10, 64, 4 * colWidth + 3 * colSpacing + 20, rowHeight}, 2, BLACK);

    DrawText("ID", tableX, 75, fontSize, BLACK);

    DrawText("Size", tableX + colWidth + colSpacing, 75, fontSize, BLACK);

    DrawText("Free", tableX + 2 * (colWidth + colSpacing), 75, fontSize, BLACK);

    DrawText("Adress", tableX + 3 * (colWidth + colSpacing), 75, fontSize, BLACK);

    // Draw table rows
    struct memoryPartition *currentPartition = memory;
    int rowIndex = 1;

    while (currentPartition != NULL)
    {
        // Calculate row position
        int rowY = (tableY + rowSpacing * 2) + rowIndex * (rowHeight + rowSpacing);

        // Draw background for each row
        DrawRectangle(tableX - 10, rowY - 10, 4 * colWidth + 3 * colSpacing + 20, rowHeight, GRAY);
        DrawRectangleLinesEx((Rectangle){tableX - 10, rowY - 10, 4 * colWidth + 3 * colSpacing + 20, rowHeight}, 2, BLACK);

        // Draw row content with borderlines
        DrawText(TextFormat("%d", currentPartition->address), tableX, rowY, fontSize, BLACK);

        DrawText(TextFormat("%d", currentPartition->size), tableX + colWidth + colSpacing, rowY, fontSize, BLACK);

        DrawText(currentPartition->free ? "Yes" : "No", tableX + 2 * (colWidth + colSpacing), rowY, fontSize, BLACK);

        DrawText(TextFormat("%p", (void *)currentPartition), tableX + 3 * (colWidth + colSpacing), rowY, fontSize, BLACK);

        // Move to the next partition
        currentPartition = currentPartition->next;
        rowIndex++;

        // Move to the next row when full
        if (rowIndex > 7)
        {
            tableX = 230;
            rowY = 0;
            rowIndex = 1;
            tableY = 20;
        }
    }
}
