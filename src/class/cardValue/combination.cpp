#include "combination.hpp"
// #include <bits/stdc++.h>
// #include "testcombo.cpp"
#include <string>

Combination::Combination()
{
    
}

Combination::~Combination()
{

}

void Combination::sortCard(vector<Card> &card)
{
    //sorting
    Card tempsort;
    for(int i=0; i<card.size(); i++){
        for(int j=0; j<card.size(); j++){
            if(card[i].getNum() < card[j].getNum()){
                tempsort = card[i];
                card[i] = card[j];
                card[j] = tempsort;
            }
        }
    }
}

bool Combination::hasPair(vector<Card> card)
{
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 2){
                return 1;
            }
        }
        ctr = 0;
    }

    return 0;
}

bool Combination::hasTwoPair(vector<Card> card)
{
    int ctr = 0;
    int temp = 0;
    bool same;
    for (int i = 0; i < card.size(); i++){
        for (int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum() && card[i].getNum() != temp){
                temp = card[i].getNum();
                ctr++;
            }
        }
    }

    if(ctr >= 2){
        return 1;
    }

    return 0;
}

bool Combination::hasThreeOfAKind(vector<Card> card)
{
    vector<Card> res;
    Card tempsort;
    int temp, index;
    int ctr = 0;

    sortCard(card);

    for (int i=0; i<card.size(); i++){
        if (i == 0){
            ctr++;
            //ambil nilai kartu pertama
            temp = card[i].getNum();
        } else{
            //kalau sama, ctr nya +1
            if (card[i].getNum() == temp){
                ctr++;
            } else{
                // kalau beda, ctr di set ke 0 dan temp = card[i]
                ctr = 1;
                temp = card[i].getNum();
            }
        }

        if (ctr == 3){
            return 1;
        }
    }
    return 0;
}

bool Combination::hasStraight(vector<Card> card)
{
    Card tempsort;
    int temp;
    int ctr = 0;

    sortCard(card);

    for (int i=0; i<card.size()-4; i++){
        temp = card[i].getNum();
        ctr = 1;
        for(int j=0; j<card.size(); j++){
            if(card[j].getNum() == temp+ctr){
                ctr++;
            }
            if (ctr == 5){
                return 1;
            }
        }
    }

    return 0;
}

bool Combination::hasFlush(vector<Card> card)
{
    int ctr = 0;
    for(int i = 1; i < card.size(); i++){
        if(card[0].getWarna() == card[i].getWarna()){
            ctr++;
        }
        if(ctr == 4){
            return 1;
        }
    }

    return 0;
}

bool Combination::hasFullHouse(vector<Card> card){
    int temp1,temp2,temp3;
    vector<Card> c1, c2, c3;

    if (hasThreeOfAKind(card) && hasTwoPair(card)){
        return 1;
    }
    return 0;
}

bool Combination::hasFourOfAKind(vector<Card> card)
{
    vector<Card> temp;
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
                // cout << ctr << "ctr" << endl;
            }
        }
        if(ctr == 3){
            return 1;
        }
        else{
            ctr = 0;
        }
    }
    return 0;
}


bool Combination::hasStraightFlush(vector<Card> card)
{
    int ctr = 0, temp;
    bool found = false;
    Card tempsort;
    string tempcolour;

    sortCard(card);

    for (int i=0; i<card.size()-4; i++){
        temp = card[i].getNum();
        tempcolour = card[i].getWarna();
        ctr = 1;
        for(int j=0; j<card.size(); j++){
            if(card[j].getNum() == temp+ctr && card[j].getWarna() == tempcolour){
                ctr++;
            }
            if (ctr == 5){
                return 1;
            }
        }
    }
    return 0;
}

vector<Card> Combination::pair(vector<Card> card)
{
    int ctr = 0;
    vector<Card> temp;
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum() && temp.size() != 2){
                temp.push_back(card[i]);
                temp.push_back(card[j]);
                ctr ++;
            }
            if(ctr > 0 && card[i].getNum() > temp[0].getNum()){
                temp.clear();
                ctr = 0;
                temp.push_back(card[i]);
                temp.push_back(card[j]);

            }
        }
    }

    return temp;
}

