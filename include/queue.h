#ifndef QUEUE_H
#define QUEUE_H

struct Queue
{
    int front, rear;
    int capacity;
    int array[100];
};

struct Queue *createQueue(int capacity);
int isEmpty(struct Queue *queue);
void enqueue(struct Queue *queue, int item);
int dequeue(struct Queue *queue);
int front(struct Queue *queue);
int rear(struct Queue *queue);

#endif