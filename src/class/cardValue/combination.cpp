#include "combination.hpp"
// #include <bits/stdc++.h>
// #include "testcombo.cpp"
#include <string>
#include <utility>

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

void Combination::sortVector(vector<vector<Card>> &result, vector<double> &val){
    double tempdouble;
    vector<Card> tempvector;
    //sorting vector
    for (int i=0; i<result.size(); i++){
        for (int j=0; j<result.size(); j++){
            if(val[i] > val[j]){
                tempdouble = val[i];
                val[i] = val[j];
                val[j] = tempdouble;
                tempvector = result[i];
                result[i] = result[j];
                result[j] = tempvector;
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
    sortingWarna(card);
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
        for(int j = i+1; j < card.size() ; j++){
            if(card[i].getWarna() == card[j].getWarna()){
                ctr++;
            }
        }
        if(ctr == 4){
            return 1;
        }
        ctr = 0;
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

pair<vector<vector<Card>>, vector<double>> Combination::highCard(vector<Card> card){
    vector<Card> temp;
    vector<vector<Card>> result;
    vector<double> val;
    sortCard(card);
    for(int i=0; i<card.size(); i++){
        temp.push_back(card[i]);
        result.push_back(temp);
        temp.clear();
        int w = color2Int(temp[0]);
        double v = highCard(temp[0].getNum(), w);
        val.push_back(v);
        temp.clear();
    }

    sortVector(result, val);
    return make_pair(result, val);
}

vector<vector<Card> > Combination::pair(vector<Card> card)
{
    sortCard(card);
    vector<vector<Card> > allPairs;
    int ctr = 0;
    vector<Card> temp;
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                temp.push_back(card[i]);
                temp.push_back(card[j]);
                allPairs.push_back(temp);
                temp.clear();
            }
        }
    }

    return allPairs;
}

vector<vector<Card> > Combination::twoPair(vector<Card> card)
{
    int ctr = 0;
    Card tempsort;
    vector<Card> res;
    vector<vector<Card> > allTwoPairs;
    int temp = 0;
    int w1, w2;
    bool same = false;

    sortCard(card);

    for(int i = 0; i < card.size()-1; i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                res.push_back(card[i]);
                res.push_back(card[j]);
                for(int k = j+1; k < card.size(); k++){
                    for(int l = k+1; l < card.size(); l++){
                        if(card[k].getNum() == card[l].getNum()){
                            res.push_back(card[k]);
                            res.push_back(card[l]);
                        }
                        if(res.size() == 4){
                            allTwoPairs.push_back(res);
                            res.pop_back();
                            res.pop_back();
                            // res.clear();
                            break;
                        }
                    }
                }
                res.clear();
            }
        }
    }
    return allTwoPairs;
}

vector<vector<Card>> Combination::fourOfAKind(vector<Card> card)
{
    int ctr = 0;
    vector<vector<Card>> allFourOfAKinds;
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
            allFourOfAKinds.push_back(temp);
            break;
        }
        else{
            ctr = 0;
        }
    }
    return allFourOfAKinds;

    //cad salah
}

