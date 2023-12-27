#include <stdio.h>
#include <stdlib.h>
#include "../../include/process.h"

#define MAX_QUEUE_SIZE 100

// Structure to represent a queue
struct Queue
{
    int front, rear;
    struct process *array[MAX_QUEUE_SIZE];
};

// Function to initialize a queue
struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL)
    {
        printf("Memory allocation failed for the queue\n");
        return NULL;
    }

    queue->front = queue->rear = -1;

    // Initialize all pointers in the array to NULL
    for (int i = 0; i < MAX_QUEUE_SIZE; i++)
    {
        queue->array[i] = NULL;
    }

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

// Function to add a process to the rear of the queue
void enqueue(struct Queue *queue, struct process *item)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue process\n");
        return;
    }

    if (isEmpty(queue))
        queue->front = 0;

    queue->rear++;
    queue->array[queue->rear] = item;
    printf("process with id %d enqueued to the queue\n", item->id);
}

// Function to remove a process from the front of the queue
struct process *dequeue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue\n");
        return NULL;
    }

    struct process *item = queue->array[queue->front];
    queue->front++;

    // If the front becomes greater than the rear, reset front and rear to -1
    if (queue->front > queue->rear)
        queue->front = queue->rear = -1;

    printf("process with id %d dequeued from the queue\n", item->id);
    return item;
}

// Function to get the front process of the queue without removing it
struct process *front(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    printf("front process id: %d\n", queue->array[queue->front]->id);
    return queue->array[queue->front];
}

// Function to get the rear process of the queue without removing it
struct process *rear(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return NULL;
    }
    printf("rear process id: %d\n", queue->array[queue->rear]->id);
    return queue->array[queue->rear];
}

void printQueue(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Process Queue:\n");
    for (int i = queue->front; i <= queue->rear; i++)
    {
        printf("Process id: %d, Arrival Time: %d, Execution Duration: %d, Size: %d\n",
               queue->array[i]->id, queue->array[i]->arrivalTime,
               queue->array[i]->executionDuration, queue->array[i]->size);
    }
}