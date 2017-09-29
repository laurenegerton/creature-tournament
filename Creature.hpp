/***********************************************************************************
 **Program Filename : Creature.hpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Declaration file for Creature class.
 **Input : n/a
 **Output: n/a
 **********************************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>

using std::string;

/*Abstract, base class*/
class Creature{
protected:
    string name;
    int strength;
    int armor;
    int fight;
    string team;
    string firstName;
public:
    Creature();
    //virtual ~Creature();
    string getName();
    void setFirstname(string);
    virtual int attack() = 0;
    virtual int defense(int) = 0;
    int dieSix();
    int dieTen();
    int dieTwelve();
    int restore();
    void setTeam(string);
    string getTeam();
    string getFirstName();
    int getStrength();
};


#endif
