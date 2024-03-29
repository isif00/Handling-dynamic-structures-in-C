#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>

struct memoryPartition
{
    int address;
    int size;
    bool free;
    struct process *allocatedProcess;
    struct memoryPartition *next;
    bool timerState;
    double startTime;
};

struct memoryPartition *addPartition(struct memoryPartition *head, int address, int size, bool free);
void initializeMemory(struct memoryPartition **head);
void printMemory(struct memoryPartition *memory);
int isMemoryFull(struct memoryPartition **head);
void freeMemory(struct memoryPartition **memory);

#endif
