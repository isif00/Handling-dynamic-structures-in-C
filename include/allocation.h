#ifndef ALLOCATION_H
#define ALLOCATION_H

void firstFit(struct memoryPartition **memory, struct Queue *processQueue);
void worstFit(struct memoryPartition **memory, struct Queue *processQueue);
void bestFit(struct memoryPartition **memory, struct Queue *processQueue);
#endif