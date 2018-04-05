/*
 * Hand.h
 *
 *  Created on: Nov 20, 2016
 *      Author: gilbeno
 */

#ifndef HAND_H_
#define HAND_H_

#include <iostream>
#include "Card.h"
#include <vector>

class Hand {
private:
    vector <Card*> hand;
public:
    Hand(const Hand& other);//copy constructor
    Hand();//empty constructor
    int getNumberOfCards();// Get the number of cards in hand
    string toString(); // Return a list of the cards, separated by space, in one line, in a sorted order
    void insert(Card* card);// a method for inserting card to the hand
    void sort();// a method used to sort the hand
    int valueForPlayer1();// returns a value representing the PlayerType 1 strategy
    int valueForPlayer2();// returns a value representing the PlayerType 2 strategy
    int valueForPlayer3();// returns a value representing the PlayerType 3 strategy
    int valueForPlayer4();// returns a value representing the PlayerType 4 strategy
    bool isInHand(int Value);//search hand for value
    bool hasFour();// a method to check if there is a set in hand
    int hasFournumber(); // returns the value of the set
    void RemoveFour(int Value); // a method to remove the set
    void remove(int Value);// a method to remove a card from hand- used in remove four
    Card* fetchCard(int Value);//returns a card when need to
    int howMuchInHand(int value);//returns how many cards are form the same value in one's hand

    ///***********************didn't implement yet- need to
    bool addCard(Card &card);
    bool removeCard (Card &card);
    bool isWinner();//
    void removeForFour(int Value);
    virtual ~Hand();




};

#endif /* HAND_H_ */
