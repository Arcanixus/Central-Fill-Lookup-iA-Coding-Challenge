/*****************************************
 * File Name: world-seed.h
 *  
 * Description: The header file of the
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

#ifndef WORLD_SEED_H
#define WORLD_SEED_H

#include <map>

enum class STATEIDS {
    NUMFACILITIES 
};

class WorldSeed 
{ 
  private:  

    std::map<STATEIDS, int> m_world_state;
    int m_seed;
       
  public:      
    WorldSeed(int override_seed = 0);      
    ~WorldSeed();
    
    int getSeed();
    int getNumFacilities();
};

#endif
