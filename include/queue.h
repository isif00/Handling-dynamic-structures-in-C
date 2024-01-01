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
struct process *dequeue(struct Queue *queue);
struct process *front(struct Queue *queue);
struct process *rear(struct Queue *queue);
void printQueue(struct Queue *queue);
int size(struct Queue *queue);

#endif