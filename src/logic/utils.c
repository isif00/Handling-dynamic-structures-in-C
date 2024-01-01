#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "queue.h"
#include "memory.h"
#include "allocation.h"

#define MAX_PROCESSES 10

int randomizer(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

void initializeProcessesQueue(struct Queue *queue, struct process *processArray)
{
    int numProcesses = randomizer(3, 7);

    for (int i = 0; i < numProcesses && i < MAX_PROCESSES; i++)
    {
        // Generate random values for the process
        int id = randomizer(50, 1000);
        int arrivalTime = i;
        int executionDuration = randomizer(15, 30);
        int size = randomizer(20, 100);

        // Create a process and enqueue it
        struct process *newProcess = createProcess(id, arrivalTime, executionDuration, size);
        enqueue(queue, newProcess);

        // Store the newProcess in the array
        processArray[i] = *newProcess;
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