#ifndef PROCESS_H
#define PROCESS_H

struct process
{
    int id;
    int arrivalTime;
    int executionDuration;
    int size;
    struct process *next;
};

struct process *createProcess(int id, int arrivalTime, int executionDuration, int size);
#endif