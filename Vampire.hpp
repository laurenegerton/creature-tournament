/***********************************************************************************
 **Program Filename : Vampire.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Declaration file for Vampire class.
 **Input : This program needs Creature.hpp and Creature.cpp.
 **Output: n/a
 **********************************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <iostream>
#include "Creature.hpp"

class Vampire:public Creature{
public:
    Vampire();
    int attack();
    int defense(int);
};

#endif