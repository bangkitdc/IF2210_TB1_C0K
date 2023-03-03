#include "deckCard.hpp"
#include <random>
#include <algorithm>

DeckCard::DeckCard() : InventoryHolder ("DeckCard"){
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"Merah"));
    }    
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"Kuning"));
    }    
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"Biru"));
    }    
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"Hijau"));
    }    
}

DeckCard::~DeckCard(){}

void DeckCard::displayDeckCard(){
    for (auto elem : DeckCard::cards) {
        elem.displayCard();
    }
}

void DeckCard::shuffleCard(){
    auto rng = std::default_random_engine {};
    std::shuffle(begin(cards), end(cards), rng);
}

vector<Card> DeckCard::getCards(){
    return cards;
    
}
DeckCard& DeckCard::operator-(const Card & a){
    for(int i=0;i<cards.size();i++){
        if (cards[i].getNum()==a.getNum() && cards[i].getWarna().compare(a.getWarna())==0 ){
            cards.erase(cards.begin()+i);
        }
    }
    return *this;
}

void DeckCard::deleteCard(Card a){
    for(int i=0;i<cards.size();i++){
        if (cards[i].getNum()==a.getNum() && cards[i].getWarna().compare(a.getWarna())==0 ){
            cards.erase(cards.begin()+i);
        }
    }
}

Card DeckCard::getCard(){
    // shuffleCard();
    Card temp=cards[cards.size()-1];
    cards.pop_back();
    return temp;

    
}

DeckCard& DeckCard::operator+(const Card &a){
    cards.push_back(a);
    return *this;
}

DeckCard& DeckCard::operator=(const DeckCard &a){
    this->cards=a.cards;
    return *this;
}
void DeckCard::setCards(vector<Card> a){
    cards=a;
}