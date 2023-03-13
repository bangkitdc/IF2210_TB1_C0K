#include "Player.cpp"
#include "C:\Users\ASUS\TB1OOP\IF2210_TB1_C0K\src\class\cardValue\card.cpp"
#include "tableCard.cpp"
#include "inventoryHolder.cpp"
#include "deckCard.cpp"
int main(){
    DeckCard game1;
    Player p1("Player 1");
    p1.setCard2(game1);
    p1.displayPlayer();
    tableCard table1;
    game1.displayDeckCard();
    // table1+game1;
    // table1+game1;
    // table1+game1;
    // table1+game1;
    // table1+game1;
    // game1.displayDeckCard();
    // p1.displayPlayer();
    // table1.displayTCard();

    // vector<Card> temp=p1.evaluateCard(table1);
    // for (int i=0;i<temp.size();i++){
    //     temp[i].displayCard();
    // }
    // Player p1;
    // tableCard table1;
    // p1+game1; //kartu p1 ditambah kartu dari deckCard
    // table1+game1; //kartu table1 ditambah kartu dari deckCard
    // p1.displayPlayer();
    // table1.displayTCard();
    
    // // p1-game1;
    // // p1.displayPlayer();
    // game1.displayDeckCard();



}