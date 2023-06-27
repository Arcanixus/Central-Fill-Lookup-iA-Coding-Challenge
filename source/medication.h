// TODO: doc blocks

#ifndef MEDICATION_H
#define MEDICATION_H

#include <memory>
#include "global-consts.h"
#include "world-seed.h"

class Medication 
{ 
  private:  

    double m_price;
    constants::MEDNAME m_name;

       
  public:      
    Medication(std::shared_ptr<WorldSeed> seed);      
    ~Medication();

    double getPrice();
    constants::MEDNAME getName();
};

#endif
