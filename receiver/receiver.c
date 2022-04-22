#include "receiver.h"
#include <stdio.h>


void readFromConsole(int *buffer)
{

  for (int idx = 0; idx <STREAM_LENGTH ; idx++)
    {
      scanf ("%i", &buffer[idx]);	
    }
}

int getMinValue(int * buffer)
{
    int minValue = MAX_VALUE;

    for (int idx = 0; idx < STREAM_LENGTH; idx++)
    {
        if (*buffer < minValue)
        {
            minValue = *buffer;
        }
        buffer++;
    }
    return minValue;
}


int getMaxValue(int * buffer)
{
    int maxValue = MIN_VALUE;

    for (int idx = 0; idx < STREAM_LENGTH; idx++)
    {
        if (*buffer > maxValue)
        {
            maxValue = *buffer;
        }
        buffer++;
    }
    return maxValue;
}
