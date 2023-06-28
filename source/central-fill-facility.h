// TODO: doc blocks

#ifndef CENTRAL_FILL_FACILITY_H
#define CENTRAL_FILL_FACILITY_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "medication.h"
#include "world-seed.h"

class CentralFillFacility
{ 
  private:  
    std::string m_ID;
    std::shared_ptr<std::vector<std::shared_ptr<Medication>>> m_inventory;

  public:      
    CentralFillFacility(std::shared_ptr<WorldSeed> seed);      
    ~CentralFillFacility();

    std::string getID();
    std::shared_ptr<std::vector<std::shared_ptr<Medication>>> getInventory();
    std::shared_ptr<Medication> getCheapestMed();

  private:

   bool initInventory(std::shared_ptr<WorldSeed> seed);
   std::string convertIntToID(int intID);
};

#endif
