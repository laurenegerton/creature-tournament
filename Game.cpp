/***********************************************************************************
 **Program Filename : Game.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Implementation file for Game class.
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp and HarryPotter.hpp to run.
 **Output: Game class provides feedback to the user so the user knows what is happening
 as the game is being played.
 **********************************************************************************/

#include "Game.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

using std::srand;
using std::cout;
using std::cin;
using std::endl;
using std::string;

//default constructor
Game::Game(){
    
    first = NULL;
    second = NULL;
}

/***********************************************************************************
 **Function : Constructor
 **Description : Creates a Game object by setting the pointers to two Creatures.
 **Parameters : Two strings
 **Pre-Conditions : Dependent on Creature.cpp and Creature.hpp.
 **Post-Conditions : Displays who will be fighting by deferencing the two pointers and
 calling the getName() function for both.
 **********************************************************************************/
Game::Game(Creature *a, Creature *b){
//
    first = a;
    second = b;
}

/***********************************************************************************
 **Function : Destructor
 **Description : Deletes pointers to Creatures
 **Parameters : n/a
 **Pre-Conditions : Dependent on Creature pointers being created
 **Post-Conditions : Ensures the pointers to Creatures have been deleted, avoiding
 memory leaks.
 **********************************************************************************/
Game::~Game(){
    
    first = NULL;
    second = NULL;
    
}

/***********************************************************************************
 **Function : fight
 **Description : Lays out the battle for the Game class. Each round consists of a first
 attack by Opponent 1 and a defense by Opponent 2. Then Opponent 2 attacks and Opponent
 1 defends. After each attack/defense, the strength points of each fighter is checked.
 If it is <= 0, the fighter dies and the game is over. It also checks to see if the
 Medusa object is playing and if so, when she rolls a 12 she turns her opponent to stone
 and wins the battle.
 **Parameters : n/a
 **Pre-Conditions : Dependent on Creature.cpp, Medusa.cpp, Barbarian.cpp, Vampire.cpp,
 BlueMen.cpp and HarryPotter.cpp
 **Post-Conditions : The function has many print statements that notify the user of 
 what action is occurring during which Round.
 **********************************************************************************/
Creature * Game::fight(){
    
    int damage1, damage2, health1, health2, round;
    damage1 = 0;
    damage2 = 0;
    health1 = 0;
    health2 = 0;
    round = 1;
    
    do{
    
    damage1 = first->attack();

    /*if Creature is Medusa, check to see if her roll is 12. If it is, she glares and turns opponent to stone*/
    if((first->getName() == "Medusa") && (damage1 == 12)){
        
        cout << "Team " << second->getTeam() << " " << second->getFirstName() << " the " << second->getName() << " has been charmed by Medusa and is now stone!" << endl;
        cout << "Team " << first->getTeam() << " " << first->getFirstName() << " the " << first->getName() << " is the winner." << endl;
        return first;
    }
    
    /*creature 2 calls defense function*/
    health2 = second->defense(damage1); //C2 defends and has this much strength left
    
    /*if creature 2's strength is 0 or below, s/he dies*/
    if(health2 <= 0){
        
        cout << "Team " << second->getTeam() << " " << second->getFirstName() << " the " << second->getName() << " is dead! " << endl;
        cout << "Team " << first->getTeam() << " " << first->getFirstName() << " the " << first->getName() << " is the winner." << endl;
        return first;
    }
    
    /*creature 2 attacks*/
    damage2 = second->attack();
    
    /*if Creature is Medusa, check to see if her roll is 12. If it is, she glares and turns opponent to stone*/
    if((second->getName() == "Medusa") && (damage1 == 12)){
        
        cout << "Team " << first->getTeam() << " " << first->getFirstName() << " the "<< first->getName() << " received the Medusa GLARE and is now stone!" << endl;
        cout << "Team " << second->getTeam() << " " << second->getFirstName()<< " the " << second->getName() << "is the winner." << endl;
        return second;
    }
    
    /*creature 1 calls defense function*/
    health1 = first->defense(damage2);
    
    /*if creature 1's strength is 0 or below, s/he dies*/
    if (health1 <= 0){
    
        cout << "Team " << first->getTeam() << " " << first->getFirstName() << " the " << first->getName() << " is dead!" << endl;
        cout << "Team " << second->getTeam() << " " << second->getFirstName() << " the " << second->getName() << " is the winner." << endl;
        return second;
    }
    round++;
        
    /*continue do-while loop until one creature dies*/
    }while((health1 > 0) && (health2 > 0));

    return NULL;        //protection
}


