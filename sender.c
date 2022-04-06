#include "sender.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define CONVERSION_12BIT_TO_AMPS(bitValue)    round((float)(bitValue * 10) / 4095)
#define CONVERSION_12BIT_TO_SOC(bitValue)     (float)(bitValue * 100) / 4095

#define CONVERSION_10BIT_TO_AMPS(bitValue)    round((float)(bitValue * 10) / 1023)
#define CONVERSION_10BIT_TO_SOC(bitValue)     (float)(bitValue * 100) / 1023

int get12BitSensorAmpReading(void)
{
    int reading = rand() % 4096;
    return CONVERSION_12BIT_TO_AMPS(reading);
}

float get12BitSensorSoCReading(void)
{
    int reading = rand() % 4096;
    return CONVERSION_12BIT_TO_SOC(reading);
}

int get10BitSensorAmpReading(void)
{
    int reading = rand() % 1024;
    return CONVERSION_10BIT_TO_AMPS(reading);
}

float get10BitSensorSoCReading(void)
{
    int reading = rand() % 1024;
    return CONVERSION_10BIT_TO_SOC(reading);
}

void printValuePairToConsole(int ampValue, float socValue)
{
    printf("%i\n%.2f\n", ampValue, socValue);
}
