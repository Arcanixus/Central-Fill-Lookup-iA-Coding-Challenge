#include "medication.h"

Medication::Medication(std::shared_ptr<WorldSeed> seed)
{
   
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