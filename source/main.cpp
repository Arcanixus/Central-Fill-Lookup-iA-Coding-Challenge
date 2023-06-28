/*****************************************
 * File Name: main.cpp
 *  
 * Description: This is the main entry point
 * into the software. This file is responsible
 * for interfacing with the user, instantiating 
 * the world object, and interacting with the
 * world object to get the information reuqested
 * by the user.
 * 
 * This file contains a set of code to help debug 
 * and better visualize the scenario. This mode can 
 * be activated by the user by answering "y" to
 * the question to start in debug mode at the start 
 * of the program. Debug mode also allows the user
 * to enter a custom seed to help reproduce past 
 * results.
 * 
 * Author: Ethan Paoletti
 * Date: 6/28/2023 
 * ***************************************/


//#define DEBUG

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "central-fill-world.h"
#include "central-fill-facility.h"
#include "global-consts.h"
#include "world-seed.h"

std::map<constants::AXES, int> parseInput(std::string inputStr);

int main()
{
    bool debug = false;
    bool valid = false;
    do
    {
        std::string str;
        std::cout << "Run program in debug mode? (y/n)" << std::endl;
        std::cin >> str;

        if(str == "y")
        {
            debug = true;
            valid = true;
        }
        else if(str == "n")
        {
            debug = false;
            valid = true;
        }
        else
        {
            std::cout << "Invalid input! Valid input is 'y' or 'n' " << std::endl;
        }

    } while (!valid);   
    

    int override_seed = 0;

    if(debug)
    {
        std::cout << "*************** DEBUG MODE DETECTED ***************" << std::endl;
        std::cout << "Please input a custom seed now (enter 0 to use a random seed)..." << std::endl;
        std::cin >> override_seed;
    }

    std::shared_ptr<WorldSeed> seed = std::make_shared<WorldSeed>(override_seed);

    CentralFillWorld world(seed);    

    bool usrLocValid = false;
    std::map<constants::AXES, int> userLoc;

    do
    {
        // Get the user's location
        std::string str;

        std::cout << "Please enter your location (x, y) as -10 to +10 for both x and y..." << std::endl;
        std::cin >> str;

        // Now ensure the coordinates are separated by a comma
        if(str.find(",") == std::string::npos)
        {
            std::cout << "ERROR: Invalid coordinate format input! Please enter coordinates as two numerical values separated by a comma, with no spaces." << std::endl;
        }
        else
        {        
            userLoc = parseInput(str);

            // Check to see if the user input coordinates are valid for our world
            usrLocValid = world.isValidWorldLocation(userLoc[constants::AXES::X], userLoc[constants::AXES::Y]);
            if(!usrLocValid)
            {
                std::cout << "ERROR: Invalid user location entered...valid inputs are " + std::to_string(constants::MIN_X_COORDINATE) + 
                            " to " + std::to_string(constants::MAX_X_COORDINATE) + " for x and " + 
                            std::to_string(constants::MIN_Y_COORDINATE) +  " to " + std::to_string(constants::MAX_Y_COORDINATE) + 
                            " for y" << std::endl;
            }
        }
    } while (!usrLocValid);


    if(debug)
    {
    
        if(nullptr != seed)
        { 
            std::cout << std::endl;
            std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
            std::cout << "Session seed is: " + std::to_string(seed->getSeed()) << std::endl;
            std::cout << "Num Central Fill Facilities: " + std::to_string(seed->getNumFacilities()) << std::endl;
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

    }

    std::vector<std::tuple<int, std::shared_ptr<CentralFillFacility>>> closestFacilities = 
                                                            world.getClosestCentralFillFacilitiesToLocation(userLoc[constants::AXES::X], 
                                                                                                            userLoc[constants::AXES::Y], 
                                                                                                            3);

    if(nullptr != seed)
    { 
        std::cout << std::endl;
        std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
        std::cout << "Closest Central Fill Facilities to (" << userLoc[constants::AXES::X] << ", " << userLoc[constants::AXES::Y] << ")" << std::endl;

        for(int i=0; i < closestFacilities.size(); i++)
        {
            std::shared_ptr<CentralFillFacility> facility = std::get<1>(closestFacilities[i]);
            int facilityDist = std::get<0>(closestFacilities[i]);

            if(nullptr != facility)
            {
                std::shared_ptr<Medication> med = facility->getCheapestMed();

                if(nullptr != med)
                {

                    std::cout << "Central Fill " << facility->getID() << " - " <<  std::setprecision(2) << std::fixed << med->getPrice() << 
                                ", Medication " << med->getNameAsString() << 
                                ", Distance "   << facilityDist << std::endl; // TBD distance

                }
                else
                {
                    std::cout << "Close Central Fill Facility Medication object was nullptr!" << std::endl;
                    return 0;
                }
            }
            else
            {
                std::cout << "Close Central Fill Facility object was nullptr!" << std::endl;
                return 0;
            }
        }
        
        std::cout << "--------------------------------------------------------------------------------------------" << std::endl;
        std::cout << std::endl;
    }

    
    std::cout << "Press ENTER to continue...";
    std::cin.ignore();
    
    return 0;
}

std::map<constants::AXES, int> parseInput(std::string inputStr)
{
    std::map<constants::AXES, int> usrLoc;

    std::stringstream ss(inputStr);
    std::vector<std::string> result; 
    while (ss.good()) 
    {
        std::string substr;
        getline(ss, substr, ',');
        result.push_back(substr);
    }

    usrLoc[constants::AXES::X] = stoi(result[0]);
    usrLoc[constants::AXES::Y] = stoi(result[1]);

    return usrLoc;
}
