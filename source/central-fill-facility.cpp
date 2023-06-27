#include "central-fill-facility.h"

static int s_numFacilities = 1; 

CentralFillFacility::CentralFillFacility(std::shared_ptr<WorldSeed> seed)
{
    m_ID = convertIntToID(s_numFacilities);
    
    // Increase the number of facilities here so that the next facility 
    // is IDed properly
    s_numFacilities++;

    initInventory(seed);
}     

CentralFillFacility::~CentralFillFacility()
{

}

bool CentralFillFacility::initInventory(std::shared_ptr<WorldSeed> seed)
{
   //std::vector<Medication>
   return true; // TBD
}

std::string CentralFillFacility::convertIntToID(int intID)
{
    std::string strID = std::to_string(intID);

    // Append the appropriate amount of 0's to the front of the 
    // string version of the facility ID to ensure that the ID
    // always consists of 3 digits.
    if(intID < 10)
    {
       strID = "00" + strID;
    }
    else if(intID < 100)
    {
       strID = "0" + strID;
    }
    
    return strID;
}

std::string CentralFillFacility::getID()
{
    return m_ID;
}

std::shared_ptr<std::vector<std::shared_ptr<Medication>>> CentralFillFacility::getInventory()
{
    return m_inventory;
}

std::shared_ptr<Medication> CentralFillFacility::getCheapestMed()
{
    if(nullptr != m_inventory)
    {
        std::shared_ptr<Medication> cheapestMed = m_inventory->at(0);
        for(unsigned int i = 1; i < m_inventory->size(); i++)
        {
            // TODO check double compare corner cases here
            // TODO determine what to do with meds that are equal
             if(m_inventory->at(i)->getPrice() < cheapestMed->getPrice())
             {
                cheapestMed = m_inventory->at(i);
             }
        }

        return cheapestMed;
    }

    return nullptr;
}