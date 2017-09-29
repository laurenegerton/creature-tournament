/***********************************************************************************
 **Program Filename : Losers.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description :
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run.
 **Output: STACK
 **********************************************************************************/

#ifndef LOSERS_HPP
#define LOSERS_HPP

#include <iostream>
#include "Creature.hpp"

class Losers{
private:
    struct node{
        Creature *L;
        node *nextNode;
    };
    node *head;
public:
    Losers();
    ~Losers();
    void add (Creature *);
    Creature * remove();
    void print();
    bool isEmpty();
    
};


#endif 
