#include "tableCard.hpp"

tableCard::tableCard():InventoryHolder("TableCard"){ }

tableCard::~tableCard(){}

void tableCard::setTCard(DeckCard *deck){
    Tcards.push_back(deck->getCard());
}

void tableCard::displayTCard(){
    cout << endl;
    if (Tcards.size() != 0) {
        cout << CYAN << "======================================================" << endl;
        cout << "=" << RESET << "                 Kartu Meja Sekarang                " << CYAN << "=" << endl;
        cout << "======================================================" << RESET << endl;
        for(int i=0;i<Tcards.size();i++){
            Tcards[i].displayCard(); cout << " ";
        }
        cout << endl;
    } else {
        cout << CYAN << "======================================================" << endl;
        cout << "=" << RESET << "                  Kartu Meja Kosong                 " << CYAN << "=" << endl;
        cout << "======================================================" << RESET << endl;
    }
}

vector<Card> tableCard::getCards(){
    return Tcards;
}

Card tableCard::getFirstCard() {
    return Tcards[0];
}

Card tableCard::getCard() {
    if(Tcards.size()==0){
        throw TableKosongException();
    }
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

void tableCard::clearCards() {
    this->Tcards.clear();
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

void tableCard::sortTableCard() {
    for(int i = 0; i < Tcards.size(); i ++) {
        for(int j = 0; j < Tcards.size() - 1 - i; j ++) {
            if (getCardWithoutPop(j).getNum() < getCardWithoutPop(j + 1).getNum()) {
                Card temp = getCardWithoutPop(j);
                Tcards[j] = Tcards[j + 1];
                Tcards[j + 1] = temp;

                int tempVal = getMilik(j);
                kartuMilik[j] = kartuMilik[j + 1];
                kartuMilik[j + 1] = tempVal;
            }
        }
    }
}

void addPlayerCard(tableCard& t, Player &p, int i) {
    t.addCard(p.getPlayerCard(i));
    t.addMilik(p.getId());
}