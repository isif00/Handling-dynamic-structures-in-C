#include <stdio.h>
#include <stdlib.h>
#include "../include/process.h"
#include "../include/queue.h"

int randomizer(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void initializeProcessesQueue(struct Queue *queue)
{
    int numProcesses = randomizer(2, 5);
    for (int i = 0; i < numProcesses; i++)
    {
        // Generate random values for the process
        int id = randomizer(50, 1000);
        int arrivalTime = randomizer(0, 5);
        int executionDuration = randomizer(2, 8);
        int size = randomizer(20, 100);

        // Create a process and enqueue it
        struct process *newProcess = createProcess(id, arrivalTime, executionDuration, size);
        enqueue(queue, newProcess);
    }
}
