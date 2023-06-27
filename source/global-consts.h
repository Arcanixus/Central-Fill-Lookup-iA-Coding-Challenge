// TODO: doc block

#ifndef GLOBAL_CONSTS_H
#define GLOBAL_CONSTS_H

namespace constants
{
    enum class MEDNAME
    {
        A, 
        B,
        C
    };
    
    // The Central Fill virtual world upper and lower axis bounds
    const int MAX_X_COORDINATE = 10;
    const int MIN_X_COORDINATE = -10;
    const int MAX_Y_COORDINATE = 10;
    const int MIN_Y_COORDINATE = -10;
}

#endif