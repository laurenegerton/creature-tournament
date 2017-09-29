/***********************************************************************************
 **Program Filename : Creature.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Implementation file for Creature class. Creature class is an abstract
 class and will not be instantiated.
 **Input : This program needs creature.hpp to run.
 **Output: This program will display the dice rolls if those functions are called and
 displayed.
 **********************************************************************************/

#include "Creature.hpp"
#include <ctime>
#include <cstdlib>

using std::srand;

/***********************************************************************************
 **Function : Constructor
 **Description : Virtual function
 **Parameters : n/a
 **Pre-Conditions : Creature.hpp
 **Post-Conditions : Creates a Creature object that has no name, 0 strength and 0 
 armor.
 **********************************************************************************/
Creature::Creature(){
    name = " ";
    strength = 0;
    armor = 0;
    team = " ";
}

/***********************************************************************************
 **Function : dieSix
 **Description : Uses the rand() function and modulus 6 to generate random numbers 
 between 1 and 6.
 **Parameters : n/a
 **Pre-Conditions : Creature object needs to be created.
 **Post-Conditions : Returns an int, the number randomly 'rolled'.
 **********************************************************************************/
int Creature::dieSix(){
    
    return (rand() % 6) + 1;
    
}

/***********************************************************************************
 **Function : dieTen
 **Description: Uses the rand() function and modulus 10 to generate random numbers
 between 1 and 10.
 **Parameters : n/a
 **Pre-Conditions : Creature object needs to be created.
 **Post-Conditions : Returns an int, the number randomly 'rolled'.
 **********************************************************************************/
int Creature::dieTen(){
    
    return (rand() % 10) + 1;
}

/***********************************************************************************
 **Function : dieTwelve
 **Description : Uses the rand() function and modulus 12 to generate random numbers
 between 1 and 12.
 **Parameters : n/a
 **Pre-Conditions : Creature object needs to be created.
 **Post-Conditions : Returns an int, the number randomly 'rolled'.
 **********************************************************************************/
int Creature::dieTwelve(){
    
    return (rand() % 12) + 1;
}

/***********************************************************************************
 **Function : getName()
 **Description : Returns the name of a Creature object.
 **Parameters : n/a
 **Pre-Conditions : Creature object needs to be created.
 **Post-Conditions : Returns the name of a creature object as a string.
 **********************************************************************************/
string Creature::getName(){
    
    return name;
}

/***********************************************************************************
 **Function : restore()
 **Description : Returns the restored strength of a Creature.
 **Parameters : n/a
 **Pre-Conditions : Creature object needs to be created.
 **Post-Conditions : Returns the current strength of a Creature + 50%.
 **********************************************************************************/
int Creature::restore(){
    
    return strength + (strength/2);
}

//set the team
void Creature::setTeam(string a){
    
    team = a;
}

//get the team
string Creature::getTeam(){
    
    return team;
}

//set the given name
void Creature::setFirstname(string a){
    
    firstName = a;
}

//get the given name
string Creature::getFirstName(){
    
    return firstName;
}

//get the strength points
int Creature::getStrength(){
    
    return strength;
}


