/***********************************************************************************
 **Program Filename : Tournament.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description :
 **Input : This program needs Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run.
 **Output:
 **********************************************************************************/

#include "Tournament.hpp"
#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Game.hpp"
#include "Lineup.hpp"
#include "Losers.hpp"

using std::endl;
using std::cout;

//constructor
Tournament::Tournament(){
    
    winsA = 0;
    winsB = 0;

}

////destructor
//Tournament::~Tournament(){
//   
//    delete it;
//}

//add nodes to Lineup Team A
void Tournament::setTeamA(string a, string b){
    string team = "A";
    Creature *it;
    
    if(a == "1"){
        it = new Medusa;
        it->setTeam(team);
        it->setFirstname(b);
    }
    else if(a == "2"){
        it = new Barbarian;
        it->setTeam(team);
        it->setFirstname(b);
    }
    else if(a == "3"){
        it = new Vampire;
        it->setTeam(team);
        it->setFirstname(b);
    }
    else if(a == "4"){
        it = new BlueMen;
        it->setTeam(team);
        it->setFirstname(b);
    }
    else if(a == "5"){
        it = new HarryPotter;
        it->setTeam(team);
        it->setFirstname(b);
    }
    else
        it = NULL;
    
    A.addQ(it);
    
    //delete it;
    it = NULL;                      //or delete it???
}

//add nodes to Lineup Team B
void Tournament::setTeamB(string a, string b){
    string team = "B";
    
    Creature *it2;
    
    if(a == "1"){
        it2 = new Medusa;
        it2->setTeam(team);
        it2->setFirstname(b);
    }
    else if(a == "2"){
        it2 = new Barbarian;
        it2->setTeam(team);
        it2->setFirstname(b);
    }
    else if(a == "3"){
        it2 = new Vampire;
        it2->setTeam(team);
        it2->setFirstname(b);
    }
    else if(a == "4"){
        it2 = new BlueMen;
        it2->setTeam(team);
        it2->setFirstname(b);
    }
    else if(a == "5"){
        it2 = new HarryPotter;
        it2->setTeam(team);
        it2->setFirstname(b);
    }
    else
        it2 = NULL;
    
    B.addQ(it2);
    
    it2 = NULL;
}

//start a fight between two creatures
int Tournament::startRound(int a){
    Creature *first;
    Creature *second;
    Creature *winner;
    int rounds = 1;
    int losers = 0;
    
    playersA = a;
    playersB = a;
    
    do{
    cout << "Round: " << rounds << endl;
    
    first = A.removeQ();
    second = B.removeQ();

    
    Game round(first, second);   //create a Game Round w/ these two creatures
    
    winner = round.fight();      //return pointer to winning Creature
   
    if(winner == first){
        A.addQ(first);          //PROBLEM
        first->restore();       //restore the winner's power
        winsA = winsA + 1;      //incrememnt Team A's wins
        loserList.add(second);  //PROBLEM
        playersB--;
        losers++;
    }
    
    if(winner == second){
        B.addQ(second);          //PROBLEM
        second->restore();      //restore the winner's power
        winsB = winsB + 1;      //increment Team B's wins
        loserList.add(first);   //PROBLEM
        playersA--;
        losers++;
    }
    rounds++;
    cout << "\n";
    }while(!TeamA() && !TeamB());
    
    if(TeamA()){
        cout << "The tournament is over. Team A lost!" << endl;
    }
    else if(TeamB()){
        cout << "The tournament is over. Team B lost!" << endl;
    }
    return losers;
    
    first = NULL;
    second = NULL;
    winner = NULL;
}

//diplay a list of losers
void Tournament::displayLosers(int a){
    
    Creature *y;
    
    
    for(int i = 0; i < a; i++){
        y = loserList.remove();
        
        if(y == NULL){
            cout << "The most recent losers were reborn to take their medals.";
            return;
        }
    
        cout << "Team " << y->getTeam() << " " << y->getFirstName() << " the " << y->getName() << endl;
    }
    
    delete y;
}

//get winning points of Team A
int Tournament::getWinsA(){
   
    return winsA;
}

