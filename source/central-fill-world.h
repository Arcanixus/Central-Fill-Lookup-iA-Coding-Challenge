/*****************************************
 * File Name: central-fill-world.cpp
 *  
 * Description: The header file of the
 * Central Fill world object. This 
 * object is responsible for building a
 * map of the 2D virtual Central Fill world.
 * This object is also responsible for placing,
 * and managing the Central Fill facilities 
 * within the main virtual world map. Lastly,
 * This object contains accessor functionality
 * so that an outside program can access the 
 * central fill facilities they are looking for.
 * 
 * Author: Ethan Paoletti
 * Date: 6/28/2023 
 * ***************************************/

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
    std::vector<std::tuple<int, std::shared_ptr<CentralFillFacility>>> getClosestCentralFillFacilitiesToLocation(int x, int y, int numFacilities=3);

  private:

    bool initWorldMap(std::shared_ptr<WorldSeed> seed);
    bool generateCentralFillFacilities(std::shared_ptr<WorldSeed> seed);  

    int calcManhattanDistanceBetweenPoints(int x1, int y1, int x2, int y2);
    std::vector<std::tuple<int, std::map<constants::AXES, int>>> calcAndSortWorldLocationDistancesToPoint(int x1, int y1);
};


#endif
