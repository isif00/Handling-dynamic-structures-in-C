#ifndef ALLOCATION_H
#define ALLOCATION_H

void firstFit(struct memoryPartition **memory, struct process *currentprocess);
void bestFit(struct memoryPartition **memory, struct process *currentProcess);
void worstFit(struct memoryPartition **memory, struct process *currentProcess);
#endif