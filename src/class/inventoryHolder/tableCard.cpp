#include "tableCard.hpp"
using namespace std;

tableCard::tableCard():InventoryHolder("TableCard"){
}
tableCard::~tableCard(){}

void tableCard::setTCard(DeckCard *deck){
    Tcards.push_back(deck->getCard());
}

void tableCard::displayTCard(){
    cout << "=======Kartu Table Sekarang======" << endl;
    cout << "\t";
    for(int i=0;i<Tcards.size();i++){
        Tcards[i].displayCard();
    }
}

vector<Card> tableCard::getCards(){
    return Tcards;
}