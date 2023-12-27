#ifndef UTILS_H
#define UTILS_H

#include "queue.h"
#include "memory.h"

int randomizer(int min, int max);
void initializeProcessesQueue(struct Queue *queue);
void firstFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue);
void bestFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue);
void worstFitUntilFull(struct memoryPartition **memory, struct Queue *processQueue);

#endif