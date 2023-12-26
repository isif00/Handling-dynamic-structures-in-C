#ifndef MEMORY_H
#define MEMORY_H

#include <stdbool.h>

struct memoryPartition
{
    int address;
    int size;
    bool free;
    struct memoryPartition *next;
};

struct memoryPartition *addPartition(struct memoryPartition *head, int address, int size, bool free);
void initializeMemory(struct memoryPartition **head);
void printMemory(struct memoryPartition *memory);

#endif
