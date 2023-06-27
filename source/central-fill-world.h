// TODO: doc blocks

#ifndef CENTRAL_FILL_WORLD_H
#define CENTRAL_FILL_WORLD_H

#include <map>
#include <memory>
#include <vector>
#include "central-fill-facility.h"
#include "world-seed.h"

class CentralFillWorld 
{ 
  private:      

    std::map<int, std::map<int, std::shared_ptr<CentralFillFacility>>> m_world;
    std::vector<std::map<constants::AXES, int>> m_facility_locs;
       
  public:      
    CentralFillWorld(std::shared_ptr<WorldSeed> seed);      
    ~CentralFillWorld();

    bool isValidWorldLocation(int x, int y);
    bool isFacilityLocation(int x, int y); 
    
    std::shared_ptr<CentralFillFacility> getCentralFillFacilityAtLocation(int x, int y);

  private:

    bool initWorldMap(std::shared_ptr<WorldSeed> seed);
    bool generateCentralFillFacilities(std::shared_ptr<WorldSeed> seed);   
};


#endif
