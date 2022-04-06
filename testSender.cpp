#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
#include "sender.h"

TEST_CASE("Test if 12 bit Amp readings are within expected range (0 - 10). Verify 1000 randomized readings")
{
    int idx;
    int result;
    for (idx = 0; idx < 1000; idx++)
    {
        result = get12BitSensorAmpReading();
        REQUIRE(result <= 10);
        REQUIRE(result >= 0);
    }
}

TEST_CASE("Test if 12 bit State of Charge readings are within expected range (0.00 - 100.00). Verify 1000 randomized readings")
{
    int idx;
    float result;
    for (idx = 0; idx < 1000; idx++)
    {
        result = get12BitSensorSoCReading();
        REQUIRE(result <= 100);
        REQUIRE(result >= 0);
    }
}

TEST_CASE("Test if 10 bit Amp readings are within expected range (0 - 10). Verify 1000 randomized readings")
{
    int idx;
    int result;
    for (idx = 0; idx < 1000; idx++)
    {
        result = get10BitSensorAmpReading();
        REQUIRE(result <= 10);
        REQUIRE(result >= 0);
    }
}

TEST_CASE("Test if 10 bit State of Charge readings are within expected range (0.00 - 100.00). Verify 1000 randomized readings")
{
    int idx;
    float result;
    for (idx = 0; idx < 1000; idx++)
    {
        result = get10BitSensorSoCReading();
        REQUIRE(result <= 100);
        REQUIRE(result >= 0);
    }
}

TEST_CASE("Test printing a stream of line by line values to the console (verify console output)")
{
    int ampTestValues[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    float socTestValues[] = {0, 10.5, 20.5, 30.5, 40.5, 50.5, 60.5, 70.5, 80.5, 90.5, 100};
    int idx;
    for (idx = 0; idx < 11; idx++)
    {
        printValuePairToConsole(ampTestValues[idx], socTestValues[idx]);
    }
}

TEST_CASE("MAIN TEST (12-bit): Print a line by line stream of 50 pairs of Amp + SoC readings to the console (100 values total) (verify console output)")
{
    int idx;
    int currentAmpValue;
    float currentSoCValue;
    for (idx = 0; idx < 50; idx++)
    {
        currentAmpValue = get12BitSensorAmpReading();
        currentSoCValue = get12BitSensorSoCReading();
        printValuePairToConsole(currentAmpValue, currentSoCValue);
    }
}

TEST_CASE("MAIN TEST (10-bit): Print a line by line stream of 50 pairs of Amp + SoC readings to the console (100 values total) (verify console output)")
{
    int idx;
    int currentAmpValue;
    float currentSoCValue;
    for (idx = 0; idx < 50; idx++)
    {
        currentAmpValue = get10BitSensorAmpReading();
        currentSoCValue = get10BitSensorSoCReading();
        printValuePairToConsole(currentAmpValue, currentSoCValue);
    }
}