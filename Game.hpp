/***********************************************************************************
 **Program Filename : Game.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Class declaration for Game class.
 **Input : n/a
 **Output: n/a
 **********************************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "Creature.hpp"
#include <iostream>
#include <ctime>

class Game{
protected:
    /*pointers to creatures*/
    Creature *first;
    Creature *second;
    
public:
    Game();
    Game(Creature *, Creature *);
    ~Game();
    Creature * fight();
};

#endif
