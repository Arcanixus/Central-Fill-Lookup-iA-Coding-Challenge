// TODO: doc blocks

#ifndef WORLD_SEED_H
#define WORLD_SEED_H

#include <map>

enum class STATEIDS {
    NUMFACILITIES,
    MIDPRICEMEDA,
    MIDPRICEMEDB,
    MIDPRICEMEDC   
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
    double getMidPriceMedA();
    double getMidPriceMedB();
    double getMidPriceMedC();

};

#endif
