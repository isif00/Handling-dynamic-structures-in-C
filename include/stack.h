#ifndef STACK_H
#define STACK_H

#include "queue.h"

struct Stack
{
    struct Queue *data;
    struct Stack *next;
};

void initializeStack(struct Stack *stack);
int isStackEmpty(struct Stack *stack);
void push(struct Stack *stack, struct Queue *queue);
struct Queue *pop(struct Stack *stack);
void printStack(struct Stack *stack);
#endif
