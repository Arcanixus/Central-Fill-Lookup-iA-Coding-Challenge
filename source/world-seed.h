// TODO: doc blocks

#ifndef WORLD_SEED_H
#define WORLD_SEED_H

#include <map>

enum class SeedID {
    NUMFACILITIES,
    
};

class WorldSeed 
{ 
  private:  

    std::map<SeedID, int> m_seed;
       
  public:      
    WorldSeed(int override_value);      
    ~WorldSeed();
};

#endif
