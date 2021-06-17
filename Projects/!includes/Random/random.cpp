#include <iostream>

#include <stdlib.h>
#include <time.h>

#include "../../!includes/Random/random.h"

using namespace std;

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

//initialization of the static member variable must be
//                            done in the .cpp file.

int Random::objectCount = 0;
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .


Random::Random()
{
    objectCount++;

    if (objectCount == 1)
    {
        srand(time(nullptr));
    }
}

int Random::Next(int low, int high)
{
    int r = rand() % ( high - low + 1) + low;
    return r;
}















