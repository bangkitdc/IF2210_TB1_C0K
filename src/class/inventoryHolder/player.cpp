#include "player.hpp"
#include "../exception/cardException.hpp"
#include "../ability/ability.hpp"
#include <vector>
#include <iostream>
using namespace std;

int Player::totalPlayer = 0;

Player::Player() : InventoryHolder("player"), id(-1) {
    this->username = "test";
    this->point = 0;
}

Player::Player(string a,DeckCard *deck) : InventoryHolder("player"), id(Player::totalPlayer + 1) {
    this->username=a;
    setCard(deck);
    setCard(deck);
    this->point=0;

    Player::totalPlayer ++;
}

void Player::setCard(DeckCard *deck){

    this->cardsP.push_back(deck->getCard());
    
} 

Ability* Player::getAbility() {
    return this->ability;
}

void Player::setAbility(Ability *abl) {
    this->ability = abl;
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

int Player::getId() const {
    return this->id;
}

double Player::getPoint()const{
    return this->point;
}

string Player::getName()const{
    return this->username;
}


void Player::displayPlayer(){
    cout << "Name : " << this->getName() <<endl;
    cout << "Point : " << this->getPoint() <<endl;
    cout << "Card : \n" ;
    for (int i=0;i<cardsP.size();i++){
        cardsP[i].displayCard();
    }
    
}

void Player::displayPlayerCard(int i){
    cardsP[i].displayCard();
}

Player& Player::operator+(const Card &a){
    if(cardsP.size()==2){
        throw "Player sudah memiliki 2 kartu";
    }
    cardsP.push_back(a);
    return *this;
}

Player& Player::operator+(DeckCard &a){
    if(cardsP.size()==2){
        throw PlayerFullException();
    }
    setCard(&a);
    return *this;
}

Player& Player::operator-(const Card &a){
    for(int i=0;i<cardsP.size();i++){
        if (cardsP[i].getNum()==a.getNum() && cardsP[i].getWarna().compare(a.getWarna())==0 ){
            cardsP.erase(cardsP.begin()+i);
        }
    }
    return *this;
}

Player& Player::operator-(DeckCard &a){
    if(cardsP.size()==0){
        throw PlayerKosongException();
    }
    a.addCard(cardsP[cardsP.size()-1]);
    cardsP.pop_back();
    return *this;
}
Player& Player::operator=(const Player &a){
    this->id = a.id;
    this->cardsP = a.cardsP;
    this->username = a.username;
    this->point = a.point;
    // ability belom
    return *this;
}
void Player::setCards(vector<Card> a){
    cardsP=a;
}

vector<Card> Player::evaluateCard(tableCard a){
    vector<Card> temp;
    vector<Card> tempTable=a.getCards();
    for(int i=0;i<cardsP.size();i++){
        temp.push_back(Card(tempTable[i]));
    }

    for (int i=0;i<a.getCards().size();i++){
        temp.push_back(Card(tempTable[i]));
    }
    return temp;

    
}

double Player::getValueGeneric() {
    return point; 
}