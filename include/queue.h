#ifndef QUEUE_H
#define QUEUE_H

#include "process.h"

#define MAX_QUEUE_SIZE 100

struct Queue
{
    int front, rear;
    int array[MAX_QUEUE_SIZE];
};

struct Queue *createQueue();
int isEmpty(struct Queue *queue);
void enqueue(struct Queue *queue, struct process *item);
int dequeue(struct Queue *queue);
int front(struct Queue *queue);
int rear(struct Queue *queue);

#endif