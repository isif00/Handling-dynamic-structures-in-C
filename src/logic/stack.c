#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

// Define the structure for the stack
struct Stack
{
    struct Queue *data;
    struct Stack *next;
};

// Function to initialize an empty stack
void initializeStack(struct Stack *stack, struct Queue *highPriorityQueue)
{
    stack->data = highPriorityQueue;
    stack->next = NULL;
}

// Function to check if the stack is empty
int isStackEmpty(struct Stack *stack)
{
    return (stack->data == NULL);
}

// Function to push a queue reference onto the stack
void push(struct Stack *stack, struct Queue *queue)
{
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));

    newNode->data = queue;
    newNode->next = stack->next;
    stack->next = newNode;
    printf("Queue at address %p pushed into the stack\n", (void *)queue);
}

// Function to pop a queue reference from the stack
struct Queue *pop(struct Stack *stack)
{
    // Make sure stack is not empty
    if (isStackEmpty(stack))
    {
        return NULL;
    }

    struct Queue *poppedQueue = stack->next->data; // Access the data of the top element
    struct Stack *temp = stack->next;

    stack->next = temp->next; // Update the next pointer to the next node

    // Free the memory of the popped node
    free(temp);

    return poppedQueue;
}

// Print stack elements
void printStack(struct Stack *stack)
{
    printf("Stack Elements:\n");

    struct Stack *current = stack->next;
    while (current != NULL)
    {
        printf("Queue at address %p\n", (void *)current->data);
        current = current->next;
    }

    printf("End of Stack\n");
}
