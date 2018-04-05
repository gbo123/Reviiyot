/*
 * Hand.cpp
 *
 *  Created on: Nov 20, 2016
 *      Author: gilbeno
 */

#include "Hand.h"
#include <vector>
#include <algorithm>

//*******Auxiliary function for comparing cards used to sort them*****

bool myCompare(Card* c1, Card* c2) {

    if (c1->getValue() == c2->getValue()) {
        return !(c1->getShapeValue() > c2->getShapeValue());
    }

    else if (c1->getValue() > 0 && c2->getValue() > 0) {
        return !(c1->getValue() > c2->getValue());
    }
    else if (c1->getValue() > 0 && c2->getValue() < 0) {
        return !!(c1->getValue() > c2->getValue());
    }
    else if (c1->getValue() < 0 && c2->getValue() > 0) {
        return !!(c1->getValue() > c2->getValue());
    }
    else  
        return !(c1->getValue() > c2->getValue());
    
    
}


////----------------------------------------------------------------------------------------------------

Hand::Hand() :hand() {}

Hand::Hand(const Hand& other):hand(){
    for(unsigned int i=0; i<other.hand.size();i++){
        hand.push_back(other.hand.at(i)->clone());
    }
}


void Hand::sort(){
    std::sort (hand.begin(), hand.end(), myCompare);

}



int Hand::getNumberOfCards() {
    return hand.size();
}
string Hand:: toString(){
    string str = "";
    for (std::vector<Card*>::iterator i = hand.begin(); i != hand.end(); i++) {
        str += (*i)->toString() + " ";
    }
    return str;
}




bool Hand::isInHand(int value){
    bool ans=0;
    int target= value;
    for (unsigned int i=0; i<hand.size()&& ans==0 ;i++) {
        if (hand.at(i)->getValue() == target){
            ans=1;

        }
    }
    return ans;

}

void Hand::insert(Card* card) {
    hand.push_back(card);
    sort();
}

int Hand::valueForPlayer1(){
    int previous = hand.back()->getValue();
    int popular = hand.back()->getValue();
    int count = 1;
    int maxCount = 1;
    int last=hand.size()-1;
    for (unsigned int i=last; i>0 ;i--) {
        if (hand.at(i-1)->getValue() == previous){
            count++;
        }

        if (count > maxCount) {
            popular = hand.at(i)->getValue();
            maxCount = count;
        }

        if (hand.at(i-1)->getValue() != previous){
            previous = hand.at(i-1)->getValue();
            count = 1;

        }


    }

    return  popular;

}


int Hand::valueForPlayer2(){
    int previous = hand.front()->getValue();
    int popular = hand.front()->getValue();
    int count = 1;
    int minCount = 700000000;
    int k=1;
    for ( unsigned int i=1; i<hand.size();i++) {
        if (hand.at(i)->getValue() == previous)
            count++;
        else {
            if (count  < minCount) {
                popular = hand.at(i-1)->getValue();
                minCount = count;
            }
            previous = hand.at(i)->getValue();
            count = 1;
        }

        k=i;
    }


    if (count  < minCount) {
        popular = hand.at(k - 1)->getValue();
        minCount = count;
    }


    return  popular;

}



int Hand::valueForPlayer3(){
    return hand.back()->getValue();
}

int Hand::valueForPlayer4(){

    return hand.front()->getValue();
}
bool Hand:: hasFour(){

    bool ans=0;
    int previous = hand.front()->getValue();
    int count = 1;
    for (unsigned int i=1; i<hand.size() && ans==0;i++) {
        if (hand.at(i)->getValue() == previous){
            count++;
        }

        else {
            if (count == 4) {
                ans=1;
            }

            previous = hand.at(i)->getValue();
            count = 1;
        }
        if (count==4){
            ans=1;
        }

    }


    return ans;



}

int Hand:: hasFournumber(){

    int previous = hand.front()->getValue();
    int popular = hand.front()->getValue();
    int count = 1;

    for (unsigned int i=1; i<hand.size()&& count<4;i++) {
        if (hand.at(i)->getValue() == previous){
            count++;
            if(count==4){
                popular=hand.at(i)->getValue();
            }
        }

        else{
            previous = hand.at(i)->getValue();
            count = 1;
        }


    }

    return  popular;

}



void Hand::remove(int Value){/****** need to destruct card in this method  */
    bool ans=0;
    for (unsigned int i=0; i<hand.size()&& ans==0;i++) {
        if (hand.at(i)->getValue() == Value){
           removeCard(*hand.at(i));
                ans=1;
        }

    }

    sort();



}

void Hand::removeForFour(int Value){
    bool ans=0;
    for (unsigned int i=0; i<hand.size()&& ans==0;i++) {
        if (hand.at(i)->getValue() == Value){
            Card* c=hand.at(i);
            hand.erase(hand.begin()+i);
            delete c;
            ans=1;
        }

    }

    sort();



}







void Hand::RemoveFour(int Value){

    for(int i=0;i<4;i++){
        removeForFour(Value);
    }

}







bool Hand::isWinner(){
    return getNumberOfCards()==0;
}
Card* Hand::fetchCard(int Value){
    bool ans=0;
    Card* c;
    for (unsigned int i=0;i<hand.size()&& ans==0;i++){
        if (hand.at(i)->getValue()==Value){
            c= hand.at(i);
            ans=1;
            remove(Value);
            sort();
        }


    }

    return c;

}


int Hand::howMuchInHand(int value){
    int ans=0;
    for (unsigned int i=0;i<hand.size();i++){
        if(hand.at(i)->getValue()==value){
            ans+=1;
        }



    }

    return ans;
}


bool Hand::addCard(Card &card){
    
    hand.push_back(&card);
    sort();
    
    return 1;
    
    
}
bool Hand::removeCard(Card &card){
  
    bool ans=0;
    for(unsigned int i=0;i<hand.size() && ans==0;i++){
        if(hand.at(i)->toString().compare(card.toString())==0){
            hand.erase(hand.begin()+i);
            ans=1;
        }
    
    
}
 sort();
 
 return 1;
 
 
}
 


Hand::~Hand(){
for (unsigned int i=0; i<hand.size();i++) {
    delete hand.at(i);

}
}


