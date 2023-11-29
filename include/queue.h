#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE_SIZE 100

struct Queue
{
    int front, rear;
    int capacity;
    int array[MAX_QUEUE_SIZE];
};

struct Queue *createQueue(int capacity);
int isEmpty(struct Queue *queue);
void enqueue(struct Queue *queue, int item);
int dequeue(struct Queue *queue);
int front(struct Queue *queue);
int rear(struct Queue *queue);

#endif