vector<Card> Combination::twoPair(vector<Card> card)
{
    int ctr = 0;
    Card tempsort;
    vector<Card> res;
    int temp = 0;
    int w1, w2;
    bool same = false;

    sortCard(card);
    sortingWarna(card);

    for(int i = 0; i < card.size()-1; i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum() && card[i].getNum() != temp){
                temp = card[i].getNum();
                res.push_back(card[i]);
                res.push_back(card[j]);
                ctr++;
            }
            if(ctr == 2){
                break;
            }
        }
        if(ctr == 2){
            break;
        }
    }
    return res;
}

vector<Card> Combination::fourOfAKind(vector<Card> card)
{
    int ctr = 0;
    vector<Card> temp;
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                temp.push_back(card[j]);
                if(card[i].getNum() > temp[0].getNum()){
                    temp.clear();
                    temp.push_back(card[j]);
                    ctr=0;
                }
                ctr++;
            }
        }
        if(temp.size() == 3){
            temp.push_back(card[i]);
            break;
        }
        else{
            ctr = 0;
        }
    }
    return temp;
}

vector<Card> Combination::flush(vector<Card> card)
{
    vector<Card> temp;

    sortCard(card);

    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getWarna() == card[j].getWarna()){
                temp.push_back(card[j]);
            }
        }
        if(temp.size() == 4){
            temp.push_back(card[i]);
            break;
        }
        else{
            temp.clear();
        }
    }
    return temp;
}

vector<Card> Combination::threeOfAKind(vector<Card> cards){
    vector<Card> res;
    Card tempsort;
    int temp, index;
    int ctr = 0;

    sortCard(cardss);

    for (int i=0; i<cards.size(); i++){
        if (i == 0){
            ctr++;
            //ambil nilai kartu pertama
            temp = cards[i].getNum();
        } else{
            //kalau sama, ctr nya +1
            if (cards[i].getNum() == temp){
                ctr++;
            } else{
                // kalau beda, ctr di set ke 0 dan temp = cards[i]
                ctr = 1;
                temp = cards[i].getNum();
            }
        }

        if (ctr == 3){
            //dipindah ke index barangkali ada yang lebih tinggi
            index = i;
            ctr = 0;
        }
    }

    res.push_back(cards[index]);
    res.push_back(cards[index-1]);
    res.push_back(cards[index-2]);

    return res;
}

vector<Card> Combination::straight(vector<Card> cards){
    vector<Card> res;
    Card tempsort, tempcard;
    string tempcolour;
    int temp, index, w1, w2;
    int ctr = 0;

    sortCard(cardss);
    sortingWarna(cards);

    for (int i=0; i<cards.size()-4; i++){
        temp = cards[i].getNum();
        ctr = 1;
        for(int j=0; j<cards.size(); j++){
            if(cards[j].getNum() == temp+ctr){
                ctr++;
            }
            if (ctr == 5){
                index = i;
            }
        }
    }

    for (int i=0; i<5; i++){
        temp = cards[index].getNum() + i;
        for (int j=0; j<cards.size(); j++){
            if (cards[j].getNum() == temp){
                tempcolour = cards[j].getWarna();
                break;
            }
        }
        tempcard.setNum(temp);
        tempcard.setWarna(tempcolour);
        res.push_back(tempcard);
    }

    return res;
}

vector<Card> Combination::straightFlush(vector<Card> cards){
    vector<Card> res;
    Card tempsort, tempcard;
    bool found = false;
    string tempcolour;
    int temp, index, w1, w2;
    int ctr = 0;

    sortCard(cardss);
    sortingWarna(cards);


    for (int i=0; i<cards.size()-4; i++){
        temp = cards[i].getNum();
        tempcolour = cards[i].getWarna();
        ctr = 1;
        for(int j=0; j<cards.size(); j++){
            if(cards[j].getNum() == temp+ctr && cards[j].getWarna() == tempcolour){
                ctr++;
            }
            if (ctr == 5){
                index = i;
            }
        }
    }

    for (int i=0; i<5; i++){
        temp = cards[index].getNum() + i;
        tempcolour = cards[index].getWarna();
        tempcard.setNum(temp);
        tempcard.setWarna(tempcolour);
        res.push_back(tempcard);
    }

    return res;
}

