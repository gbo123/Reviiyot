

#include "Game.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;




// copy constructor

 Game::Game(const Game& other):players(),deck(other.deck),verbal(other.verbal),highestNumeric(other.highestNumeric),turn() {

    for (unsigned int i=0; i<other.players.size();i++){
            Player* p;
            p=other.players.at(i)->clone() ;
            players.push_back(p);


    }






 }
//destructor

Game::~Game(){
    for (unsigned int i=0; i<players.size();i++) {
        delete players.at(i);

    }
}


//config constructor
Game::Game(char* configurationFile):players(), deck(),verbal(),highestNumeric(),turn() {

    ifstream file;
    file.open(configurationFile);
    
    
        string line;
        int counter = 0;
        if(file.is_open()){
            while (getline(file, line)) {
                if (!line.empty()) {
                    if (line[0] != '#') {
                        if (counter == 0) {
                            stringstream ss(line);
                            int x;
                            ss >> x;


                            verbal = x;
                            counter += 1;
                            continue;
                        }

                        if (counter == 1) {
                            stringstream ss(line);
                            int x;
                            ss >> x;

                            int p = x;
                            highestNumeric = p;
                            counter += 1;
                            continue;
                        }


                        if (counter == 2) {
                            string input = line;
                            istringstream ss(input);
                            string token;

                            while (std::getline(ss, token, ' ')) {

                                deck.insert(convertStringToCard(token));

                            }
                            counter += 1;
                            continue;
                        }


                        if (counter == 3) {
                            string input2 = line;
                            istringstream ss(input2);
                            string token;
                            int count = 0;
                            string name;
                            string number;
                            while (std::getline(ss, token, ' ') && count < 2) {
                                if (count == 0) {
                                    name = token;
                                    count += 1;
                                    continue;
                                }
                                if (count == 1) {
                                    number = token;
                                    count += 1;
                                    continue;
                                }

                            }


                            if (number == "1") {
                                players.push_back(new PlayerType1(name));
                                continue;
                            }

                            if (number == "2") {
                                players.push_back(new PlayerType2(name));
                                continue;
                            }


                            if (number == "3") {
                                players.push_back(new PlayerType3(name));
                                continue;
                            }


                            if (number == "4") {
                                players.push_back(new PlayerType4(name));
                                continue;
                            }


                        }
                    }

                }
            }

        }


}


void Game::printState(){


    cout<<"Deck: "<<deck.toString()<<endl;
    for(unsigned int i=0;i<players.size();i++){
        cout<<players.at(i)->toString()<<endl;

    }



}


string Game::askValue(int value){
    string s;
    if (value==-1){
        s="A";
    }

    if (value==-2){
        s="K";
    }

    if (value==-3) {
        s = "Q";
    }
    if (value==-4){
        s="J";
    }
    return s;

}

void Game:: printWinner(){
    int counter=0;
    for (unsigned int i=0; i<players.size();i++){
        if(players.at(i)->getNumberOfCards()==0){
            counter+=1;
        }
    }

    if (counter==1){
        for(unsigned int i=0; i<players.size();i++){
            if (players.at(i)->getNumberOfCards()==0){
             cout<<"***** The Winner is: "<<players.at(i)->getName()<<" *****"<<endl;

            }

        }
    }

    if (counter==2){
        unsigned int winner1=-1;
        unsigned int winner2=-1;
        bool ans=0;
        for (unsigned int i=0; i<players.size(); i++){
             if (players.at(i)->getNumberOfCards()==0 && ans==0){
                 winner1= i;
                                 ans+=1;
                 

             }
              if (players.at(i)->getNumberOfCards()==0 && i!=winner1 && ans==1){
                  winner2=i;
              }

        }

        cout<<"***** The winners are: "<<players.at(winner1)->getName()<<" and "<<players.at(winner2)->getName()<<" *****"<<endl;

    }



}

void Game::printNumberOfTurns() {

    cout<<"Number of turns: "<<turn<<endl;

}








//-----------------------------------------------------------------------------------------------------------------------------

