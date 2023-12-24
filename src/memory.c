#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../include/utils.h"

struct memoryPartition
{
    int address;
    int size;
    bool free;
    struct memoryPartition *next;
};

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

void initializeMemory()
{
    struct memoryPartition *head = NULL;
    struct memoryPartition *memoryPartition;

    int memorySize = randomizer(5, 15);
    for (int i = 0; i < memorySize; i++)
    {
        // Generate a random values for the partitions
        int adress = randomizer(50, 1000);
        int size = randomizer(50, 1000);
        int isFree = randomizer(0, 1);

        // adding a partition to the list
        memoryPartition = addPartition(head, adress, size, isFree);
    }
}