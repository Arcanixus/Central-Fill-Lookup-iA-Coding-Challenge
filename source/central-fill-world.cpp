#include "central-fill-world.h"
#include "global-consts.h"
#include <iostream>
#include <vector>

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

