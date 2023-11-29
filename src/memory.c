#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
