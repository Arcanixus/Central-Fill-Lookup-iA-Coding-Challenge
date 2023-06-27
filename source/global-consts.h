// TODO: doc block

#ifndef GLOBAL_CONSTS_H
#define GLOBAL_CONSTS_H

#include <stdlib.h>

namespace constants
{
    enum class MEDNAME
    {
        A, 
        B,
        C
    };

    enum class AXES
    {
        X,
        Y,
    };
    
    // The Central Fill virtual world upper and lower axis bounds
    const int MAX_X_COORDINATE = 10;
    const int MIN_X_COORDINATE = -10;
    const int MAX_Y_COORDINATE = 10;
    const int MIN_Y_COORDINATE = -10;
    
    // + 1 on both x an y axes to account for the (0,0) point
    const int SIZE_X_AXIS = (abs(MIN_X_COORDINATE) + abs(MAX_X_COORDINATE) + 1);
    const int SIZE_Y_AXIS = (abs(MIN_Y_COORDINATE) + abs(MAX_Y_COORDINATE) + 1);

    const int WORLD_SIZE = SIZE_X_AXIS * SIZE_Y_AXIS;

    const int MAX_WORLD_MED_PRICE = 1000;
}

#endif