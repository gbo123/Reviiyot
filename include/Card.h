
#ifndef CARD_H_
#define CARD_H_

#include <iostream>
using namespace std;

enum Shape {
    Club,
    Diamond,
    Heart,
    Spade
};

enum Figure {
    Jack,
    Queen,
    King,
    Ace
};


//****class Card****

class Card {
private:
    Shape shape;
    string sName;
    int shapeValue;


public:
    virtual Card* clone()=0;// a  function used to clone cards when copying a Deck or a Hand
    Card(Shape s);// a simple constructor
    string getShape() const;// return a string when using the toString function
    virtual string toString() = 0; //Returns the string representation of the card "<value><shape>" exp: "12S" or "QD"

    int getShapeValue()const;// return the shape value form 1-4
    virtual int getValue() const =0;// used to determined if the card is figure or numeric
    Shape getShapeToShape(string shape);// use to convert string funtion getShape to a shape when cloning
    virtual Figure getFigureToFigure(string figure)=0;// use to convert string funtion getfigure to a figure when cloning
    //didn't implement yet
    virtual ~Card();

};
///----------------------------------------------------------------------------------------***

//****Figure Card****

class FigureCard : public Card {
private:
    Figure figure;
    string fName;// string representing the figure when using the toString function
    int value;// a int used to compare between numeric and figure cards

public:
    FigureCard(Shape s, Figure f);// constructor
    string getFigure() const;//return a string representing the figure
    virtual string toString() override;// a tostring function
    Figure getFigureToFigure(string figure);// use to convert string funtion getfigure to a figure when cloning.
    int getValue() const ;// used to determined if the card is figure or numeric
    Card* clone(); // a  function used to clone cards when copying a Deck or a Hand





};

///----------------------------------------------------------------------------------------***

//****NumericCard****

class NumericCard : public Card {
private:
    int number=0;
    int value;// a int used to compare between numeric and figure cards

public:

    NumericCard(Shape s, int num);// a constructor
    string getNumber() const;// used when the toString function is implemented
    virtual string toString() override;
    int getValue() const;// used to determined if the card is figure or numeric
    Card* clone();// a  function used to clone cards when copying a Deck or a Hand
    Figure getFigureToFigure(string figure);// use to convert string funtion getfigure to a figure when cloning. not used with numeric.


};

#endif

