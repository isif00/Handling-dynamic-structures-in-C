#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

// Structure to represent a queue
struct Queue
{
    int front, rear;
    int array[MAX_QUEUE_SIZE];
};

// Function to initialize a queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    return queue;
}

// Function to check if the queue is full
int isFull(struct Queue *queue)
{
    return (queue->rear == MAX_QUEUE_SIZE - 1);
}

// Function to check if the queue is empty
int isEmpty(struct Queue *queue)
{
    return (queue->front == -1);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue *queue, int item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue %d\n", item);
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->array[queue->rear] = item;
    printf("%d enqueued to the queue\n", item);
}

// Function to remove an element from the front of the queue
int dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue\n");
        return -1;
    }

    int item = queue->array[queue->front];
    queue->front++;

    // If the front becomes greater than the rear, reset front and rear to -1
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    printf("%d dequeued from the queue\n", item);
    return item;
}

// Function to get the front element of the queue without removing it
int front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
        return queue->array[queue->front];
    }
}

// Function to get the rear element of the queue without removing it
int rear(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->array[queue->rear];
}