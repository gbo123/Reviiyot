#ifndef GAME_H_
#define GAME_H_

#include <iostream>

#include "Player.h"
#include "Deck.h"
#include "Card.h"

using namespace std;

class Game {
private:
    vector<Player *> players;  //The list of the players
    Deck deck;//The deck of the game
    int verbal;//how to print the process of the game- get by the config file
    int highestNumeric;//number of highest numeric- get by the config file
    int turn;//determine which turn is it
public:
    Game();//empty constructor
    Game(char* configurationFile);//constructor that gets a file
    Game(const Game& game);//copy constructor
    Player* whoToAsk(Player* player);//returns a player pointer to ask from cards
    bool hasWinner();//returns if there is a winner and the game is completed
    void init();//initialize the game
    void play();//play the game
    int getVerbal() const;//returns verbal
    int getHighestNumeric()const ;//retrun highestNumeric
    Card* convertStringToCard(string s);//used to convert the string deck to a deck of the program

    
    void printState();        //Print the state of the game as described in the assignment.
    string askValue(int value);//convert figure values to string
    void printWinner();       //Print the winner of the game as describe in the assignment.
    void printNumberOfTurns(); //Print the number of played turns at any given time.
    ~Game();//destructor
    //**assignment operator*--------------------------------------
};

#endif

