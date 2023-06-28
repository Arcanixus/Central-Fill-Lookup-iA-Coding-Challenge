#include "central-fill-world.h"
#include "global-consts.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <stdlib.h>
#include <algorithm>

CentralFillWorld::CentralFillWorld(std::shared_ptr<WorldSeed> seed)
{
    if(!initWorldMap(seed)) throw (false);
}     

CentralFillWorld::~CentralFillWorld()
{

}

bool CentralFillWorld::initWorldMap(std::shared_ptr<WorldSeed> seed)
{
    // First, initialize every world position to nullptr   
    for(int x = constants::MIN_X_COORDINATE; x <= constants::MAX_X_COORDINATE; x++)
    {
        for(int y = constants::MIN_Y_COORDINATE; y <= constants::MAX_Y_COORDINATE; y++)
        {
            m_world[x][y] = nullptr;
        }
    }

   // Now intialize all the central fill facilities in the world
   return generateCentralFillFacilities(seed);
}

bool CentralFillWorld::generateCentralFillFacilities(std::shared_ptr<WorldSeed> seed)
{
    // First, flush any facility locations previously generated
    m_facility_locs.clear();

    if(nullptr != seed)
    { 
        // Generate the random locations where the central fill facilities will be placed
        srand(seed->getSeed());

        for(int i=0; i < seed->getNumFacilities(); i++)
        {
            std::map<constants::AXES, int> loc;
            
            // do-while to ensure no duplicate locations or invalid locations
            do
            {
                loc[constants::AXES::X] = (rand() % (constants::SIZE_X_AXIS + 1)) - constants::MAX_X_COORDINATE; 
                loc[constants::AXES::Y] = (rand() % (constants::SIZE_Y_AXIS + 1)) - constants::MAX_Y_COORDINATE;  

                // We can have a MAX + 1 condition above...so use this quick hack for now to bandaid this problem
                // We'll still get the correct number of randomly located facilities even if this bandaid is left here. 
                loc[constants::AXES::X] = loc[constants::AXES::X] > constants::MAX_X_COORDINATE ? 
                    constants::MAX_X_COORDINATE : loc[constants::AXES::X]; 
                    
                loc[constants::AXES::Y] = loc[constants::AXES::Y] > constants::MAX_Y_COORDINATE ? 
                    constants::MAX_Y_COORDINATE : loc[constants::AXES::Y];

            } while (!isValidWorldLocation(loc[constants::AXES::X], loc[constants::AXES::Y]) || 
                    isFacilityLocation(loc[constants::AXES::X], loc[constants::AXES::Y]));  

            // Once we have a randomly generate location for a central fill facility, add it to the world.
            m_world[loc[constants::AXES::X]][loc[constants::AXES::Y]] = std::make_shared<CentralFillFacility>(seed);      

            // Now record the new central fill facility's location for easy viewing in the future.
            m_facility_locs.push_back(loc);
        }  
    }  
    else
    {
        std::cout << "ERROR: World Seed was nullptr!" << std::endl;
        return false;
    }

    return true;
}

bool CentralFillWorld::isFacilityLocation(int x, int y)
{
    return (m_world[x][y] != nullptr);
}

bool CentralFillWorld::isValidWorldLocation(int x, int y)
{
    bool locValid = true;
    if(x > constants::MAX_X_COORDINATE ||
    x < constants::MIN_X_COORDINATE ||
    y > constants::MAX_Y_COORDINATE ||
    y < constants::MIN_Y_COORDINATE)
    {
        locValid = false;
    }

    return locValid;
}

std::shared_ptr<CentralFillFacility> CentralFillWorld::getCentralFillFacilityAtLocation(int x, int y)
{
    return m_world[x][y];
}

std::vector<std::tuple<int, std::shared_ptr<CentralFillFacility>>> CentralFillWorld::getClosestCentralFillFacilitiesToLocation(int x, int y, int numFacilities)
{
    std::vector<std::tuple<int, std::shared_ptr<CentralFillFacility>>> closestFacilities;

    std::vector<std::tuple<int, std::map<constants::AXES, int>>> locDists = calcAndSortWorldLocationDistancesToPoint(x, y);
    
    int i = 0;
    do
    {       
        std::tuple<int, std::map<constants::AXES, int>> location = locDists[i];

        int x2 = std::get<1>(location)[constants::AXES::X]; 
        int y2 = std::get<1>(location)[constants::AXES::Y];
        int dist = std::get<0>(location);

        if(isValidWorldLocation(x2, y2) &&
            isFacilityLocation(x2, y2))
        {
            closestFacilities.push_back(std::make_tuple(dist, getCentralFillFacilityAtLocation(x2, y2)));
        }
       
        i++;
    }
    while(closestFacilities.size() != numFacilities);

    return closestFacilities;
}

int CentralFillWorld::calcManhattanDistanceBetweenPoints(int x1, int y1, int x2, int y2)
{
    return abs(x1-x2) + abs(y1-y2);
}

std::vector<std::tuple<int, std::map<constants::AXES, int>>> CentralFillWorld::calcAndSortWorldLocationDistancesToPoint(int x1, int y1)
{
    std::vector<std::tuple<int, std::map<constants::AXES, int>>> locDists;

    for(int x2 = constants::MIN_X_COORDINATE; x2 <= constants::MAX_X_COORDINATE; x2++)
    {
        for(int y2 = constants::MIN_Y_COORDINATE; y2 <= constants::MAX_Y_COORDINATE; y2++)
        {
            std::map<constants::AXES, int> location;

            location[constants::AXES::X] = x2;
            location[constants::AXES::Y] = y2;

            locDists.push_back(std::make_tuple(calcManhattanDistanceBetweenPoints(x1, y1, x2, y2), location));
        }
    }

    std::sort(locDists.begin(), locDists.end());

    return locDists;
}

