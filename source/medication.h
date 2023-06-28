/*****************************************
 * File Name: medication.h
 *  
 * Description: The header file of the
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
