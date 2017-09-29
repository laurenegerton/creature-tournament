/***********************************************************************************
 **Program Filename : Medusa.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Implementation file for Medusa.hpp. This program provides the overidden 
 functions for the Creature class when it is declared a Medusa object, which is a child 
 of Creature.
 **Input : This program needs Medusa.hpp and Creature.hpp
 **Output: n/a
 **********************************************************************************/

#include "Medusa.hpp"
#include "Creature.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

using std::srand;
using std::cout;
using std::cin;
using std::endl;

/***********************************************************************************
 **Function : Medusa
 **Description : Constructor
 **Parameters : n/a
 **Pre-Conditions : Needs to override the Creature constructor.
 **Post-Conditions : Sets name, strength and armor for a Medusa object.
 **********************************************************************************/
Medusa::Medusa(): Creature(){
    
    name = "Medusa";
    armor = 3;
    strength = 8;
    
}

/***********************************************************************************
 **Function : attack
 **Description : When Medusa attacks, she can roll a 6-sided dice twice.
 **Parameters : n/a
 **Pre-Conditions : Creature class dieSix() function declared.
 **Post-Conditions : Returns an int, dieSix() function called twice and added together.
 **********************************************************************************/
int Medusa::attack(){
 
    return (dieSix()) + (dieSix());     //check in Main if she got a 12 - GLARE to kill opponent instantly
}

/***********************************************************************************
 **Function : defense
 **Description : Shows how Medusa can defend herself against attack.
 **Parameters : int
 **Pre-Conditions : Creature class defense() function declared as virtual; Creature class
 dieSix() function declared.
 **Post-Conditions : Returns an int, which is calculated by first rolling her defense
 die (dieSix) once. If protection is greater than the attack number, the function returns
 her current strength and the attack has no effect. If the protection is lower than the 
 attack number, her damage is equal to her protection minus her armor, all subtracted 
 from the attack number. This new strength number is returned when the function ends.
 **********************************************************************************/
int Medusa::defense(int a){
    
    int protection, damage;
    protection = 0;
    damage = 0;
    
    protection = dieSix();
    
    if(protection > a){
        return strength;
    }
    else{
    damage = a - protection;
        
    damage = damage - 3;
    
    if(damage < 0){
        damage = 0;
    }
        
    strength = strength - damage;
    
    /*return each player's new strength after being attacked*/
    return strength;
    }
}

