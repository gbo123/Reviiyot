

#include "Card.h"

#include <iostream>

#include <sstream>  //include this to use string streams
#include <string>



using namespace std;


//****Card functions****

Card::Card(Shape s): shape(s), sName(),shapeValue(){
    switch (s){
        case Club:sName="C";shapeValue=1;break;
        case Diamond:sName="D";shapeValue=2;break;
        case Heart:sName="H";shapeValue=3;break;
        case Spade:	sName="S";shapeValue=4;break;
    }
}


string Card :: getShape() const{
    return sName;
}
int Card::getShapeValue()const{
    return shapeValue;
}


Card::~Card(){}// a destructor no used because of the Card fields

Shape Card:: getShapeToShape(string shape){

    Shape s;

    if (shape=="C"){
        s=Club;
    }

    if (shape=="D"){
        s=Diamond;
    }

    if (shape=="H"){
        s=Heart;
    }

    if (shape=="S"){
        s=Spade;
    }


    return s;
}



///----------------------------------------------------------------------------------------***





//**** FigureCard functions ****

FigureCard :: FigureCard(Shape s, Figure f):Card(s), figure(f), fName(), value() { // the values are negative to compare with numeric cards

    switch (f){
        case Jack: fName="J";value= -4;  break;
        case Queen:fName="Q";value= -3;break;
        case King:fName="K";value= -2;break;
        case Ace:fName="A";value = -1;break;
    }
}

string FigureCard :: getFigure()const {
    return fName;
}
int FigureCard:: getValue()const{
    return value;
}

string FigureCard::toString(){
    return getFigure() + getShape() ;
}


Figure FigureCard::getFigureToFigure(string figure){
    Figure f;

    if (figure=="J"){
        f=Jack;
    }

    if (figure=="K"){
        f=King;
    }

    if (figure=="Q"){
        f=Queen;
    }

    if (figure=="A"){
        f=Ace;
    }


    return f;
}

Card* FigureCard::clone() {

    FigureCard* ret= new FigureCard( this->getShapeToShape(this->getShape()) , this->getFigureToFigure(this->getFigure()));
    return ret;

}

///----------------------------------------------------------------------------------------***

Figure NumericCard::getFigureToFigure(string figure){// not used


    Figure s= Jack;
    return s;
}


//**** NumericCard functions ****

NumericCard::NumericCard(Shape s, int num):Card(s), number(num),value(num) {


}

Card* NumericCard::clone() {

    NumericCard* ret = new NumericCard(this->getShapeToShape(this->getShape()), this->getValue() );

        return ret;


}




string NumericCard::getNumber() const{

    int num= number;
    ostringstream ostr;
    ostr<<num;
    string numberstring= ostr.str();

    return numberstring;}

int NumericCard::getValue() const {
    return value;
}

string NumericCard::toString(){
    return (getNumber()) + getShape();
}