pair<vector<vector<Card>>, vector<double>> Combination::flush(vector<Card> card)
{
    vector<vector<Card>> allFlushes;
    vector<double> val;
    vector<Card> temp;

    sortCard(card);

    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            for(int k = j+1; k < card.size(); k++){
                for(int l = k+1; l < card.size(); l++){
                    for(int m = l+1; m < card.size(); m++){
                        if(card[i].getWarna() == card[j].getWarna() && 
                            card[i].getWarna() == card[k].getWarna() &&
                            card[i].getWarna() == card[l].getWarna() &&
                            card[i].getWarna() == card[m].getWarna()){
                            temp.push_back(card[i]);
                            temp.push_back(card[j]);
                            temp.push_back(card[k]);
                            temp.push_back(card[l]);
                            temp.push_back(card[m]);
                            allFlushes.push_back(temp);
                            int w = color2Int(temp[0]);
                            double v = flushVal(temp[0].getNum(), temp[1].getNum(), temp[2].getNum(), temp[3].getNum(), temp[4].getNum(), w);
                            val.push_back(val);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }
    return make_pair(allFlushes, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::threeOfAKind(vector<Card> cards){
    vector<vector<Card>> result;
    vector<double> val;
    vector<Card> temp;

    sortCard(cards);
    sortingWarna(cards);

    for(int i=0; i<cards.size()-2; i++){
        for(int j=i+1; j<cards.size()-1; j++){
            for(int k=j+1; k<cards.size(); k++){
                if (cards[i].getNum() == cards[j].getNum() && cards[j].getNum() == cards[k].getNum()){
                    temp.push_back(cards[i]);
                    temp.push_back(cards[j]);
                    temp.push_back(cards[k]);
                    result.push_back(temp);
                    int w1 = color2Int(temp[0]), w2 = color2Int(temp[1]), w3 = color2Int(temp[2]);
                    //dapetin nilai evaluatenya biar bisa di sorting
                    double v = threesVal(temp[0].getNum(), w1, w2, w3);
                    val.push_back(v);
                    temp.clear();
                }
            }
        }
    }
    sortVector(result, val);
    
    return make_pair(result, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::straight(vector<Card> cards){
    vector<vector<Card>> result;
    vector<Card> temp;
    vector<double> val;

    sortCard(cards);
    sortingWarna(cards);

    for(int i=0; i<cards.size()-4; i++){
        for(int j=i+1; j<cards.size()-3; j++){
            for(int k=j+1; k<cards.size()-2; k++){
                for(int l=k+1; l<cards.size()-1; l++){
                    for(int m=l+1; m<cards.size(); m++){
                        if(cards[i].getNum() == cards[j].getNum()-1
                        && cards[j].getNum() == cards[k].getNum()-1
                        && cards[k].getNum() == cards[l].getNum()-1
                        && cards[l].getNum() == cards[m].getNum()-1){
                            temp.push_back(cards[i]);
                            temp.push_back(cards[j]);
                            temp.push_back(cards[k]);
                            temp.push_back(cards[l]);
                            temp.push_back(cards[m]);
                            result.push_back(temp);
                            int w1 = color2Int(temp[0]), w2 = color2Int(temp[1]), w3 = color2Int(temp[2]), w4 = color2Int(temp[3]), w5 = color2Int(temp[4]);
                            double v = straightVal(temp[0].getNum(), w1, w2, w3, w4, w5);
                            val.push_back(v);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }
    sortVector(result, val);
    
    return make_pair(result, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::straightFlush(vector<Card> cards){
    vector<vector<Card>> result;
    vector<Card> temp;
    vector<double> val;

    sortCard(cards);
    sortingWarna(cards);


    for(int i=0; i<cards.size()-4; i++){
        for(int j=i+1; j<cards.size()-3; j++){
            for(int k=j+1; k<cards.size()-2; k++){
                for(int l=k+1; l<cards.size()-1; l++){
                    for(int m=l+1; m<cards.size(); m++){
                        if(cards[i].getNum() == cards[j].getNum()-1
                        && cards[j].getNum() == cards[k].getNum()-1
                        && cards[k].getNum() == cards[l].getNum()-1
                        && cards[l].getNum() == cards[m].getNum()-1
                        && cards[i].getWarna() == cards[j].getWarna()
                        && cards[j].getWarna() == cards[k].getWarna()
                        && cards[k].getWarna() == cards[l].getWarna()
                        && cards[l].getWarna() == cards[m].getWarna()){
                            temp.push_back(cards[i]);
                            temp.push_back(cards[j]);
                            temp.push_back(cards[k]);
                            temp.push_back(cards[l]);
                            temp.push_back(cards[m]);
                            result.push_back(temp);
                            int w = color2Int(temp[0]);
                            double v = straightFlushVal(temp[0].getNum(), temp[0].getNum(), temp[0].getNum(), temp[0].getNum(), temp[0].getNum(), w);
                            val.push_back(v);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }
    sortVector(result, val);

    return make_pair(result, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::fullHouse(vector<Card> cards){
    vector<vector<Card>> result, three, two;
    vector<Card> temp;
    vector<double> val;
    bool ada = false;

    sortCard(cards);
    sortingWarna(cards);

    for(int i=0; i<cards.size()-4; i++){
        for(int j=i+1; j<cards.size()-3; j++){
            for(int k=j+1; k<cards.size()-2; k++){
                for(int l=k+1; l<cards.size()-1; l++){
                    for(int m=l+1; m<cards.size(); m++){
                        if(cards[i].getNum() == cards[j].getNum()
                        && cards[j].getNum() == cards[k].getNum()
                        && cards[k].getNum() != cards[l].getNum()
                        && cards[l].getNum() == cards[m].getNum()){
                            temp.push_back(cards[i]);
                            temp.push_back(cards[j]);
                            temp.push_back(cards[k]);
                            temp.push_back(cards[l]);
                            temp.push_back(cards[m]);
                            result.push_back(temp);
                            int w1 = color2Int(temp[0]), w2 = color2Int(temp[1]), w3 = color2Int(temp[2]), w4 = color2Int(temp[3]), w5 = color2Int(temp[4]);
                            double v = fullHouseVal(temp[0].getNum(), temp[3].getNum(), w1, w2, w3, w4, w5);
                            val.push_back(v);
                            temp.clear();
                        } else if (cards[i].getNum() == cards[j].getNum()
                        && cards[j].getNum() != cards[k].getNum()
                        && cards[k].getNum() == cards[l].getNum()
                        && cards[l].getNum() == cards[m].getNum()){
                            temp.push_back(cards[k]);
                            temp.push_back(cards[l]);
                            temp.push_back(cards[m]);
                            temp.push_back(cards[i]);
                            temp.push_back(cards[j]);
                            result.push_back(temp);
                            int w4 = color2Int(temp[0]), w5 = color2Int(temp[1]), w1 = color2Int(temp[2]), w2 = color2Int(temp[3]), w3 = color2Int(temp[4]);
                            double v = fullHouseVal(temp[2].getNum(), temp[0].getNum(), w1, w2, w3, w4, w5);
                            val.push_back(v);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }

    sortVector(result, val);

    return make_pair(result, val);
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

    // maxGap = 156

    return 26285.8 + (pow(2, angka1) + angka1 * 156 + angka2 + angka2 * 5) * pow(2, 6) + (pow(konstan1, 2) + konstan2 - 50);
    // MAX : 412554
}

double Combination::foursVal(int angka) {
    // Fours

    return 412554 + angka;
    // MAX : 412567
}

double Combination::straightFlushVal(int angka1, int angka2, int angka3, int angka4, int angka5, int warna) {
    // StraightFlush
    double konstan = warna;

    return 412567 + konstan + angka1 + angka2 + angka3 + angka4 + angka5;
    // MAX : 412567
}

// double Combination::priorityCard(vector<Card> cards){
//     vector<vector<Card>> res;
//     if(hasStraightFlush(cards)){
//         cout << "straight flush" << endl;
//         res = straightFlush(cards);
//         int angka1 = res[0][0].getNum(), angka2 = res[0][1].getNum(), angka3 = res[0][2].getNum(), angka4 = res[0][3].getNum(), angka5 = res[0][4].getNum();
//         int warna = color2Int(res[0][0]);
//         return straightFlushVal(angka1, angka2, angka3, angka4, angka5, warna);
//     } else if (hasFourOfAKind(cards)){
//         cout << "4ofakind" << endl;
//         res = fourOfAKind(cards);
//         int angka = res[0][0].getNum();
//         return foursVal(angka);
//     } else if (hasFullHouse(cards)){
//         //angka1 threes, angka2 twopairnya
//         cout << "full house" << endl;
//         res = fullHouse(cards);
//         int angka1 = res[0][0].getNum(), angka2 = res[0][3].getNum();
//         int warna1_1 = color2Int(res[0][0]), warna1_2 = color2Int(res[0][1]), warna1_3 = color2Int(res[0][2]), warna2_1 = color2Int(res[0][3]), warna2_2 = color2Int(res[0][4]);
//         return fullHouseVal(angka1, angka2, warna1_1, warna1_2, warna1_3, warna2_1, warna2_2);
//     } else if (hasFlush(cards)){
//         cout << "flush" << endl;
//         res = flush(cards);
//         int angka1 = res[0][0].getNum(), angka2 = res[0][1].getNum(), angka3 = res[0][2].getNum(), angka4 = res[0][3].getNum(), angka5 = res[0][4].getNum();
//         int warna = color2Int(res[0][0]);
//         return flushVal(angka1, angka2, angka3, angka4, angka5, warna);
//     } else if(hasStraight(cards)){
//         cout << "straight" << endl;
//         res = straight(cards);
//         int angka1 = res[0][0].getNum();
//         int warna1 = color2Int(res[0][0]), warna2 = color2Int(res[0][1]), warna3 = color2Int(res[0][2]), warna4 = color2Int(res[0][3]), warna5 = color2Int(res[0][4]);
//         return straightVal(angka1, warna1, warna2, warna3, warna4, warna5);
//     } else if(hasThreeOfAKind(cards)){
//         cout << "3ofakind" << endl;
//         res = threeOfAKind(cards);
//         int angka = res[0][0].getNum();
//         int warna1 = color2Int(res[0][0]), warna2 = color2Int(res[0][1]), warna3 = color2Int(res[0][3]);
//         return threesVal(angka, warna1, warna2, warna3);
//     } else if(hasTwoPair(cards)){
//         cout << "2pair" << endl;
//         res = twoPair(cards);
//         int angkaA = res[0][0].getNum();
//         int warna1A = color2Int(res[0][0]), warna2A = color2Int(res[0][1]);
//         int angkaB = res[0][2].getNum();
//         int warna1B = color2Int(res[0][2]), warna2B = color2Int(res[0][3]);
//         return twoPairVal(angkaA, warna1A, warna2A, angkaB, warna1B, warna2B);
//     } else if(hasPair(cards)){
//         cout << "pair" << endl;
//         res = pair(cards);
//         int angka = res[0][0].getNum();
//         int warna1 = color2Int(res[0][0]), warna2 = color2Int(res[0][1]);
//         return pairVal(angka, warna1, warna2);
//     } else {
//         cout << "highcard" << endl;
//         sortCard(cards);
//         res.push_back(cards);
//         // sortCard(res);
//         int angka = res[0][0].getNum();
//         int warna = color2Int(res[0][0]);
//         return highVal(angka, warna);
//     }
// }

// int Combination::highestOnTable(vector<Card> card)
// {
//     if(hasStraightFlush(card)){
//         return 8;
//     } else if (hasFourOfAKind(card)){
//         return 7;
//     } else if (hasFullHouse(card)){
//         return 6;
//     } else if (hasFlush(card)){
//         return 5;
//     } else if (hasStraight(card)){
//         return 4;
//     } else if (hasThreeOfAKind(card)){
//         return 3;
//     } else if (hasTwoPair(card)){
//         return 2;
//     } else if (hasPair(card)){
//         return 1;
//     } else {
//         return 0;
//     }
// }


void Combination::eraseFirst(vector<vector<Card>> &card){
    card.erase(card.begin());
}



pair<vector<vector<Card>>, vector<double> Combination::concatCombi(vector<Card> card){
    vector<vector<Card>> result;
    vector<double> val;

    if(hasStraightFlush(card)){
        pair<vector<vector<Card>>, vector<double> sf = straightFlush(card);
        vector<vector<Card>> sfv = sf.first;
        vector<double> value = sf.second;
        result.insert(result.end(), sfv.begin(), sfv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasFourOfAKind(card)){
        pair<vector<vector<Card>>, vector<double> fok = fourOfAKind(card);
        vector<vector<Card>> fokv = fok.first;
        vector<double> value = fok.second;
        result.insert(result.end(), fokv.begin(), fokv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasFullHouse(card)){
        pair<vector<vector<Card>>, vector<double> fh = fullHouse(card);
        vector<vector<Card>> fhv = fh.first;
        vector<double> value = fh.second;
        result.insert(result.end(), fhv.begin(), fhv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasFlush(card)){
        pair<vector<vector<Card>>, vector<double> fl = flush(card);
        vector<vector<Card>> flv = fl.first;
        vector<double> value = fl.second;
        result.insert(result.end(), flv.begin(), flv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasStraight(card)){
        pair<vector<vector<Card>>, vector<double> s = straight(card);
        vector<vector<Card>> sv = s.first;
        vector<double> value = s.second;
        result.insert(result.end(), sv.begin(), sv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasThreeOfAKind(card)){
        pair<vector<vector<Card>>, vector<double> tok = threeOfAKind(card);
        vector<vector<Card>> tokv= tok.first;
        vector<double> value = tok.second;
        result.insert(result.end(), tokv.begin(), tokv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasTwoPair(card)){
        pair<vector<vector<Card>>, vector<double> tp = twoPair(card);
        vector<vector<Card>> tpv = tp.first;
        vector<double> value = tp.second;
        result.insert(result.end(), tpv.begin(), tpv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasPair(card)){
        pair<vector<vector<Card>>, vector<double> p = pair(card);
        vector<vector<Card>> pv = p.first;
        vector<double> value = p.second;
        result.insert(result.end(), pv.begin(), pv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    vector<vector<Card>> hc = highCard(card);
    vector<vector<Card>> hcv = hc.first;
    vector<double> value = hc.second;
    result.insert(result.end(), hc.begin(), hc.end());
    val.insert(val.end(), value.begin(), value.end());
    value.clear();

    // sortVector(card); ////

    return make_pair(result, val);
}

Player Combination::evaluate(deque<Player> players, vector<Card> t)
{
    vector<Player> playersTemp;
    vector<Card> temp;
    int ctr = 0;
    double max = 0.0;
    for(auto &p : players){
        vector<Card> tempGabungan;
        tempGabungan.insert(tempGabungan.end(), tableCard.begin(), tableCard.end());
        tempGabungan.insert(tempGabungan.end(), p.getCards().begin(), p.getCards().end());

        if(priorityCard(tempGabungan) > max){
            max = priorityCard(tempGabungan);
            while(playersTemp.size() != 0){
                playersTemp.pop_back();
            }
            playersTemp.push_back(p);
            vector<Card> temp = tempGabungan;
        } else if (max == priorityCard(tempGabungan)){
            playersTemp.push_back(p);
        }

        if(players.size() != 1){ // 
            playersTemp.push_back(evaluateAgain(playersTemp, temp, tempGabungan));
        }

        tempGabungan.clear();
    }

    return players[0];
}

// Player Combination::evaluateAgain(vector<Player> players, vector<Card> t, double m)
// {
//     Player res;
//     vector<Player> player;
//     while(player.size() != 1){
//         double max = 0.0;
//         for(auto &p : players){
//             vector<Card> tempGabungan;
//             tempGabungan.insert(tempGabungan.end(), t.begin(), t.end());
//             tempGabungan.insert(tempGabungan.end(), p.getCards().begin(), p.getCards().end());

//             pair<vector<vector<Card>>, vector<double> combi = concatCombi(tempGabungan);
//             vector<vector<Card>> com = combi.first;
//             vector<double> val = combi.second;
//             //kalo sebelumnya dia punya straight flush

//             for(int i=0; i< )
//             cout << priorityCard(com[0]) << endl;
//             if(val[0] == m){
//                 cout << "bug" << endl;
//                 eraseFirst(combi);
//             }

//             cout << priorityCard(com[0]) << endl;
//             if(priorityCard(com[0]) > max){
//                 cout << "bug2" << endl;
//                 max = priorityCard(com[0]);
//                 while(player.size() != 0){
//                     player.pop_back();
//                     cout << "bug3" << endl;
//                 }
//                 player.push_back(p);
//             } else if(priorityCard(com[0]) == max){
//                 player.push_back(p);
//                 cout << "bug4" << endl;
//             }
//             tempGabungan.clear();
//         }
//         m = max;
//     }

//     return player[0];
// }
