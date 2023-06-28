/*****************************************
 * File Name: medication.cpp
 *  
 * Description: The implementation of the
 * medication object. This 
 * object is responsible for containing the
 * data necessary for simulating a medication 
 * within the virtual world of this program.
 * Medication objects are created and stored
 * within a Central Fill facility object.
 * They are responsible for generating a price
 * and maintaining a consistent ID, as well as
 * providing accessors to this data.
 * 
 * Author: Ethan Paoletti
 * Date: 6/28/2023 
 * ***************************************/

#include "medication.h"

Medication::Medication(constants::MEDNAME name, std::shared_ptr<WorldSeed> seed)
{
   m_name = name;

   if(nullptr != seed)
   {
        const long max_rand = 1000000L;
        switch(m_name)
        {
            default:
            case constants::MEDNAME::A:
                m_price = constants::MIN_WORLD_MED_PRICE
                           + (constants::MAX_WORLD_MED_PRICE - constants::MIN_WORLD_MED_PRICE)
                           * (rand() % max_rand)
                           / max_rand;
                break;
            case constants::MEDNAME::B:
                m_price = constants::MIN_WORLD_MED_PRICE
                           + (constants::MAX_WORLD_MED_PRICE - constants::MIN_WORLD_MED_PRICE)
                           * (rand() % max_rand)
                           / max_rand;
                break;
            case constants::MEDNAME::C:
                m_price = constants::MIN_WORLD_MED_PRICE
                           + (constants::MAX_WORLD_MED_PRICE - constants::MIN_WORLD_MED_PRICE)
                           * (rand() % max_rand)
                           / max_rand;
                break;
        }
   }
   else
   {
        std::cout << "World Seed was nullptr!" << std::endl;
        throw (false);
   }
}

Medication::~Medication()
{

}

double Medication::getPrice()
{
    return m_price;
}

constants::MEDNAME Medication::getName()
{
    return m_name;
}

std::string Medication::getNameAsString()
{
    switch(m_name)
    {
        case constants::MEDNAME::A:
            return "A";
        case constants::MEDNAME::B:
            return "B";
        case constants::MEDNAME::C:
            return "C";
        default:
            return "A";
    }
}
