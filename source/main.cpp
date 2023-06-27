#define DEBUG

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "central-fill-world.h"
#include "central-fill-facility.h"
#include "global-consts.h"
#include "world-seed.h"

std::map<constants::AXES, int> parseInput(std::string inputStr);

int main()
{
    int override_seed = 0;

#ifdef DEBUG
    std::cout << "*************** DEBUG MODE DETECTED ***************" << std::endl;
    std::cout << "Please input a custom seed now (enter 0 to use a random seed)..." << std::endl;
    std::cin >> override_seed;
#endif // DEBUG

    std::shared_ptr<WorldSeed> seed = std::make_shared<WorldSeed>(override_seed);

    CentralFillWorld world(seed);

    // Get the user's location
    std::string str;

    std::cout << "Please enter your location (x, y) as -10 to +10 for both x and y..." << std::endl;
    std::cin >> str;

    std::map<constants::AXES, int> userLoc = parseInput(str);

    // Check to see if the user input coordinates are valid for our world
    bool usrLocValid = world.isValidWorldLocation(userLoc[constants::AXES::X], userLoc[constants::AXES::Y]);
    if(!usrLocValid)
    {
        std::cout << "ERROR: Invalid user location entered...valid inputs are " + std::to_string(constants::MIN_X_COORDINATE) + 
                     " to " + std::to_string(constants::MAX_X_COORDINATE) + " for x and " + 
                     std::to_string(constants::MIN_Y_COORDINATE) +  " to " + std::to_string(constants::MAX_Y_COORDINATE) + 
                    " for y" << std::endl;

        usrLocValid = false;
    }

    if(usrLocValid)
    {

#ifdef DEBUG
       
       if(nullptr != seed)
       { 
          std::cout << std::endl;
          std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
          std::cout << "Session seed is: " + std::to_string(seed->getSeed()) << std::endl;
          std::cout << "Num Central Fill Facilities: " + std::to_string(seed->getNumFacilities()) << std::endl;
          std::cout << "Median World Price for Medication A: " + std::to_string(seed->getMidPriceMedA()) << std::endl;
          std::cout << "Median World Price for Medication B: " + std::to_string(seed->getMidPriceMedB()) << std::endl;
          std::cout << "Median World Price for Medication C: " + std::to_string(seed->getMidPriceMedC()) << std::endl;
          std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
          std::cout << std::endl;
       }

        std::cout << "-------------------------------------------- 0 ---------------------------------------------" << std::endl;

        for(int y = constants::MAX_Y_COORDINATE; y >= constants::MIN_Y_COORDINATE; y--)
        {        
            if(0 == y)
            {
                std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
            }

            std::string rowStr = (y == 0 ? "0 " : "| ");

            for(int x = constants::MIN_X_COORDINATE; x <= constants::MAX_X_COORDINATE; x++)
            {
                if(0 == x)
                {
                    rowStr += "| ";
                }

                bool atUsrLoc = false;
                if(x == userLoc[constants::AXES::X] &&
                y == userLoc[constants::AXES::Y])
                {
                    atUsrLoc = true;
                }

                std::shared_ptr<CentralFillFacility> facilityLocation = world.getCentralFillFacilityAtLocation(x, y);
                if(nullptr != facilityLocation)
                {
                    if(atUsrLoc)
                    {
                        rowStr += "USR/" + facilityLocation->getID() + " ";
                    }
                    else
                    {
                        rowStr += facilityLocation->getID() + " ";
                    }
                }
                else
                {
                    if(atUsrLoc)
                    {
                        rowStr += "USR ";
                    }
                    else
                    {
                        rowStr += "--- ";
                    }                    
                }                

                if(0 == x)
                {
                    rowStr += "| ";
                }
            }

            rowStr += (y == 0 ? " 0" : " |");

            std::cout << rowStr << std::endl;

            if(0 == y)
            {
                std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
            }
        } 

        std::cout << "-------------------------------------------- 0 ---------------------------------------------" << std::endl;

 #endif // DEBUG

    }


    
    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    
    return 0;
}

std::map<constants::AXES, int> parseInput(std::string inputStr)
{
    // TODO need to add lots of validation here

    std::map<constants::AXES, int> usrLoc;

    std::stringstream ss(inputStr);
    std::vector<std::string> result; 
    while (ss.good()) 
    {
        std::string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
        std::cout << substr << std::endl;
    }

    usrLoc[constants::AXES::X] = stoi(result[0]);
    usrLoc[constants::AXES::Y] = stoi(result[1]);

    return usrLoc;
}
