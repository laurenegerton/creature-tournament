/***********************************************************************************
 **Program Filename : Tournament.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description :
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run.
 **Output:
 **********************************************************************************/

#ifndef TOURNAMENT_HPP
#define TOURNAMENT_HPP

#include <iostream>
#include "Losers.hpp"
#include "Lineup.hpp"
#include "Game.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"

class Tournament{
protected:
    Losers loserList;       //Stack to hold the losers from both teams; displayed first-in, last-out
    Lineup A;               //Queue to hold one team
    Lineup B;               //Queue to hold other team
    int winsA;              //# of wins for Team A
    int winsB;              //# of wins for Team B
    int playersA;
    int playersB;

public:
    Tournament();           //create a Tournament
    //~Tournament();
    
    void setTeamA(string, string);
    void setTeamB(string, string);
    
    int startRound(int);
    
    void displayLosers(int);              //diplay a list of losers
    void displayWinners();
    
    int getWinsA();                    //get winning points of Team A
    int getWinsB();                    //get winning points of Team B
    
    void getTeamA();                   //display list of Lineup Team A
    void getTeamB();                   //display list of Lineup Team B
    bool TeamA();
    bool TeamB();
};

#endif 
