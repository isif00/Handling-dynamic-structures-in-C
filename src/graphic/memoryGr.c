#include <stdio.h>
#include "../include/raylib.h"
#include "../../include/memory.h"

// Function to draw a memory partition
void drawMemoryPartition(struct memoryPartition *partition, int yPos)
{
    // Set the color based on whether the partition is free or not
    Color color = partition->free ? GREEN : RED;

    // Draw the rectangle representing the partition
    DrawRectangle(20, yPos, 180, 70, color);

    // Draw the text indicating the partition details
    DrawText(TextFormat("ID: %d\nSize: %d", partition->address, partition->size), 30, yPos + 10, 10, WHITE);
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
        yPos += 70; // Add some padding between partitions

        // Move to the next partition in the linked list
        memory = memory->next;
    }
}