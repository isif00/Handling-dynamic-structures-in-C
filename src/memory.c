#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/utils.h"

struct memoryPartition *addPartition(struct memoryPartition *head, int address, int size, bool free)
{
    struct memoryPartition *newPartition = (struct memoryPartition *)malloc(sizeof(struct memoryPartition));
    if (newPartition == NULL)
    {
        printf("Memory allocation failed\n");
        return NULL;
    }

    newPartition->address = address;
    newPartition->size = size;
    newPartition->free = free;
    newPartition->next = NULL;
    printf("Partition added: address: %d, size: %d, free: %d\n", newPartition->address, newPartition->size, newPartition->free);

    if (head == NULL)
    {
        // If the list is empty, the new partition becomes the head
        return newPartition;
    }
    else
    {
        // Find the last partition in the list and append the new partition
        struct memoryPartition *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = newPartition;
        return head;
    }
}

void initializeMemory(struct memoryPartition **head)
{
    int memorySize = randomizer(2, 6);
    for (int i = 0; i < memorySize; i++)
    {
        // Generate random values for the partitions
        int address = randomizer(50, 1000);
        int size = randomizer(50, 1000);
        int isFree = randomizer(0, 1);

        // Adding a partition to the list
        *head = addPartition(*head, address, size, isFree);
    }
}

void printMemory(struct memoryPartition *memory)
{
    printf("Memory Partitions:\n");
    while (memory != NULL)
    {
        printf("Address: %d, Size: %d, Free: %d\n", memory->address, memory->size, memory->free);
        memory = memory->next;
    }
    printf("\n");
}

// Function to check if the memory is full
int isMemoryFull(struct memoryPartition **head)
{
    struct memoryPartition *current = *head;
    while (current != NULL)
    {
        if (current->free)
        {
            return 0;
        }
        current = current->next;
    }
    return 1;
}