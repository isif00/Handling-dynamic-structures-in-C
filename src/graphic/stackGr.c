#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "stack.h"

void drawVerticalStack(struct Stack *stack)
{
    int processSpacing = 122;

    // Calculate the total width of the table
    int totalWidth = 3 * 140 + 2 * 22;

    DrawText("Stack Processes", 455, 470, 25, BLACK);
    int yPos = 500;
    int xPos = 450;

    int i = 1;
    // Draw text indicating process details from the processArray
    struct Stack *current = stack->next;
    while (current != NULL)
    {
        // Draw a rectangle representing the process
        DrawRectangle(xPos, yPos, 140, 120, BLUE);

        // Draw the borders around the rectangle
        DrawRectangleLinesEx((Rectangle){xPos, yPos, 140, 120}, 2, BLACK);

        // Draw the text indicating the process detail
        DrawText(TextFormat("Priority: %d", i), xPos + 10, yPos + 10, 16, WHITE);

        // Increment xPos, priority index, current queue to draw the next process
        i++;
        xPos += processSpacing;
        current = current->next;
    }
}
