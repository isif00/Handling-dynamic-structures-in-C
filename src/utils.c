#include <stdio.h>
#include <stdlib.h>

int randomizer(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}