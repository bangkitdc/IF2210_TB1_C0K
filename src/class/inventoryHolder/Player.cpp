#include "player.hpp"
#include <vector>
#include <iostream>
using namespace std;



Player::Player(string a,DeckCard *deck):InventoryHolder(a){
    this->username=a;
    setCard(deck);
    this->point=0;
}

void Player::setCard(DeckCard *deck){
    for (int i=0;i<2;i++){
        this->cardsP.push_back(deck->getCard());
    }
} 
Player::Player(){

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