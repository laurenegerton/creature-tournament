/***********************************************************************************
 **Program Filename : HarryPotter.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : 
 **Input : This program needs
 **Output: This program
 **********************************************************************************/

#include "HarryPotter.hpp"
#include "Creature.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

using std::srand;
using std::cout;
using std::cin;
using std::endl;

/***********************************************************************************
 **Function : HarryPotter
 **Description : Constructor
 **Parameters : n/a
 **Pre-Conditions : Needs to override the Creature constructor.
 **Post-Conditions : Sets name, strength and armor for a HarryPotter object.
 **********************************************************************************/
HarryPotter::HarryPotter(): Creature(){
    
    name = "Harry Potter";
    armor = 0;
    strength = 10;
    count = 0;
    
}

/***********************************************************************************
 **Function : attack
 **Description : When Harry Potter attacks, he can roll a 6-sided dice twice.
 **Parameters : n/a
 **Pre-Conditions : Creature class dieSix() function declared.
 **Post-Conditions : Returns an int, dieSix() function called twice and added together.
 **********************************************************************************/
int HarryPotter::attack(){
    
    return dieSix() + dieSix();
}

/***********************************************************************************
 **Function : defense
 **Description : Shows how Harry Potter can defend himself against attack.
 **Parameters : int
 **Pre-Conditions : Creature class defense() function declared as virtual; Creature class
 dieSix() function declared.
 **Post-Conditions : Returns an int, which is calculated by first rolling his defense
 die (dieSix) twice. If protection is greater than the attack number, the function returns
 his current strength and the attack has no effect. If the protection is lower than the
 attack number, his damage is equal to his protection minus his armor, all subtracted
 from the attack number. This new strength number is returned when the function ends. He
 has a special power, however, where he can die once and be re-born with strenght of 20.
 If he dies again, however, he is dead for good.
 **********************************************************************************/
int HarryPotter::defense(int a){
    
    int protection, damage;
    damage = 0;
    protection = 0;
    
    protection = (dieSix()) + (dieSix());
    
    if(protection > a)
        return strength;
    
    damage = a - protection;
    
    strength = strength - damage;
    
    if((strength <= 0) && (count == 0)){
        
        strength = 20;
        //cout << "Harry died but came back to life with double strength. \n" << endl;
        count ++;
        
    }
    else if((strength <= 0) && (count == 1)){
        
        strength = 0;
        //cout << "Harry died. He cannot come back to life a second time. \n" << endl;
        
    }
    
    /*return each player's new strength after being attacked*/
    return strength;
}