vector<Card> Combination::fullHouse(vector<Card> cards){
    vector<Card> res, three, two;
    string tempcolour;
    int temp, index, temp3, temp2;
    int ctr = 0;

    if(hasThreeOfAKind(cards) && hasTwoPair(cards)){
        three = threeOfAKind(cards);
        two = twoPair(cards);
        temp3 = three[0].getNum();
        temp2 = two[0].getNum();
        cout << "temp2 = " << temp2 << endl;
        cout << "temp3 = " << temp3 << endl;
        // for (int i=0; i<three.size(); i++){
        //     cout << three[i].getNum() << endl;
        // }
        // for (int i=0; i<two.size(); i++){
        //     cout << two[i].getNum() << endl;
        // }
        for (int i=0; i<three.size(); i++){
            res.push_back(three[i]);
        }
        if(temp2 != temp3){
            for (int j=0; j<two.size()-2; j++){
                res.push_back(two[j]);
            }
        } else{
            temp2 = two[2].getNum();
            for (int j=2; j<two.size(); j++){
                res.push_back(two[j]);
            }
        }
    }

    return res;
}

int Combination::color2Int(Card card)
{
    if(card.getWarna() == "hijau"){
        return 0;
    }
    else if(card.getWarna() == "biru"){
        return 1;
    }
    else if(card.getWarna() == "kuning"){
        return 2;
    }
    else {
        return 3;
    }
}

void Combination::sortingWarna(vector<Card> &card){
    int w1, w2;
    Card tempsort;
    //sorting warna
    for(int i=0; i<card.size(); i++){
        for(int j = i+1; j<card.size();j++){
            if (card[i].getNum() == card[j].getNum()){
                int warna1 = color2Int(card[i]);
                int warna2 = color2Int(card[j]);
                if(w2 > w1){
                    tempsort = card[i];
                    card[i] = card[j];
                    card[j] = tempsort;
                }

            }
        }
    }
}

double Combination::highVal(int angka, int warna) {
    // High Card
    double konstan = 0.1 * angka;

    return konstan + warna * 0.03;
    // MAX : 1.39
}

double Combination::pairVal(int angka, int warna1, int warna2) {
    // Pair
    double konstan = (angka * 10.1) - 13;
    // Rumus dari 10.1 - 13 + -2.9 + 3(kemungkinan terkecil) = 1.49 

    return 1.39 + konstan + (pow(2, warna1) + pow(2, warna2));
    // MAX : 131.69
}

double Combination::twoPairVal(int angka1, int angka2, int warna1_a, int warna1_b, int warna2_a, int warna2_b) {
    // TwoPair

    // Pair kecil hanya punya porsi 0.3
	if (angka1 > angka2) {
		return 131.69 + pairVal(angka1, warna1_a, warna1_b) + pairVal(angka2, warna2_a, warna2_b) * 0.3;
	} else {
		return 131.69 + pairVal(angka2, warna2_a, warna2_b) + pairVal(angka1, warna1_a, warna1_b) * 0.3;
	}
	// MAX : 299.857
}

double Combination::threesVal(int angka, int warna1, int warna2, int warna3) {
    // Threes
    double konstan = (angka * 10.1) - 15;
    // Rumus mirip pairVal

    return 299.857 + (konstan) + (pow(2, warna1) + pow(2, warna2) + pow(2, warna3));
    // MAX : 430.157
}

double Combination::straightVal(int angkaTerkecil, int warna1, int warna2, int warna3, int warna4, int warna5) {
    // Straight
    double konstan = angkaTerkecil * 1024;

    // Menggunakan representasi 10 bit
    int subset = 0;
    subset = subset | (warna5 << 8);
    subset = subset | (warna4 << 6);
    subset = subset | (warna3 << 4);
    subset = subset | (warna2 << 2);
    subset = subset | warna1;

    return 430.157 + konstan + subset;
    // MAX : 10669.2
}

double Combination::flushVal(int angka1, int angka2, int angka3, int angka4, int angka5, int warna) {
    // Flush
    double konstan = warna * 0.2;
    // Differs warna dengan 1 angka di belakang koma

    return 10669.2 + konstan + pow(2, angka1) + pow(2, angka2) + pow(2, angka3) + pow(2, angka4) + pow(2, angka5);
    // MAX : 50861.2
}

