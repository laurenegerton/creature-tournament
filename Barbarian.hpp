/***********************************************************************************
 **Program Filename : Barbarian.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Declaration file for Barbarian class.
 **Input : This program needs Creature.hpp and Creature.cpp.
 **Output: n/a
 **********************************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include <iostream>
#include "Creature.hpp"


class Barbarian:public Creature{
public:
    Barbarian();
    int attack();
    int defense(int);
};


#endif
