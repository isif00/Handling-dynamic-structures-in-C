#include <stdio.h>
#include <stdlib.h>
#include "process.h"
#include "queue.h"
#include "memory.h"
#include "allocation.h"
#include "stack.h"

#define MAX_PROCESSES 10

// Function to generate a random number
int randomizer(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

// Function to create a process
void initializeProcessesQueue(struct Queue *queue, struct process *processArray)
{
    int numProcesses = randomizer(3, 5);

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

// Function to print the queue
void firstFitUntilFull(struct memoryPartition **memory, struct Queue *newQueue)
{
    // Keep allocating processes until memory is full
    while (!isMemoryFull(memory) && !isEmpty(newQueue))
    {
        struct process *currentProcess = dequeue(newQueue);
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

// Function to print the queue
void bestFitUntilFull(struct memoryPartition **memory, struct Queue *newQueue)
{
    // Keep allocating processes until memory is full
    while (!isMemoryFull(memory) && !isEmpty(newQueue))
    {
        struct process *currentProcess = dequeue(newQueue);
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

// Function to print the queue
void worstFitUntilFull(struct memoryPartition **memory, struct Queue *newQueue)
{
    // Keep allocating processes until memory is full
    while (!isMemoryFull(memory) && !isEmpty(newQueue))
    {
        struct process *currentProcess = dequeue(newQueue);
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

void initializeQueuesStack(struct Stack *stack)
{
    for (int i = 0; i < 2; i++)
    {
        // Create a new queue and push it onto the stack
        struct Queue *newQueue = createQueue();
        struct process priorityProcessArray[MAX_PROCESSES];
        initializeProcessesQueue(newQueue, priorityProcessArray);

        push(stack, newQueue);

        printStack(stack);
    }
}
