// TODO: doc blocks

#ifndef MEDICATION_H
#define MEDICATION_H

#include "global-consts.h"

class Medication 
{ 
  private:  

    double m_price;
    constants::MEDNAME m_name;

       
  public:      
    Medication(int seed);      
    ~Medication();
};

#endif
