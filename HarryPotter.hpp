/***********************************************************************************
 **Program Filename : HarryPotter.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Declaration file for HarryPotter class.
 **Input : This program needs Creature.hpp and Creature.cpp.
 **Output: n/a
 **********************************************************************************/

#ifndef HARRYPOTTER_CPP
#define HARRYPOTTER_CPP

#include <iostream>
#include "Creature.hpp"


class HarryPotter:public Creature{
private:
    /*variable used to keep track of first death*/
    int count;
public:
    HarryPotter();
    int attack();
    int defense(int);
};

#endif
