#include <stdio.h>
#include <stdlib.h>
#include "../../include/process.h"
#include "../../include/queue.h"
#include "../../include/memory.h"
#include "../../include/allocation.h"

int randomizer(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void initializeProcessesQueue(struct Queue *queue)
{
    int numProcesses = randomizer(1, 2);
    for (int i = 0; i < numProcesses; i++)
    {
        // Generate random values for the process
        int id = randomizer(50, 1000);
        int arrivalTime = i;
        int executionDuration = randomizer(2, 8);
        int size = randomizer(20, 100);

        // Create a process and enqueue it
        struct process *newProcess = createProcess(id, arrivalTime, executionDuration, size);
        enqueue(queue, newProcess);
    }
}

void firstFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue)
{
    // Keep allocating processes until memory is full
    while (!isMemoryFull(memory) && !isEmpty(processQueue))
    {
        struct process *currentProcess = dequeue(processQueue);
        firstFit(memory, currentProcess);
    }

    if (isMemoryFull(memory))
    {
        printf("Memory is full. Unable to allocate more processes.\n");
    }
    else
    {
        printf("Process queue is empty. All processes allocated successfully.\n");
    }
}

void bestFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue)
{
    // Keep allocating processes until memory is full
    while (!isMemoryFull(memory) && !isEmpty(processQueue))
    {
        struct process *currentProcess = dequeue(processQueue);
        bestFit(memory, currentProcess);
    }

    if (isMemoryFull(memory))
    {
        printf("Memory is full. Unable to allocate more processes.\n");
    }
    else
    {
        printf("Process queue is empty. All processes allocated successfully.\n");
    }
}

void worstFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue)
{
    // Keep allocating processes until memory is full
    while (!isMemoryFull(memory) && !isEmpty(processQueue))
    {
        struct process *currentProcess = dequeue(processQueue);
        worstFit(memory, currentProcess);
    }

    if (isMemoryFull(memory))
    {
        printf("Memory is full. Unable to allocate more processes.\n");
    }
    else
    {
        printf("Process queue is empty. All processes allocated successfully.\n");
    }
}