// TODO: doc blocks

// TODO explain what this class was originally for.

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
