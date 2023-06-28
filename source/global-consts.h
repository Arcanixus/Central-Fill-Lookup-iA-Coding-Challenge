/*****************************************
 * File Name: global-consts.h
 * 
 * Description: File containing constant 
 * data used throughout the program. This
 * File allows data to be changed in one 
 * place and ensures that the entire 
 * program adheres to the same bounds.
 * 
 * Author: Ethan Paoletti
 * Date: 6/28/2023 
 * ***************************************/

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
    const double MIN_WORLD_MED_PRICE = 0.01;
}

#endif