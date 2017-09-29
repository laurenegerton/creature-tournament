/***********************************************************************************
 **Program Filename : BlueMen.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : 
 **Input : This program needs
 **Output: This program
 **********************************************************************************/

#include "BlueMen.hpp"
#include "Creature.hpp"
#include <ctime>
#include <iostream>
#include <cstdlib>

using std::srand;
using std::cout;
using std::cin;
using std::endl;

/***********************************************************************************
 **Function : BlueMen
 **Description : Constructor
 **Parameters : n/a
 **Pre-Conditions : Needs to override the Creature constructor.
 **Post-Conditions : Sets name, strength and armor for a BlueMen object.
 **********************************************************************************/
BlueMen::BlueMen(): Creature(){
    
    name = "Blue Men";
    armor = 3;
    strength = 12;
}

/***********************************************************************************
 **Function : attack
 **Description : When BlueMen attack, they can roll a 10-sided dice twice.
 **Parameters : n/a
 **Pre-Conditions : Creature class dieTen() function declared.
 **Post-Conditions : Returns an int, dieTen() function called twice and added together.
 **********************************************************************************/
int BlueMen::attack(){
    
    return (dieTen()) + (dieTen());
}

/***********************************************************************************
 **Function : defense
 **Description : Shows how BlueMen can defend themselves against attack.
 **Parameters : int
 **Pre-Conditions : Creature class defense() function declared as virtual; Creature class
 dieSix() function declared.
 **Post-Conditions : Returns an int, which is calculated by first rolling their defense
 die (dieSix) three times. However, each time the Blue Men lose four points of strenght, 
 they lose one die to roll for protectin. If protection is greater than the attack number, 
 the function returns their current strength and the attack has no effect. If the protection 
 is lower than the attack number, their damage is equal to their protection minus their armor, 
 all subtracted from the attack number. This new strength number is returned when the function 
 ends.
 **********************************************************************************/
int BlueMen::defense(int a){
    
    int protection, damage;
    protection = 0;
    damage = 0;
    
    if(strength > 8){
        protection = (dieSix()) + (dieSix()) + (dieSix());
        
        if(protection > a)
            return strength;
        
        damage = a - protection;
        
        damage = damage - 3;
                
        if(damage < 0)
            damage = 0;
        
        strength = strength - damage;}
    
    else if((strength > 4) && (strength <= 8)){
        protection = (dieSix()) + (dieSix());
        
        if(protection > a)
            return strength;
    
        damage = a - protection;
        
        damage = damage - 3;
        
        if(damage < 0)
            damage = 0;
        
        strength = strength - damage;}
    
    else if(strength <= 4){
        protection = dieSix();
       
        if(protection > a)
            return strength;
        damage = a - protection;
        
        damage = damage - 3;
        
        if(damage < 0)
            damage = 0;
        
        strength = strength - damage;}

    /*return each player's new strength after being attacked*/
    return strength;
}

