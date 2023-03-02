#include "player.hpp"
#include <vector>
#include <iostream>
using namespace std;

int Player::totalPlayer = 0;

Player::Player(string a,DeckCard *deck) : InventoryHolder("player"), id(Player::totalPlayer + 1) {
    this->username=a;
    setCard(deck);
    this->point=0;

    Player::totalPlayer ++;
}

void Player::setCard(DeckCard *deck){
    for (int i=0;i<2;i++){
        this->cardsP.push_back(deck->getCard());
    }
} 

Player::~Player(){
}

vector<Card> Player::getCards(){
    return cardsP;
}

void Player::setName(string name){
    this->username=name;
}

void Player::addPoint(double addP){
    this->point+=addP;
}

double Player::getPoint()const{
    return this->point;
}

string Player::getName()const{
    return this->username;
}


void Player::displayPlayer(){
    cout << "Name : " << this->getName() <<endl;
    cout << "Card : \n" ;
    for (int i=0;i<cardsP.size();i++){
        cardsP[i].displayCard();
    }
    cout << "Point : " << this->getPoint() <<endl;
}

Player& Player::operator+(Card a){
    cardsP.push_back(a);
    return *this;
}

Player& Player::operator-(Card a){
    for(int i=0;i<cardsP.size();i++){
        if (cardsP[i].getNum()==a.getNum() && cardsP[i].getWarna().compare(a.getWarna())==0 ){
            cardsP.erase(cardsP.begin()+i);
        }
    }
    return *this;
}

void Player::setCards(vector<Card> a){
    cardsP=a;
}
    
