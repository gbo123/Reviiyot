#include "Player.h"/*
 * Player.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: gilbeno
 */

#include "Player.h"
#include "Hand.h"
#include <string>

using namespace std;

Player::Player (string name):name(name),postionRequired(0) {


}

Player::Player(const Player& player):   Hand(player) ,name(player.getName())  {

}



string Player::getName() const {

    return name;


}

string Player:: toString(){
    return getName()+" : " + Hand::toString();

}


bool Player::hasCard (Player* player, int requiredValue){
    return player->isInHand(requiredValue);

}

void Player:: fetchCards(Player* player, int numTimes, int requiredValue){

    for (int i=0; i<numTimes;i++){
        addCard(*player->fetchCard(requiredValue));
    }


}


//----------------------------------------------------------------------------
//****playertype 1





PlayerType1::PlayerType1(string name):Player(name){

}

PlayerType1::PlayerType1(const PlayerType1& player1):Player(player1) {


}

Player* PlayerType1 ::clone(){

    Player* ret;
    ret = new PlayerType1(*this);
    return ret;

}



int PlayerType1 :: requiredValue(){

    return valueForPlayer1();
}
int PlayerType1::getStrategy(){
    return 1;
}

int PlayerType1::getpostionRequired(){
    return postionRequired;
}


void PlayerType1::setpostionRequired(){
    postionRequired+=1;
}

//---------------------------------------------------------------------------------


//****playertype 2

PlayerType2::PlayerType2(string name):Player(name){

}

PlayerType2::PlayerType2(const PlayerType2& player2):Player(player2) {



}

Player* PlayerType2 ::clone(){

    Player* ret;
    ret = new PlayerType2(*this);
    return ret;

}



int PlayerType2 :: requiredValue(){

    return valueForPlayer2();

}
int PlayerType2::getStrategy(){
    return 2;
}
int PlayerType2::getpostionRequired(){
    return postionRequired;
}

void PlayerType2::setpostionRequired(){
    postionRequired+=1;
}
//------------------------------------------------------------------------------------

//****playertype 3
PlayerType3::PlayerType3(string name):Player(name){

}

PlayerType3::PlayerType3(const PlayerType3& player3):Player(player3) {



}


Player* PlayerType3 ::clone(){

    Player* ret;
    ret = new PlayerType3(*this);
    return ret;

}



int PlayerType3 :: requiredValue(){

    return valueForPlayer3();

}

int PlayerType3::getStrategy(){
    return 3;
}

int PlayerType3::getpostionRequired(){
    return postionRequired;
}

void PlayerType3::setpostionRequired(){
    postionRequired+=1;
}
//------------------------------------------------------------------------------------

//****playertype 4


PlayerType4::PlayerType4(string name):Player(name){

}
PlayerType4::PlayerType4(const PlayerType4& player4):Player(player4) {



}

Player* PlayerType4 ::clone(){

    Player* ret;
    ret = new PlayerType4(*this);
    return ret;

}






int PlayerType4 :: requiredValue(){

    return valueForPlayer4();

}



int PlayerType4::getStrategy(){
    return 4;
}

int PlayerType4::getpostionRequired(){
    return postionRequired;
}
void PlayerType4::setpostionRequired(){
    postionRequired+=1;
}