Card* Game:: convertStringToCard(string s){


    Card* c;

    if (s.at(0)=='1' || s.at(0)=='2' || s.at(0)=='3' || s.at(0)=='4' || s.at(0)=='5' || s.at(0)=='6' || s.at(0)=='7' || s.at(0)=='8' || s.at(0)=='9'){

        string line=s.substr(0,s.length()-1);
        stringstream ss(line);
        int x;
        ss >> x;
        int p = x;
        if(s.at(s.length()-1)=='C'){

            c=new NumericCard(Club, p);

        }

        if(s.at(s.length()-1)=='D'){

            c=new NumericCard(Diamond, p);

        }
        if(s.at(s.length()-1)=='H'){

            c=new NumericCard(Heart, p);

        }
        if(s.at(s.length()-1)=='S'){

            c=new NumericCard(Spade, p);

        }



    }



    else {

        if (s.at(0) == 'A') {
            if (s.at(s.length() - 1) == 'C') {

                c = new FigureCard(Club, Ace);

            }

            if (s.at(s.length() - 1) == 'D') {

                c = new FigureCard(Diamond, Ace);

            }
            if (s.at(s.length() - 1) == 'H') {

                c = new FigureCard(Heart, Ace);

            }
            if (s.at(s.length() - 1) == 'S') {

                c = new FigureCard(Spade, Ace);

            }

        }


        if (s.at(0) == 'K') {
            if (s.at(s.length() - 1) == 'C') {

                c = new FigureCard(Club, King);

            }

            if (s.at(s.length() - 1) == 'D') {

                c = new FigureCard(Diamond, King);

            }
            if (s.at(s.length() - 1) == 'H') {

                c = new FigureCard(Heart, King);

            }
            if (s.at(s.length() - 1) == 'S') {

                c = new FigureCard(Spade, King);

            }


        }


        if (s.at(0) == 'Q') {
            if (s.at(s.length() - 1) == 'C') {

                c = new FigureCard(Club, Queen);

            }

            if (s.at(s.length() - 1) == 'D') {

                c = new FigureCard(Diamond, Queen);

            }
            if (s.at(s.length() - 1) == 'H') {

                c = new FigureCard(Heart, Queen);

            }
            if (s.at(s.length() - 1) == 'S') {

                c = new FigureCard(Spade, Queen);

            }


        }


        if (s.at(0) == 'J') {
            if (s.at(s.length() - 1) == 'C') {

                c = new FigureCard(Club, Jack);

            }

            if (s.at(s.length() - 1) == 'D') {

                c = new FigureCard(Diamond, Jack);

            }
            if (s.at(s.length() - 1) == 'H') {

                c = new FigureCard(Heart, Jack);

            }
            if (s.at(s.length() - 1) == 'S') {

                c = new FigureCard(Spade, Jack);

            }


        }

    }
    return c;
}

//-----------------------------------------------------------------------------------------------

int Game:: getVerbal() const{
    return verbal;

}
int Game:: getHighestNumeric()const {
    return highestNumeric;

}

//depends on the player strategy this function returns the player from the player to ask form cards 


Player* Game::whoToAsk(Player* player){
    Player* p;

    if(player->getStrategy()==1 || player->getStrategy()==2){
        if(player->toString().compare(players.at(players.size()-1)->toString())==0){
            p=players.at(players.size()-2);
            int max= p->getNumberOfCards();
            for(int i=players.size()-3; i>=0; i--){
                if (players.at(i)->getNumberOfCards()>max){
                    max=players.at(i)->getNumberOfCards();
                    p=players.at(i);
                }
            }

            return p;
        }
        else{
            p=players.at(players.size()-1);
            int max= p->getNumberOfCards();
            for(int i=players.size()-2; i>=0; i--){
                if (players.at(i)->toString().compare(player->toString())!=0 && players.at(i)->getNumberOfCards()>max){
                    max=players.at(i)->getNumberOfCards();
                    p=players.at(i);
                }
            }

            return p;
        }





    }
    else{
        int size= players.size();
        int required= player->getpostionRequired();
        int suppose= required% size;

        if (players.at(suppose)->toString().compare(player->toString())==0){
            player->setpostionRequired();
            int required= player->getpostionRequired();
            suppose=required% size;
            p=players.at(suppose);
            player->setpostionRequired();
            return p;

        }

        else{


            p=players.at(suppose);
            player->setpostionRequired();
            return p;


        }


    }







}

bool  Game::hasWinner(){
    bool ans=0;
    for(unsigned int i=0; i<players.size() && ans==0;i++){
        if(players.at(i)->getNumberOfCards()==0){
            ans=1;

        }




    }

    return ans;

}




void Game:: init(){

    for(unsigned int i=0;i<players.size(); i++){
        for (int j=0; j<7; j++){
            players.at(i)->addCard(*deck.fetchCard());

        }
        if (players.at(i)->hasFour()){
            players.at(i)->RemoveFour(players.at(i)->hasFournumber());


        }

    }



}




void Game:: play(){

    turn=0;
    bool ans=hasWinner();
    while(ans==0){
        int play=turn%players.size();
        Player* p= players.at(play);
        Player* d= whoToAsk(p);
        int Value= p->requiredValue();
        if (verbal==1){
        cout<<"turn: "  <<turn+1<<endl;
        printState();

        if (Value<0){
            cout<<p->getName()<<" asked "<<d->getName()<<" for the value "<<askValue(Value)<<endl;
            cout<<"       "<<endl;
        }
         if (Value>0){
             cout<<p->getName()<<" asked "<<d->getName()<<" for the value "<<p->requiredValue()<<endl;
             cout<<"        "<<endl;
         }

        }


        if(p->hasCard(d, Value)){
            int draw= d->howMuchInHand(Value);
            p->fetchCards(d,d->howMuchInHand(Value), Value );
            for( int i=0; i<draw && deck.getNumberOfCard()>0; i++){
                d->addCard(*deck.fetchCard());
                if(d->hasFour()){
                    d->RemoveFour(d->hasFournumber());
                }



            }
        }

        else{
            if(deck.getNumberOfCard()>0){
                p->addCard(*deck.fetchCard());
            }

        }


        for(unsigned int i=0; i<players.size();i++){
            if(players.at(i)->hasFour()){
                players.at(i)->RemoveFour(players.at(i)->hasFournumber());
            }
        }



        turn+=1;

        ans=hasWinner();




    }

        




}
















