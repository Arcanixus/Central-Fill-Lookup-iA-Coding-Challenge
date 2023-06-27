// TODO: doc blocks

#ifndef CENTRAL_FILL_FACILITY_H
#define CENTRAL_FILL_FACILITY_H

#include <string>
#include <vector>
#include <memory>
#include "medication.h"

class CentralFillFacility
{ 
  private:  
    std::string m_ID;
    std::shared_ptr<std::vector<Medication>> m_inventory;
       
  public:      
    CentralFillFacility();      
    ~CentralFillFacility();
    std::weak_ptr<std::vector<Medication>> getInventory();
    std::weak_ptr<Medication> getCheapestMed();
};

#endif
