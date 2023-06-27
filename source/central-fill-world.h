// TODO: doc blocks

#ifndef CENTRAL_FILL_WORLD_H
#define CENTRAL_FILL_WORLD_H

#include <map>;
#include <memory>;
#include "central-fill-facility.h";

class CentralFillWorld 
{ 
  private:  
    std::map<int, std::map<int, std::shared_ptr<CentralFillFacility>>> m_world;
       
  public:      
    CentralFillWorld(int seed);      
    ~CentralFillWorld();
    std::shared_ptr<CentralFillFacility> getCentralFillFacilityAtLocation(int x, int y);
};

#endif
