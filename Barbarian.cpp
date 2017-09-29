/***********************************************************************************
 **Program Filename : Barbarian.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : 
 **Input : This program needs
 **Output: This program
 **********************************************************************************/

#include "Barbarian.hpp"
#include "Creature.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

using std::srand;
using std::cout;
using std::cin;
using std::endl;

/***********************************************************************************
 **Function : Barbarian
 **Description : Constructor
 **Parameters : n/a
 **Pre-Conditions : Needs to override the Creature constructor.
 **Post-Conditions : Sets name, strength and armor for a Barbarian object.
 **********************************************************************************/
Barbarian::Barbarian(): Creature(){
    
    name = "Barbarian";
    armor = 0;
    strength = 12;
    
}

/***********************************************************************************
 **Function : attack
 **Description : When Barbarian attacks, it can roll a 6-sided dice twice.
 **Parameters : n/a
 **Pre-Conditions : Creature class dieSix() function declared.
 **Post-Conditions : Returns an int, dieSix() function called twice and added together. **********************************************************************************/
int Barbarian::attack(){
    
    return (dieSix()) + (dieSix());
    
}

/***********************************************************************************
 **Function : defense
 **Description : Shows how Barbarian can defend itrself against attack.
 **Parameters : int
 **Pre-Conditions : Creature class defense() function declared as virtual; Creature class
 dieSix() function declared.
 **Post-Conditions : Returns an int, which is calculated by first rolling its defense
 die (dieSix) twice. If protection is greater than the attack number, the function returns
 its current strength and the attack has no effect. If the protection is lower than the
 attack number, its damage is equal to its protection minus its armor, all subtracted
 from the attack number. This new strength number is returned when the function ends.
 **********************************************************************************/
int Barbarian::defense(int a){
    
    int protection, damage;
    protection = 0;
    damage = 0;
    
    protection = (dieSix()) + (dieSix());
    
    if(protection > a){
        return strength;
    }
    else{
    damage = a - protection;
        
    if(damage < 0)
        damage = 0;
    
    strength = strength - damage;
    
    /*return each player's new strength after being attacked*/
    return strength;
    }
}

