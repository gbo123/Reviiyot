/*
 * Deck.h
 *
 *  Created on: Nov 20, 2016
 *      Author: gilbeno
 */

#ifndef DECK_H_
#define DECK_H_
#include <iostream>
#include "Card.h"
#include <vector>

class Deck {
private:
    vector<Card*> deck;
public:
    Deck(const Deck& other);//copy constructor
    Deck();// empty constructor
    void insert (Card*);// a function for inserting cards to the deck
    Card* fetchCard(); //Returns the top card of the deck and remove it from the deck
    int getNumberOfCard();// Get the number of cards in the deck
    string toString();// Return the cards in top-to-bottom order in a single line, cards are separated by a space ex: "12S QD AS 3H"

    //didn't implement yet

    ~Deck();
};

#endif /* DECK_H_ */
