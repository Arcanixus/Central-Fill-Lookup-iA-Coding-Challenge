/*****************************************
 * File Name: world-seed.cpp
 *  
 * Description: The implementation of the
 * world-seed object. This 
 * object is responsible for translating 
 * an input seed integer into multiple random 
 * world state parameters. Currently, this
 * object is only storing a copy of the session
 * integer seed, passed in by main.cpp, 
 * calculating a random number of Central Fill 
 * facilities, and providing access to that
 * number. This object was originally also
 * generating a median price for each medication
 * and was intended to be used to handle any other
 * world state data. Many of those earlier plans 
 * became unecessary for this exercise, but this 
 * object was left in partly because it is connected
 * in many places already and because this object 
 * can serve as an example of an object that can help
 * this program scale into a larger system.
 * 
 * Author: Ethan Paoletti
 * Date: 6/28/2023 
 * ***************************************/

#include "world-seed.h"
#include "global-consts.h"
#include <iostream>

WorldSeed::WorldSeed(int override_seed)
{  
   if(0 == override_seed)
   {
        // Seed the random number generator with the current system time
        // if the user did not provide a seed value
        m_seed = time(0);
   }
   else
   {
        m_seed = override_seed;
   }
   
   // Seed the random number generator
   srand(m_seed);
   
   // Now convert the raw int seed to world state seed data
   m_world_state[STATEIDS::NUMFACILITIES] = rand() % int(constants::WORLD_SIZE * 0.50);
} 

WorldSeed::~WorldSeed()
{

}

int WorldSeed::getSeed()
{
    return m_seed;
}

int WorldSeed::getNumFacilities()
{
    return m_world_state[STATEIDS::NUMFACILITIES];
}
