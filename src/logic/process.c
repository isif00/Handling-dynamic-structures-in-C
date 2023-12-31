#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "queue.h"

// fonction to create a process
struct process *createProcess(int id, int arrivalTime, int executionDuration, int size)
{
    struct process *process = (struct process *)malloc(sizeof(struct process));
    process->id = id;
    process->arrivalTime = arrivalTime;
    process->executionDuration = executionDuration;
    process->size = size;

    printf("Process created: id: %d, arrivalTime: %d, executionDuration: %d, size: %d\n", process->id, process->arrivalTime, process->executionDuration, process->size);
    return process;
}
