/***********************************************************************************
 **Program Filename : Lineup.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description :
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run.
 **Output: QUEUE
 **********************************************************************************/
#ifndef LINEUP_HPP
#define LINEUP_HPP

#include <iostream>
#include "Creature.hpp"

struct node{
    Creature *P;
    node *nextNode;
    node *prevNode;
};

class Lineup{
private:
    node *head;
    node *tail;
    
public:
    Lineup();
    ~Lineup();
    void addQ(Creature *);
    Creature * removeQ();
    void printQ();
    bool isEmpty();
    void print1();
};

#endif 
