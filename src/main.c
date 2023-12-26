#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../raylib/src/raylib.h"
#include "../include/memory.h"
#include "../include/queue.h"
#include "../include/process.h"
#include "../include/utils.h"
#include "../include/allocation.h"

int main(void)
{
    // seed the random number generator
    srand(time(NULL));

    // memory initialization
    struct memoryPartition *memory = NULL;
    initializeMemory(&memory);

    printf("[INFO] Memory initialized\n");
    // initialize process queue
    struct Queue *processQueue = createQueue();

    // add processes to the queue
    enqueue(processQueue, createProcess(randomizer(50, 1000), 0, randomizer(1, 5), randomizer(10, 30)));
    enqueue(processQueue, createProcess(randomizer(50, 1000), 1, randomizer(1, 5), randomizer(10, 20)));
    enqueue(processQueue, createProcess(randomizer(50, 1000), 2, randomizer(1, 5), randomizer(10, 40)));

    printf("[INFO] Processes added to the queue\n");

    printQueue(processQueue);
    // Use firstFit function
    printf("[INFO] Using first fit algorithm\n");
    firstFit(&memory, processQueue);
    printf("[INFO] Using best fit algorithm\n");
    bestFit(&memory, processQueue);
    printf("[INFO] Using worst fit algorithm\n");
    worstFit(&memory, processQueue);

    printMemory(memory);
    printQueue(processQueue);

    return 0;
}
