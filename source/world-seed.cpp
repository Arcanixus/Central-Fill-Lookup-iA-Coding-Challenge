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
   m_world_state[STATEIDS::NUMFACILITIES] = rand() % int(constants::WORLD_SIZE * 0.75);
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
