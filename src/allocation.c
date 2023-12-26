#include <stdio.h>
#include <stdlib.h>
#include "../include/memory.h"
#include "../include/process.h"
#include "../include/queue.h"

#define PARTITION_MIN_SIZE 50
#define PARTITION_MAX_SIZE 1000

// First Fit Allocation method
void firstFit(struct memoryPartition **memory, struct Queue *processQueue)
{
    struct process *currentprocess = dequeue(processQueue);

    if (currentprocess == NULL)
    {
        printf("No process to allocate.\n");
        return;
    }

    struct memoryPartition *currentPartition = *memory;

    while (currentPartition != NULL)
    {
        if (currentPartition->free && currentPartition->size >= currentprocess->size)
        {
            // Allocate the process to the current partition
            currentPartition->free = false;

            // Check if we need to create a new partition for the remaining memory
            if (currentPartition->size > currentprocess->size)
            {
                struct memoryPartition *newPartition = (struct memoryPartition *)malloc(sizeof(struct memoryPartition));
                newPartition->address = currentPartition->address + currentprocess->size;
                newPartition->size = currentPartition->size - currentprocess->size;
                newPartition->free = true;
                newPartition->next = currentPartition->next;
                currentPartition->size = currentprocess->size;
                currentPartition->next = newPartition;
            }

            printf("process with id %d allocated to memory partition starting at address %d\n", currentprocess->id, currentPartition->address);
            return;
        }

        currentPartition = currentPartition->next;
    }

    printf("process with id %d could not be allocated.\n", currentprocess->id);
}

// Best Fit Allocation method
void bestFit(struct memoryPartition **memory, struct Queue *processQueue)
{
    struct process *currentProcess = dequeue(processQueue);

    if (currentProcess == NULL)
    {
        printf("No process to allocate.\n");
        return;
    }

    struct memoryPartition *bestFitPartition = NULL;
    int minResidue = PARTITION_MAX_SIZE;

    struct memoryPartition *currentPartition = *memory;

    while (currentPartition != NULL)
    {
        if (currentPartition->free && currentPartition->size >= currentProcess->size)
        {
            int residue = currentPartition->size - currentProcess->size;

            if (residue < minResidue)
            {
                minResidue = residue;
                bestFitPartition = currentPartition;
            }
        }

        currentPartition = currentPartition->next;
    }

    if (bestFitPartition != NULL)
    {
        // Allocate the process to the best fit partition
        bestFitPartition->free = false;

        // Check if we need to create a new partition for the remaining memory
        if (bestFitPartition->size > currentProcess->size)
        {
            struct memoryPartition *newPartition = (struct memoryPartition *)malloc(sizeof(struct memoryPartition));
            newPartition->address = bestFitPartition->address + currentProcess->size;
            newPartition->size = bestFitPartition->size - currentProcess->size;
            newPartition->free = true;
            newPartition->next = bestFitPartition->next;
            bestFitPartition->size = currentProcess->size;
            bestFitPartition->next = newPartition;
        }

        printf("Process with id %d allocated to memory partition starting at address %d\n", currentProcess->id, bestFitPartition->address);
    }
    else
    {
        printf("Process with id %d could not be allocated.\n", currentProcess->id);
    }
}

// Worst Fit Allocation method
void worstFit(struct memoryPartition **memory, struct Queue *processQueue)
{
    struct process *currentProcess = dequeue(processQueue);

    if (currentProcess == NULL)
    {
        printf("No process to allocate.\n");
        return;
    }

    struct memoryPartition *worstFitPartition = NULL;
    int maxResidue = PARTITION_MIN_SIZE;

    struct memoryPartition *currentPartition = *memory;

    while (currentPartition != NULL)
    {
        if (currentPartition->free && currentPartition->size >= currentProcess->size)
        {
            int residue = currentPartition->size - currentProcess->size;

            if (residue > maxResidue)
            {
                maxResidue = residue;
                worstFitPartition = currentPartition;
            }
        }

        currentPartition = currentPartition->next;
    }

    if (worstFitPartition != NULL)
    {
        // Allocate the process to the worst fit partition
        worstFitPartition->free = false;

        // Check if we need to create a new partition for the remaining memory
        if (worstFitPartition->size > currentProcess->size)
        {
            struct memoryPartition *newPartition = (struct memoryPartition *)malloc(sizeof(struct memoryPartition));
            newPartition->address = worstFitPartition->address + currentProcess->size;
            newPartition->size = worstFitPartition->size - currentProcess->size;
            newPartition->free = true;
            newPartition->next = worstFitPartition->next;
            worstFitPartition->size = currentProcess->size;
            worstFitPartition->next = newPartition;
        }

        printf("Process with id %d allocated to memory partition starting at address %d\n", currentProcess->id, worstFitPartition->address);
    }
    else
    {
        printf("Process with id %d could not be allocated.\n", currentProcess->id);
    }
}
