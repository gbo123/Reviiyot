/*
 * Deck.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: gilbeno
 */

#include "Deck.h"
#include "Card.h"
#include <vector>

using namespace std;

Deck::Deck() :deck() {}



Deck::~Deck() {

for(unsigned int i=0; i<deck.size();i++){

    delete deck.at(i);


    }



}



Deck::Deck(const Deck& other):deck(){
    for(unsigned int i=0; i<other.deck.size();i++){
        deck.push_back(other.deck.at(i)->clone());
    }
}




void Deck::insert(Card* card) {
    deck.push_back(card);
}



Card* Deck::fetchCard() {
   

        Card* ans = deck.at(0);
        deck.erase(deck.begin());
        return ans;

    

}



int Deck::getNumberOfCard() {

    return deck.size();
}

string Deck::toString() {
    string str = "";
    for (std::vector<Card*>::iterator i = deck.begin(); i != deck.end(); i++) {
        str += (*i)->toString() + " ";
    }
    return str;
}