double Combination::fullHouseVal(int angka1, int angka2, int warna1_1, int warna1_2, int warna1_3, int warna2_1, int warna2_2) {
    // FullHouse
    // angka1 = 3 biji
    // angka2 = 2 biji

    double konstan1 = pow(2, warna1_1) + pow(2, warna1_2) + pow(2, warna1_3);
    double konstan2 = pow(2, warna2_1) + pow(2, warna2_2);

    // min 5 x 32 = 160
    // max = 158 (dari kombinasi konstan1 dan konstan2)
    // agar tidak overlap angka dikali agar mendekati 158, yakni 160

    return 26285.8 + (pow(2, angka1) + pow(2, angka2)) * pow(2, 5) + (pow(konstan1, 2) + konstan2 - 50);
    // MAX : 419660
}

double Combination::foursVal(int angka) {
    // Fours

    return 419660 + angka;
    // MAX : 419673
}

double Combination::straightFlushVal(int angka1, int angka2, int angka3, int angka4, int angka5, int warna) {
    // StraightFlush
    double konstan = warna;

    return 419673 + konstan + angka1 + angka2 + angka3 + angka4 + angka5;
    // MAX : 419731
}

double Combination::priorityCard(vector<Card> cards){
    vector <Card> res;
    if(hasStraightFlush(cards)){
        cout << "straight flush" << endl;
        res = straightFlush(cards);
        int angka1 = res[0].getNum(), angka2 = res[1].getNum(), angka3 = res[2].getNum(), angka4 = res[3].getNum(), angka5 = res[4].getNum();
        int warna = color2Int(res[0]);
        return straightFlushVal(angka1, angka2, angka3, angka4, angka5, warna);
    } else if (hasFourOfAKind(cards)){
        cout << "4ofakind" << endl;
        res = fourOfAKind(cards);
        int angka = res[0].getNum();
        return foursVal(angka);
    } else if (hasFullHouse(cards)){
        //angka1 threes, angka2 twopairnya
        cout << "full house" << endl;
        res = fullHouse(cards);
        int angka1 = res[0].getNum(), angka2 = res[3].getNum();
        int warna1_1 = color2Int(res[0]), warna1_2 = color2Int(res[1]), warna1_3 = color2Int(res[2]), warna2_1 = color2Int(res[3]), warna2_2 = color2Int(res[4]);
        return fullHouseVal(angka1, angka2, warna1_1, warna1_2, warna1_3, warna2_1, warna2_2);
    } else if (hasFlush(cards)){
        cout << "flush" << endl;
        res = flush(cards);
        int angka1 = res[0].getNum(), angka2 = res[1].getNum(), angka3 = res[2].getNum(), angka4 = res[3].getNum(), angka5 = res[4].getNum();
        int warna = color2Int(res[0]);
        return flushVal(angka1, angka2, angka3, angka4, angka5, warna);
    } else if(hasStraight(cards)){
        cout << "straight" << endl;
        res = straight(cards);
        int angka1 = res[0].getNum();
        int warna1 = color2Int(res[0]), warna2 = color2Int(res[1]), warna3 = color2Int(res[2]), warna4 = color2Int(res[3]), warna5 = color2Int(res[4]);
        return straightVal(angka1, warna1, warna2, warna3, warna4, warna5);
    } else if(hasThreeOfAKind(cards)){
        cout << "3ofakind" << endl;
        res = threeOfAKind(cards);
        int angka = res[0].getNum();
        int warna1 = color2Int(res[0]), warna2 = color2Int(res[1]), warna3 = color2Int(res[3]);
        return threesVal(angka, warna1, warna2, warna3);
    } else if(hasTwoPair(cards)){
        cout << "2pair" << endl;
        res = twoPair(cards);
        int angkaA = res[0].getNum();
        int warna1A = color2Int(res[0]), warna2A = color2Int(res[1]);
        int angkaB = res[2].getNum();
        int warna1B = color2Int(res[2]), warna2B = color2Int(res[3]);
        return twoPairVal(angkaA, warna1A, warna2A, angkaB, warna1B, warna2B);
    } else if(hasPair(cards)){
        cout << "pair" << endl;
        res = pair(cards);
        int angka = res[0].getNum();
        int warna1 = color2Int(res[0]), warna2 = color2Int(res[1]);
        return pairVal(angka, warna1, warna2);
    } else {
        cout << "highcard" << endl;
        // harusnya sorting dulu
        int angka = cards[0].getNum();
        int warna = color2Int(cards[0]);
        return highVal(angka, warna);
    }
}