//get winning points of Team B
int Tournament::getWinsB(){
    
    return winsB;
}

//display list of Lineup Team A
void Tournament::getTeamA(){
    
    A.printQ();
}

//display list of Lineup Team B
void Tournament::getTeamB(){
    
    B.printQ();
}

//return true if Team A is empty
bool Tournament::TeamA(){
    
    return A.isEmpty();
}

//return true if Team B is empty
bool Tournament::TeamB(){
    
    return B.isEmpty();
}

void Tournament::displayWinners(){
    Creature *a;
    Creature *b;
    
    //if Team A has survivors (aka the winner)
    if(!TeamA()){
        if(playersA > 2){                  //Get the two with the highest scoring points
            A.print1();             //print the last one in the line-up (last to be added)
            for(int i = 0; i < playersA - 3; i++){
                A.removeQ();
            }
            a = A.removeQ();        //3rd place
            b = A.removeQ();        //2nd place
            cout << "Second Place: Team " << b->getTeam() << " " << b->getFirstName() << " the " << b->getName() << endl;
            cout << "Third Place: Team " << a->getTeam() << " " << a->getFirstName() << " the " << a->getName() << endl;
        }
        
        else if(playersA == 2){      //Get the two with the highest scoring points
            A.print1();             //print the winner
            a = A.removeQ();        //2nd place winner
            cout << "Second Place: Team " << a->getTeam() << " " << a->getFirstName() << " the " << a->getName() << endl;
            b = loserList.remove();
            cout << "     The following loser is reborn to take its medal:" << endl;
            cout << "Third Place: Team " << b->getTeam() << " " << b->getFirstName() << " the " << b->getName() << endl;
        }
        else if(playersA == 1){          //Get two with highest scoring points
            A.print1();
            a = loserList.remove();
            cout << "     The following loser is reborn to take its medal:" << endl;
            cout << "Second Place: Team " << a->getTeam() << " " << a->getFirstName() << " the " << a->getName() << endl;
            b = loserList.remove();
            if(b == NULL)
                return;
            cout << "     The following loser is reborn to take its medal:" << endl;
            cout << "Third Place: Team " << b->getTeam() << " " << b->getFirstName() << " the " << b->getName() << endl;
        }
    }
    
    //if Team B has survivors (aka the winner)
    else if(!TeamB()){                   //Team B still has survivors, but how many?
        if(playersB > 2){                  //Get the two with the highest scoring points
            for(int i = 0; i < playersB - 3; i++){
                B.removeQ();
            }
            B.print1();             //print the last one in the line-up (last to be added)
            a = B.removeQ();        //3rd place
            b = B.removeQ();        //2nd place
            cout << "Second Place: Team " << b->getTeam() << " " << b->getFirstName() << " the " << b->getName() << endl;
            cout << "Third Place: Team " << a->getTeam() << " " << a->getFirstName() << " the " << a->getName() << endl;
        }
        
        else if(playersB == 2){          //Get the two with the highest scoring points
            B.print1();                 //print the winner
            a = B.removeQ();            //2nd place winner
            cout << "Second Place: Team " << a->getTeam() << " " << a->getFirstName() << " the " << a->getName() << endl;
            b = loserList.remove();
            cout << "     The following loser is reborn to take its medal:" << endl;

            cout << "Third Place: Team " << b->getTeam() << " " << b->getFirstName() << " the " << b->getName() << endl;
        }
        else if(playersB == 1){          //Get two with highest scoring points
            B.print1();
            a = loserList.remove();
            cout << "     The following loser is reborn to take its medal:" << endl;
            cout << "Second Place: Team " << a->getTeam() << " " << a->getFirstName() << " the " << a->getName() << endl;
            b = loserList.remove();
            if(b == NULL)
                return;
            cout << "     The following loser is reborn to take its medal:" << endl;
            cout << "Third Place: Team " << b->getTeam() << " " << b->getFirstName() << " the " << b->getName() << endl;
            
        }
    }
//    delete a;
//    delete b;
//    delete c;
}






