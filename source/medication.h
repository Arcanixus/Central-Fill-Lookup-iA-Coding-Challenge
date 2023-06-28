// TODO: doc blocks

#ifndef MEDICATION_H
#define MEDICATION_H

#include <memory>
#include <string>
#include <iostream>
#include <random>
#include "global-consts.h"
#include "world-seed.h"

class Medication 
{ 
  private:  

    double m_price;
    constants::MEDNAME m_name;

       
  public:      
    Medication(constants::MEDNAME name, std::shared_ptr<WorldSeed> seed);      
    ~Medication();

    double getPrice();
    void setName(constants::MEDNAME name);
    constants::MEDNAME getName();
    std::string getNameAsString();
};

#endif
