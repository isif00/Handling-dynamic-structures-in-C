#ifndef MEMORYGR_H
#define MEMORYGR_H

#include <stdbool.h>

void drawMemoryPartition(struct memoryPartition *partition, int yPos, bool *timerState);
void drawMemoryLayout(struct memoryPartition *memory, bool *timerState);
void drawMemoryTable(struct memoryPartition *memory);

#endif