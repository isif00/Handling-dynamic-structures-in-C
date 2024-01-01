#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "memory.h"
#include "process.h"
#include "queue.h"

void drawVerticalQueue(struct Queue *queue, int yPos, struct process *processArray)
{
    int processSpacing = 122;
    int queueSize = size(queue);

    // Calculate the total width of the table
    int totalWidth = queueSize * 140 + 2 * 22;

    // Calculate the starting X position to center the table
    int xPos = (1000 - totalWidth) / 2;

    // Draw processes in the queue
    for (int i = queue->front; i <= queue->rear; i++)
    {

        // Draw text indicating process details from the processArray
        if (!isEmpty(queue))
        {
            // Draw a rectangle representing the process
            DrawRectangle(xPos, yPos, 140, 120, BLUE);

            // Draw the borders around the rectangle
            DrawRectangleLinesEx((Rectangle){xPos, yPos, 140, 120}, 2, BLACK);

            // Draw the text indicating the process detail
            DrawText(TextFormat("ID: %d", processArray[i].id), xPos + 10, yPos + 10, 16, WHITE);
            DrawText(TextFormat("Arrival Time: %d", processArray[i].arrivalTime), xPos + 10, yPos + 30, 10, WHITE);
            DrawText(TextFormat("Execution Time: %d", processArray[i].executionDuration), xPos + 10, yPos + 50, 10, WHITE);
        }

        // Increment xPos to draw the next process
        xPos += processSpacing;

        // check if the queue is empty
        if (isEmpty(queue))
        {
            DrawText("Queue is empty", xPos - 190, 700, 35, RED);
            return;
        }
    }
}
