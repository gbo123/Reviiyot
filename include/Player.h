#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>

#include "Hand.h"

using namespace std;

class Player : public Hand {
private:
    const string name;

public:
    Player(const Player& player);//copy constructor
    Player(string name);// constructor
    int postionRequired=0;//position of each player used for strategy 3-4
    string getName() const;
    string toString();//not the best implementation need to check:
    virtual int getStrategy()=0;//get player stategy number
    virtual int getpostionRequired()=0;//get player
    virtual void setpostionRequired()=0;// set positionRequired +1 , used for strategy 3-4 to know from who to ask
    virtual int requiredValue()=0;//get the value to ask for
    bool hasCard (Player* player, int requiredValue);//check if other player has the required value
    void fetchCards(Player* player, int numTimes, int requiredValue);//get the value
    virtual Player* clone()=0;//method to clone players when copying a vector of players


};

class PlayerType1 : public Player {  //For strategy 1



public:
    virtual Player* clone();//method to clone players when copying a vector of players
    PlayerType1(const PlayerType1& player1);//copy constructor
    PlayerType1(string name);// constructor
    int requiredValue();//get the required value needed to complete a set
    int getStrategy();//get strategy number
    int getpostionRequired();// get the position of whom to ask- used for strategy 3-4
    void setpostionRequired();// set the position of whom to ask - used for strategy 3-4
};

class PlayerType2 : public Player {  //For strategy 2

public:
    virtual Player* clone();//method to clone players when copying a vector of players
    PlayerType2(const PlayerType2& player2);//copy constructor
    PlayerType2(string name);
    int requiredValue();//get the required value needed to complete a set
    int getStrategy();//get strategy number
    int getpostionRequired();
    void setpostionRequired();
};

class PlayerType3 : public Player {


public:
    virtual Player* clone();//method to clone players when copying a vector of players
    PlayerType3(const PlayerType3& player3);//copy constructor
    PlayerType3(string name);
    int requiredValue();//get the required value needed to complete a set
    int getStrategy();//get strategy number
    int getpostionRequired();
    void setpostionRequired();
};



class PlayerType4 : public Player {  //For strategy 4




public:
    virtual Player* clone();//method to clone players when copying a vector of players
    PlayerType4(const PlayerType4& player4);//copy constructor
    PlayerType4(string name);
    int requiredValue();
    int getStrategy();//get strategy number
    int getpostionRequired();
    void setpostionRequired();

};

#endif
