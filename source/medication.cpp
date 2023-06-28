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