/***********************************************************************************
 **Program Filename : Vampire.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : 
 **Input : This program needs
 **Output: This program
 **********************************************************************************/

#include "Vampire.hpp"
#include "Creature.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

using std::srand;
using std::cout;
using std::cin;
using std::endl;

/***********************************************************************************
 **Function : Vampire
 **Description : Constructor
 **Parameters : n/a
 **Pre-Conditions : Needs to override the Creature constructor.
 **Post-Conditions : Sets name, strength and armor for a Vampire object.
 **********************************************************************************/
Vampire::Vampire(): Creature(){
    
    name = "Vampire";
    armor = 1;
    strength = 18;
    
}

/***********************************************************************************
 **Function : attack
 **Description : When Vampire attacks, it can roll one 12-sided dice twice.
 **Parameters : n/a
 **Pre-Conditions : Creature class dieTwelve() function declared.
 **Post-Conditions : Returns an int, dieTwelve() function called once. **********************************************************************************/
int Vampire::attack(){
    
    return dieTwelve();
    
}

/***********************************************************************************
 **Function : defense
 **Description : Shows how Vampire can defend itrself against attack.
 **Parameters : int
 **Pre-Conditions : Creature class defense() function declared as virtual; Creature class
 dieSix() function declared.
 **Post-Conditions : Returns an int, which is calculated by first rolling its defense
 die (dieSix) once. If protection is greater than the attack number, the function returns
 its current strength and the attack has no effect. If the protection is lower than the
 attack number, its damage is equal to its protection minus its armor, all subtracted
 from the attack number. This new strength number is returned when the function ends.
 The vampire has a special defense where there is a 50% chance that it will charm its
 opponent in to not attacking. In this case, its strength is returned unchanged.
 **********************************************************************************/
int Vampire::defense(int a){
    
    int protection, damage, charm;
    protection = 0;
    damage = 0;
    charm = 0;
    
    protection = dieSix();
    
    if(protection > a){
        return strength;
    }
    else{
    
    charm = (rand() % 2) + 1;
    
    if(charm == 1){
    
        //cout << "The vampire charmed her opponent. No attack taken!" << endl;
        return strength;
        
    }
    else if(charm == 2){
        damage = a - protection;
        
        damage = damage -1;
        
        if(damage < 0)
            damage = 0;
        
        strength = strength - damage;
    }
    
    /*return each player's new strength after being attacked*/
    return strength;
    }
}

