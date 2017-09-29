/***********************************************************************************
 **Program Filename : Lineup.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description :
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run.
 **Output:
 USE A QUEUE FOR LINE-UP, FIRST-IN, FIRST-OUT
 **********************************************************************************/

#include "Lineup.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Game.hpp"
#include "Losers.hpp"

using std::cout;
using std::endl;

//constructor
Lineup::Lineup(){
    
    head = NULL;
    tail = NULL;
}

//print the Lineupclass list
void Lineup::printQ(){
    
    if(head == NULL){
        //cout << "Lineup is empty." << endl;
        return;
    }
    else{
        node *temp = head;
        
        while (temp != NULL){
            cout << temp->P->getFirstName() << " the " << temp->P->getName();  //print the P in the current node
            temp = temp->nextNode;              //move temp to the next node
        
        cout << endl;
        }
    }
}

//print the last person in the Team (most recently added, the winner)
void Lineup::print1(){

        if(head == NULL){
            cout << "Lineup is empty." << endl;
        }
        else{
            node *temp = tail;
            
            cout << "First place: Team " << temp->P->getTeam() << " " << temp->P->getFirstName() << " the " << temp->P->getName();  //print the P in the current node
            cout << endl;
        }
}


//add a node to Lineup
void Lineup::addQ(Creature *a){
    if(head == NULL){
        head = new node;
        head->P = a;
        head->nextNode = NULL;
        head->prevNode = NULL;
        tail = head;
    }
    else{
        tail->nextNode = new node;
        tail->nextNode->P = a;
        tail->nextNode->nextNode = NULL;
        tail->nextNode->prevNode = tail;
        tail = tail->nextNode;
    }
}

//remove a node from Lineup- first in, first out
Creature* Lineup::removeQ(){
    Creature *r;
    node *temp = head;
    node *temp2 = head;
    
    if(head == NULL){
        cout << "Nothing to remove. The list is empty." << endl;
        r = NULL;
        return r;
    }
    
    else if(head->nextNode == NULL){  //there is only one node in the Lineup
        r = head->P;
        delete head;
        head = NULL;
        tail = NULL;
        //cout << "Nothing left to remove now." << endl;
        return r;}
    
    else{                   //there is more than one node in the list
        temp = temp2->nextNode;
        r = head->P;
        delete head;
        head = temp;
        head->prevNode = NULL;                     //point to the front of the list
        return r;
    }
}

//destructor
Lineup::~Lineup(){
    node * temp = head;
    node *garbage = head;
    
    if(head != NULL){                   //only one node to delete
        if(temp->nextNode == NULL){
            delete temp;
            head = NULL;
            }
    
        else{
            while (temp != NULL){           //more than one node to delete
                garbage = temp;                //garbage keeps track of node to be deleted
                temp = temp->nextNode;                //move ptr to the next node
                delete garbage;                     //delete the "garbage" node
            }
        }
    }
}

//return true if Lineup is empty
bool Lineup::isEmpty(){
    
    if(head == NULL)
        return true;
    else
        return false;
    
}