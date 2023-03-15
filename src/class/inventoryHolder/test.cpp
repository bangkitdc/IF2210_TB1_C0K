#include "deckCard.cpp"
#include "inventoryHolder.cpp"
#include "../cardValue/card.cpp"
#include "../cardValue/combination.cpp"
#include <iostream>
#include "tableCard.cpp"
#include "player.cpp"
using namespace std;


int main(){
    Combination c;
    vector<Card> cards, rese;
    vector<vector<Card>> res;
    pair<vector<vector<Card>>, vector<double>> resss, tes1, tes2, tes3, tes4;
    DeckCard d;
    d.shuffleCard();
    Player p1("icad",d);
    Player p2("jedan",d);
    Player p3("bagas",d);
    Player p4("bangkit",d);
    tableCard t;

    Card spc1(5, "biru");
    Card spcc1(6, "merah");
    vector<Card> setpc;
    setpc.push_back(spc1);
    setpc.push_back(spcc1);
    p1.setCards(setpc);

    Card spc2(8, "biru");
    Card spcc2(3, "hijau");
    vector<Card> setpc2;
    setpc2.push_back(spc2);
    setpc2.push_back(spcc2);
    p2.setCards(setpc2);

    Card spc3(6, "biru");
    Card spcc3(7, "merah");
    vector<Card> setpc3;
    setpc3.push_back(spc3);
    setpc3.push_back(spcc3);
    p3.setCards(setpc3);

    Card spc4(12, "merah");
    Card spcc4(9, "hijau");
    vector<Card> setpc4;
    setpc4.push_back(spc4);
    setpc4.push_back(spcc4);
    p4.setCards(setpc4);

    Card x(7,"kuning");
    Card y(8,"kuning");
    Card z(9,"kuning");
    Card zz(10,"kuning");
    Card yy(11,"kuning");
    
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

    // cout << "INI KARTU ICAD" << endl;
    // for (int i=0; i<pcards1.size(); i++){
        
    //     cout << pcards1[i].getNum() << pcards1[i].getWarna() << endl;
    // }
    // cout << "=====================" << endl;

    // cout << "INI KARTU JEDAN" << endl;
    // for (int i=0; i<pcards2.size(); i++){
        
    //     cout << pcards2[i].getNum() << pcards2[i].getWarna() << endl;
    // }
    // cout << "=====================" << endl;

    // cout << "INI KARTU BAGAS" << endl;
    // for (int i=0; i<pcards3.size(); i++){
        
    //     cout << pcards3[i].getNum() << pcards3[i].getWarna() << endl;
    // }
    // cout << "=====================" << endl;

    // cout << "INI KARTU BANGKIT" << endl;
    // for (int i=0; i<pcards4.size(); i++){
        
    //     cout << pcards4[i].getNum() << pcards4[i].getWarna() << endl;
    // }
    // cout << "=====================" << endl;

    // cout << "INI KARTU TABLE" << endl;
    // for (int i=0; i<cards.size(); i++){
        
    //     cout << cards[i].getNum() << cards[i].getWarna() << endl;
    // }
    // cout << "=====================" << endl;

    // vector<double> resp;

    vector<Card> gabungan = cards;
    pc1 = pcards1, pc2 = pcards2, pc3 = pcards3, pc4 = pcards4;
    for (int i=0; i<cards.size(); i++){
        pc1.push_back(cards[i]);
        pc2.push_back(cards[i]);
        pc3.push_back(cards[i]);
        pc4.push_back(cards[i]);
    }
    // cout << "buggg" << endl;

    cout << "kartu gabungan p1" << endl;
    for(int i = 0; i<pc1.size(); i++){
        cout << pc1[i].getNum() << " " << pc1[i].getWarna() << endl;
    }
    cout << "kartu gabungan p2" << endl;
    for(int i = 0; i<pc2.size(); i++){
        cout << pc2[i].getNum() << " " << pc2[i].getWarna() << endl;
    }
    cout << "kartu gabungan p3" << endl;
    for(int i = 0; i<pc3.size(); i++){
        cout << pc3[i].getNum() << " " << pc3[i].getWarna() << endl;
    }
    cout << "kartu gabungan p4" << endl;
    for(int i = 0; i<pc4.size(); i++){
        cout << pc4[i].getNum() << " " << pc4[i].getWarna() << endl;
    }

    tes1 = c.concatCombi(pc1);
    tes2 = c.concatCombi(pc2);
    tes3 = c.concatCombi(pc3);
    tes4 = c.concatCombi(pc4);

    int ctr = 0;
    vector<double> d1 = tes1.second;
    vector<double> d2 = tes2.second;
    vector<double> d3 = tes3.second;
    vector<double> d4 = tes4.second;
    vector<Player> player;

    double dd1 = d1[0];
    ctr++;
    player.push_back(p1);
    double dd2 = d2[0];
    if(dd2 == dd1){
        ctr++;
        player.push_back(p2);
    }
    double dd3 = d3[0];
    if(dd3 == dd1){
        ctr++;
        player.push_back(p3);
    }
    double dd4 = d4[0];
    if(dd4 == dd1){
        ctr++;
        player.push_back(p4);
    }

    if(ctr == 4){
        cout << "wah sama" << endl;
    }

    cout << dd1 << endl;

    // cout << "Highest on table" << endl;
    // cout << c.highestOnTable(pc1) << endl;
    // cout << c.highestOnTable(pc2) << endl;
    // cout << c.highestOnTable(pc3) << endl;
    // cout << c.highestOnTable(pc4) << endl;
    // cout << "INI GABUNGAN CARD" << endl;
    // for(int i = 0; i<gabungan.size(); i++){
    //     cout << gabungan[i].getNum()  << " " << gabungan[i].getWarna() << endl;
    // }
    cout << "=====================" << endl;

    res = resss.first;
    vector<double> val = resss.second;
    // cout << "bug" << endl;
    // cout << s << endl;
    // for(int i=0; i<c.threeOfAKind(pc1).size(); i++){
    //     cout << "bug" << endl;
    //     rese = c.threeOfAKind(pc1)[i];
    //     cout << "bug2" << endl;
    //     res.push_back(rese);
    // }
    // cout << res.size() << endl;
    // for(int i = 0; i <res.size(); i++){
    //     for(int j=0; j<res[i].size(); j++){
    //         cout << res[i][j].getNum() << res[i][j].getWarna() << " ";
    //     }
    //     cout << "           " << val[i] << endl;
    //     cout << endl;
    // }

    Player ppp = c.evaluateAgain(player, cards, dd1);

    cout << "Yang menang player : " << ppp.getId() << endl;

}

