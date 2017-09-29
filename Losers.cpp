/***********************************************************************************
 **Program Filename : Losers.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : 
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run.
 **Output:
 USE A STACK FOR LOSERS : FIRST-IN, LAST-OUT
 **********************************************************************************/

#include "Losers.hpp"


using std::cout;
using std::endl;


//Constructor with only a head, no nodes yet
Losers::Losers(){
    head = NULL;
}

//Print the Ls in the list
void Losers::print(){
    //point to the head of list
    if(head == NULL){
        //cout << "Nothing to print; the list is empty." << endl;
        return;
    }
    else{
        node *temp = head;
        
        while (temp != NULL){
            cout << "Team " << temp->L->getTeam() << " " << temp->L->getFirstName() << " ";  //print the P in the current node
            temp = temp->nextNode;              //move temp to the next node
            
            cout << endl;
        }
    }
}


//Add an item
void Losers::add (Creature *a){
    
    if(head == NULL){                       //there are no nodes yet
        head = new node;
        head->L = a;
        head->nextNode = NULL;
    }
    
    else {
        node *temp = head;                  //start temp at the head of the list
        
        while (temp->nextNode != NULL){     //while the node that temp is pointing to does NOT point at NULL
            temp = temp->nextNode;}         //move temp to point to the next node in list
        
        temp->nextNode = new node;                       //point n to a new node
        temp->nextNode->L = a;                      //set the value of the new node to a
        temp->nextNode->nextNode = NULL;                 //newest node now points to NULL (end of list)
    }
}


//Remove an item and return it
Creature * Losers::remove(){
    Creature *r;
    node *temp = head;
    node *temp2 = head;
    
    if(head == NULL){
        //cout << "Nothing to delete. The list is empty." << endl;
        r = NULL;
        return r;
    }
    
    else if(head->nextNode == NULL){        //there is only one node in the list
        r = head->L;
        delete head;
        head = NULL;
        return r;
    }
    
    else{
        while(temp2->nextNode != NULL){         //while n does not point to NULL (there are items in the list)
            temp = temp2;                       //have temp pointer point to same node as n
            temp2 = temp2->nextNode;            //move n to point to next node in list
        }
        
        r = temp2->L;
        delete temp2;
        
        temp->nextNode = NULL;
        
        return r;
    }
}

//Destructor
Losers::~Losers(){
    node *temp = head;                        //start at head of list
    node *garbage = head;
    
    if(head != NULL){
        if(head->nextNode == NULL){
            delete head;
            head = NULL;
        }
        else{
            while(temp != NULL){
                garbage = temp;
                temp = temp->nextNode;
                delete garbage;
            }
        }
    }
}

//return true if Losers is empty
bool Losers::isEmpty(){
    
    if(head == NULL)
        return true;
    else
        return false;
    
}

