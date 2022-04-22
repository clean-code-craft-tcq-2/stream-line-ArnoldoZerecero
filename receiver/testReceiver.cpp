#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test-receiver/catch.hpp"
#include "receiver.h"

int ampDataStream[STREAM_LENGTH];
int stateOfChargeDataStream[STREAM_LENGTH];


TEST_CASE("Test reading the stream of values from console")
{
	
    readFromConsole(&ampDataStream[0]);
    readFromConsole(&stateOfChargeDataStream[0]);

    printf("Amperage");
    for (int idx = 0; idx < STREAM_LENGTH; idx++)
    {
        printf(" %i", ampDataStream[idx]);
    }
    printf("\n");

    printf("State Of Charge (SOC)");
    for (int idx = 0; idx < STREAM_LENGTH; idx++)
    {
        printf(" %i", stateOfChargeDataStream[idx]);
    }
    printf("\n");
}



TEST_CASE("Get minimum and maximum values for each parameter")
{
    printf("Current MIN value - %i\n", getMinValue(&ampDataStream[0]));
    printf("Current MAX value - %i\n", getMaxValue(&ampDataStream[0]));
    printf("SOC MIN value - %i\n", getMinValue(&stateOfChargeDataStream[0]));
    printf("SOC MAX value - %i\n", getMaxValue(&stateOfChargeDataStream[0]));
}

