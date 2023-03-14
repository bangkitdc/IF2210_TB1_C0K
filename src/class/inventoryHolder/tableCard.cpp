#include "tableCard.hpp"
#include "../exception/cardException.hpp"
using namespace std;

tableCard::tableCard():InventoryHolder("TableCard"){
}
tableCard::~tableCard(){}

void tableCard::setTCard(DeckCard *deck){
    Tcards.push_back(deck->getCard());
}

void tableCard::displayTCard(){
    if (Tcards.size() != 0) {
        cout << "=================Kartu Meja Sekarang=================" << endl;
        for(int i=0;i<Tcards.size();i++){
            Tcards[i].displayCard();   
        }
    } else {
        cout << "Kartu meja saat ini kosong :(" << endl;
    }
}

vector<Card> tableCard::getCards(){
    return Tcards;
}

Card tableCard::getFirstCard() {
    return Tcards[0];
}

Card tableCard::getCard() {
    Card temp = Tcards[Tcards.size() - 1];
    Tcards.pop_back();
    return temp;
}

Card tableCard::getCardWithoutPop(int i) {
    return Tcards[i];
}

void tableCard::addCard(Card c) {
    this->Tcards.push_back(c);
}

void tableCard::addMilik(int i) {
    this->kartuMilik.push_back(i);
}

int tableCard::getMilik(int i) {
    return this->kartuMilik[i];
}

void tableCard::clearMilik() {
    this->kartuMilik.clear();
}

void tableCard::setCards(vector<Card> a){
    Tcards=a;
}

tableCard& tableCard::operator+(DeckCard &a){
    if(Tcards.size()==5){
        throw TablePenuhException();//TableCardFull()
    }
    Tcards.push_back(a.getCard());
    return *this;
}

tableCard& tableCard::operator-(DeckCard &a){
    if(Tcards.size()==0){
        throw TableKosongException();
    }
    a.addCard(Tcards[Tcards.size()-1]);
    Tcards.pop_back();
    return *this;
}

bool tableCard::isTCardEmpty() {
    return getCards().size() == 0;
}

void addPlayerCard(tableCard& t, Player &p, int i) {
    t.addCard(p.getPlayerCard(i));
    t.addMilik(p.getId());
}