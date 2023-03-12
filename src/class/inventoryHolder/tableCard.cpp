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
    cout << "=================Kartu Meja Sekarang=================" << endl;
    for(int i=0;i<Tcards.size();i++){
        Tcards[i].displayCard();
    }
}

vector<Card> tableCard::getCards(){
    return Tcards;
}

void tableCard::setCards(vector<Card> a){
    Tcards=a;
}

tableCard& tableCard::operator+(DeckCard &a){
    if(Tcards.size()==5){
        throw tablePenuhException();//TableCardFull()
    }
    Tcards.push_back(a.getCard());
    return *this;
}

tableCard& tableCard::operator-(DeckCard &a){
    if(Tcards.size()==0){
        throw tableKosongException();
    }
    a.addCard(Tcards[Tcards.size()-1]);
    Tcards.pop_back();
    return *this;
}