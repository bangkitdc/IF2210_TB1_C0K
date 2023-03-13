#include "deckCard.cpp"
#include "inventoryHolder.cpp"
#include "../cardValue/card.cpp"
#include "../cardValue/combination.cpp"
#include <iostream>
#include "tableCard.cpp"
#include "Player.cpp"
using namespace std;


int main(){
    Combination c;
    vector<Card> cards, res;
    DeckCard d;
    d.shuffleCard();
    Player p1("icad",&d);
    Player p2("jedan",&d);
    Player p3("bagas",&d);
    Player p4("bangkit",&d);
    tableCard t;

    Card spc1(10, "merah");
    Card spcc1(11, "biru");
    vector<Card> setpc;
    setpc.push_back(spc1);
    setpc.push_back(spcc1);
    p1.setCards(setpc);

    Card spc2(10, "biru");
    Card spcc2(11, "kuning");
    vector<Card> setpc2;
    setpc2.push_back(spc2);
    setpc2.push_back(spcc2);
    p2.setCards(setpc2);

    Card spc3(6, "biru");
    Card spcc3(7, "kuning");
    vector<Card> setpc3;
    setpc3.push_back(spc3);
    setpc3.push_back(spcc3);
    p3.setCards(setpc3);

    Card spc4(9, "merah");
    Card spcc4(9, "kuning");
    vector<Card> setpc4;
    setpc4.push_back(spc4);
    setpc4.push_back(spcc4);
    p4.setCards(setpc4);

    Card x(5,"merah");
    Card y(7,"hijau");
    Card z(1,"hijau");
    Card zz(8,"kuning");
    Card yy(9,"biru");
    
    vector<Card> temp;
    
    temp.push_back(x);
    temp.push_back(y);
    temp.push_back(z);
    temp.push_back(zz);
    temp.push_back(yy);
    // t.setTCard(&d);
    // t.setTCard(&d);
    // t.setTCard(&d);
    // t.setTCard(&d);
    // t.setTCard(&d);
    cards=temp;
    vector<Card> pcards1 = p1.getCards();
    vector<Card> pcards2 = p2.getCards();
    vector<Card> pcards3 = p3.getCards();
    vector<Card> pcards4 = p4.getCards();
    vector<Card> pc1, pc2, pc3, pc4, pc5;

    cout << "INI KARTU ICAD" << endl;
    for (int i=0; i<pcards1.size(); i++){
        
        cout << pcards1[i].getNum() << pcards1[i].getWarna() << endl;
    }
    cout << "=====================" << endl;

    cout << "INI KARTU JEDAN" << endl;
    for (int i=0; i<pcards2.size(); i++){
        
        cout << pcards2[i].getNum() << pcards2[i].getWarna() << endl;
    }
    cout << "=====================" << endl;

    cout << "INI KARTU BAGAS" << endl;
    for (int i=0; i<pcards3.size(); i++){
        
        cout << pcards3[i].getNum() << pcards3[i].getWarna() << endl;
    }
    cout << "=====================" << endl;

    cout << "INI KARTU BANGKIT" << endl;
    for (int i=0; i<pcards4.size(); i++){
        
        cout << pcards4[i].getNum() << pcards4[i].getWarna() << endl;
    }
    cout << "=====================" << endl;

    cout << "INI KARTU TABLE" << endl;
    for (int i=0; i<cards.size(); i++){
        
        cout << cards[i].getNum() << cards[i].getWarna() << endl;
    }
    cout << "=====================" << endl;

    vector<double> resp;

    vector<Card> gabungan = cards;
    pc1 = pcards1, pc2 = pcards2, pc3 = pcards3, pc4 = pcards4;
    for (int i=0; i<cards.size(); i++){
        pc1.push_back(cards[i]);
        pc2.push_back(cards[i]);
        pc3.push_back(cards[i]);
        pc4.push_back(cards[i]);
    }
    cout << "buggg" << endl;

    double p = c.priorityCard(pc1);
    resp.push_back(p);
    cout << "nilai evaluatenya " << p << endl;
    p = c.priorityCard(pc2);
    resp.push_back(p);
    cout << "nilai evaluatenya " << p << endl;
    p = c.priorityCard(pc3);
    resp.push_back(p);
    cout << "nilai evaluatenya " << p << endl;
    p = c.priorityCard(pc4);
    resp.push_back(p);
    cout << "nilai evaluatenya " << p << endl;

    // cout << "INI GABUNGAN CARD" << endl;
    // for(int i = 0; i<gabungan.size(); i++){
    //     cout << gabungan[i].getNum()  << " " << gabungan[i].getWarna() << endl;
    // }
    // cout << "=====================" << endl;

    // cout << "bug 1"<< endl;
    // if(c.hasTwoPair(gabungan)){
    //     cout << "ADA TWO PAIR" << endl;
    // }
    // if(c.hasThreeOfAKind(gabungan)){
    //     cout << "ADA THREES" << endl;
    // }
    // if(c.hasFullHouse(gabungan)){
    //     cout << "ADA" << endl;
    //     res = c.fullHouse(gabungan);
    //     cout << res.size() << endl;
    //     for(int i = 0; i <res.size(); i++){
    //         cout << res[i].getNum() << " " << res[i].getWarna() << endl;
    //     }
    // } else {
    //     cout << "Tidak ada \n" ;
    // }


}
