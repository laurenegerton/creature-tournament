/***********************************************************************************
 **Program Filename : Main.cpp
 **Author : Lauren Egerton
 **Date : 02/28/16
 **Description : Main user function to run the Battle program. The program uses
 inheritance and polymorphism by using an abstract base class (Creature) and derived
 classes (Medusa, Barbarian, Vampire, BlueMen, HarryPotter) that use virtual functions 
 to override the base class functions (attack and defense). It also uses Stack-like and 
 Queue-like linked lists to hold and display creatures.
 **********************************************************************************/

#include "Creature.hpp"
#include "Medusa.hpp"
#include "Barbarian.hpp"
#include "Vampire.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Game.hpp"
#include "Lineup.hpp"
#include "Losers.hpp"
#include "Tournament.hpp"

#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::srand;


/***********************************************************************************
 **Function : main
 **Description : The program starts by greeting the user and telling the user what
 the program will do (play a game). The program uses a loop to ask the user to choose 
 a number of players for each team (two teams total) and then asks the user to choose
 the creatures for Team 1 and Team 2; the user also chooses a name for each creatures on
 each team. It creates a Tournament object and calls functions from the following classes
 to play the game.
 **Parameters : n/a
 **Pre-Conditions : Main is dependent on Creature.cpp, Creature.hpp, Medusa.cpp, Medusa.hpp,
 Barbarian.cpp, Barbarian.cpp, Vampire.cpp, Vampire.hpp, BlueMen.cpp, BlueMen.hpp,
 HarryPotter.cpp, HarryPotter.hpp, Game.cpp and Game.hpp to run. It uses public member 
 functions of each class to play the game.
 **Post-Conditions : The results of the tournament are displayed to the user as each
 round is fought between two players. When only one player is left alive, it displays
 the 1st, 2nd, and 3rd place winners as well as the losers (if the user would like).
 **********************************************************************************/

int main() {
 
    /*seed random numbers*/
    srand((unsigned) time(0));
   
    Tournament T1;
    
    int players;
    string choice1;
    string choice2;
    string name;
    int numLosers;
    
    /*introduction*/
    
    cout << "Welcome to the Tournament of the Creepy Creatures, " << endl;
    cout << "a turn-based combat game. \n" << endl;
    
    cout << "You will form two teams made of the following types of creatures: " << endl;
    
    cout << "Medusa, Barbarian, Vampire, Blue Men, and Harry Potter. \n" << endl;
    
    cout << "Each team will line up." << endl;
    cout << "The head of one lineup will fight the other until death." << endl;
    
    cout << "The loser of a fight is sent to the loser pile to rot;" << endl;
    cout << "the winner moves to the back of its team's line. \n" << endl;
    
    cout << "The last player alive is the FIRST PLACE & WINNER of the Tournament." << endl;
    cout << "If the Winner's team has players that are still alive," << endl;
    cout << "then the last player to win a round gets SECOND PLACE," << endl;
    cout << "and the player before it wins THIRD PLACE. \n" << endl;
    cout << "If, however, the Winner's Team is all dead," << endl;
    cout << "The last two losers to die will be re-born," << endl;
    cout << "in the order of their most recent death," << endl;
    cout << "and be given SECOND and THIRD PLACES, respectively. \n" << endl;
    
    //get number of players for each team
    cout << "How many players do you want on each team?" << endl;
    cin >> players;
    
    cout << "\n";
    cout << "Player 1: you will now choose a creature and a name for the " << players << " player(s) on Team A." << endl;
    
    for(int i = 0; i < players; i++){
    do{
        /*Ask user to choose first creature to fight*/
        cout << "Choose a number from the following menu. " << endl;
        cout << "1. Medusa \n";
        cout << "2. Barbarian \n";
        cout << "3. Vampire \n";
        cout << "4. Blue Men \n";
        cout << "5. Harry Potter \n";
        cin >> choice1;
        cin.ignore(1000, '\n');
        
        if((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5")){
            cout << "That is not a choice. Please choose again. \n" << endl;
            }
    }while((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5"));
   
    cout << "Please give this player a name: " << endl;
    getline(cin, name);

    T1.setTeamA(choice1, name);     //add player to Team A
    }
    cout << "\n";
    cout << "Player 2: you will now choose a creature and a name for the " << players << " player(s) on Team B." << endl;
    
    for(int i = 0; i < players; i++){
        do{
            /*Ask user to choose first creature to fight*/
            cout << "Choose a number from the following menu. " << endl;
            cout << "1. Medusa \n";
            cout << "2. Barbarian \n";
            cout << "3. Vampire \n";
            cout << "4. Blue Men \n";
            cout << "5. Harry Potter \n";
            cin >> choice1;
            cin.ignore(1000, '\n');
            
            if((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5")){
                cout << "That is not a choice. Please choose again. \n" << endl;
            }
        }while((choice1 != "1") && (choice1 != "2") && (choice1 != "3") && (choice1 != "4") && (choice1 != "5"));
        
        cout << "Please give this player a name: " << endl;
        getline(cin, name);
        
        T1.setTeamB(choice1, name);     //add Player to Team B
        
    }
    cout << "\n";
    
    //print Team A's lineup
    cout << "Here is the lineup of players for Team A : " << endl;
    
    T1.getTeamA();
    
    cout << endl;
    
    cout << "Here is the lineup of players for Team B : " << endl;
    
    //print Team B's lineup
    T1.getTeamB();
    
    cout << "\n";
    cout << "Let the Tournament begin! \n" << endl;
    
    //start the tournament
    numLosers = T1.startRound(players);
    
    cout << "\n";
    
    //display results
    cout << "The results of the tournament are as follows: " << endl;
    
    //display stats for each team
    cout << "Team A finished with " << T1.getWinsA() << " winning point(s)." << endl;
    cout << "Team B finished with " << T1.getWinsB() << " winning point(s)." << endl;
    
    cout << "\n";
    
    //display the list of winners
    T1.displayWinners();
    
    cout << "\n";
    
    //choice to see losers
    cout << "Would you like to see who is rotting in the Loser pile? Choose Y or N." << endl;
    cin >> choice2;
    

    if(choice2 == "y" || choice2 == "Y"){
    
    cout << "The losers are: " << endl;
    
    T1.displayLosers(numLosers);
    cout << "\n\n";
    cout << "Goodbye!";
    }
    
    else if(choice2 == "n" || "N"){
        cout << "\nGoodbye!";
    }
    return 0;
}


