/***********************************************************************************
 **Program Filename : Medusa.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Declaration file for Medusa class.
 **Input : This program needs Creature.hpp and Creature.cpp to run.
 **Output: n/a
 **********************************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include <iostream>
#include "Creature.hpp"


class Medusa:public Creature{
public:
    Medusa();
    int attack();
    int defense(int);
};

#endif 
