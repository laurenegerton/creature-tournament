/***********************************************************************************
 **Program Filename : BlueMen.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Declaration file for BlueMen class.
 **Input : This program needs Creature.hpp and Creature.cpp.
 **Output: n/a
 **********************************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include <iostream>
#include "Creature.hpp"


class BlueMen:public Creature{
public:
    BlueMen();
    int attack();
    int defense(int);
};

#endif