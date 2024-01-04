#ifndef UTILS_H
#define UTILS_H

#include "queue.h"
#include "memory.h"
#include "stack.h"

int randomizer(int min, int max);
void initializeProcessesQueue(struct Queue *queue, struct process *processArray);
void firstFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue);
void bestFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue);
void worstFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue);
void initializeQueuesStack(struct Stack *stack);

#endif