#include "combination.hpp"

Combination::Combination() { }

Combination::~Combination() { }

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

    int temp2 = card.size();

    for (int i=0; i< (temp2 -4); i++){
        temp = card[i].getNum();
        ctr = 1;
        for(int j=0; j< temp2; j++){
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
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size() ; j++){
            if(card[i].getWarna() == card[j].getWarna()){
                ctr++;
            }
        }
        if(ctr >= 4){
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

    int temp2 = card.size();

    for (int i=0; i < (temp2 - 4); i++){
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
        double v = highVal(temp[0].getNum(), w);
        val.push_back(v);
        temp.clear();
    }

    sortVector(result, val);
    return make_pair(result, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::Pair(vector<Card> card)
{
    sortCard(card);
    vector<vector<Card> > allPairs;
    vector<double> val;
    int ctr = 0;
    vector<Card> temp;
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                temp.push_back(card[i]);
                temp.push_back(card[j]);
                allPairs.push_back(temp);
                val.push_back(pairVal(temp[1].getNum(), color2Int(temp[1]), color2Int(temp[1])));
                temp.clear();
            }
        }
    }
    sortVector(allPairs, val);
    return make_pair(allPairs, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::twoPair(vector<Card> card)
{
    vector<Card> res;
    vector<vector<Card> > allTwoPairs;
    vector<double> val;

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
                            val.push_back(twoPairVal(res[0].getNum(), res[2].getNum(), color2Int(res[0]), color2Int(res[1]), color2Int(res[2]), color2Int(res[3])));
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

    sortVector(allTwoPairs, val);
    return make_pair(allTwoPairs, val);
}

pair<vector<vector<Card>>, vector<double>> Combination::fourOfAKind(vector<Card> card)
{
    vector<vector<Card>> allFourOfAKinds;
    vector<Card> temp;
    vector<double> val;

    for(int i =0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            for(int k = j+1; k < card.size(); k++){
                for(int l = k+1; l < card.size(); l++){
                    if(card[i].getNum() == card[j].getNum() &&
                        card[i].getNum() == card[k].getNum() &&
                        card[i].getNum() == card[l].getNum())
                    {
                        temp.push_back(card[i]);
                        temp.push_back(card[j]);
                        temp.push_back(card[k]);
                        temp.push_back(card[l]);
                        allFourOfAKinds.push_back(temp);
                        val.push_back(foursVal(temp[0].getNum()));
                        temp.clear();
                        break;
                    }
                }
            }
        }
    }
    sortVector(allFourOfAKinds, val);

    return make_pair(allFourOfAKinds, val);
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
                            val.push_back(v);
                            temp.clear();
                        }
                    }
                }
            }
        }
    }
    sortVector(allFlushes, val);
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

    return 50861.2 + (pow(2, angka1) + angka1 * 156 + angka2 + angka2 * 4) * pow(2, 6) + (pow(konstan1, 2) + konstan2 - 52);
    // MAX : 708937
}

double Combination::foursVal(int angka) {
    // Fours

    return 708937 + angka;
    // MAX : 708350
}

double Combination::straightFlushVal(int angka1, int angka2, int angka3, int angka4, int angka5, int warna) {
    // StraightFlush
    double konstan = warna;

    return 708350 + konstan + angka1 + angka2 + angka3 + angka4 + angka5;
    // MAX : 709008
}

void Combination::eraseFirst(vector<vector<Card>> &card){
    card.erase(card.begin());
}

pair<vector<vector<Card>>, vector<double>> Combination::concatCombi(vector<Card> card){
    vector<vector<Card>> result;
    vector<double> val;

    if(hasStraightFlush(card)){
        pair<vector<vector<Card>>, vector<double>> sf = straightFlush(card);
        vector<vector<Card>> sfv = sf.first;
        vector<double> value = sf.second;
        result.insert(result.end(), sfv.begin(), sfv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasFourOfAKind(card)){
        pair<vector<vector<Card>>, vector<double>> fok = fourOfAKind(card);
        vector<vector<Card>> fokv = fok.first;
        vector<double> value = fok.second;
        result.insert(result.end(), fokv.begin(), fokv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasFullHouse(card)){
        pair<vector<vector<Card>>, vector<double>> fh = fullHouse(card);
        vector<vector<Card>> fhv = fh.first;
        vector<double> value = fh.second;
        result.insert(result.end(), fhv.begin(), fhv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasFlush(card)){
        pair<vector<vector<Card>>, vector<double>> fl = flush(card);
        vector<vector<Card>> flv = fl.first;
        vector<double> value = fl.second;
        result.insert(result.end(), flv.begin(), flv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasStraight(card)){
        pair<vector<vector<Card>>, vector<double>> s = straight(card);
        vector<vector<Card>> sv = s.first;
        vector<double> value = s.second;
        result.insert(result.end(), sv.begin(), sv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasThreeOfAKind(card)){
        pair<vector<vector<Card>>, vector<double>> tok = threeOfAKind(card);
        vector<vector<Card>> tokv= tok.first;
        vector<double> value = tok.second;
        result.insert(result.end(), tokv.begin(), tokv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasTwoPair(card)){
        pair<vector<vector<Card>>, vector<double>> tp = twoPair(card);
        vector<vector<Card>> tpv = tp.first;
        vector<double> value = tp.second;
        result.insert(result.end(), tpv.begin(), tpv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    if(hasPair(card)){
        pair<vector<vector<Card>>, vector<double>> p = Pair(card);
        vector<vector<Card>> pv = p.first;
        vector<double> value = p.second;
        result.insert(result.end(), pv.begin(), pv.end());
        val.insert(val.end(), value.begin(), value.end());
        value.clear();
    }

    pair<vector<vector<Card>>, vector<double>> hc = highCard(card);
    vector<vector<Card>> hcv = hc.first;
    vector<double> value = hc.second;
    result.insert(result.end(), hcv.begin(), hcv.end());
    val.insert(val.end(), value.begin(), value.end());
    value.clear();

    sortVector(result, val);
    // for(int i=0; i<val.size(); i++){
    //     for(int j=0; j<val.size(); i++){
    //         if(val[i])
    //     }
    // }

    return make_pair(result, val);
}

Player Combination::evaluate(vector<Player> players, vector<Card> tableCard)
{
    vector<Player> playersTemp;
    vector<Card> temp;
    vector<Card> table = tableCard;
    double max = 0.0;
    vector<Card> tempGabungan;

    for(auto &p : players){

        vector<Card> kartuplayer = p.getCards();
        tempGabungan.insert(tempGabungan.end(), tableCard.begin(), tableCard.end());
        tempGabungan.insert(tempGabungan.end(), kartuplayer.begin(), kartuplayer.end());

        if(concatCombi(tempGabungan).second[0] > max){
            max = concatCombi(tempGabungan).second[0];
            while(playersTemp.size() != 0){
                playersTemp.pop_back();
            }
            playersTemp.push_back(p);
        } else if (max == concatCombi(tempGabungan).second[0]){
            playersTemp.push_back(p);
        }

        cout << "TEST: " << playersTemp.size() << endl;

        if(playersTemp.size() == 7){ 
            cout << "HALO EVALUATE AGAIN" << endl;
            return evaluateAgain(playersTemp, tableCard, max);
        }
        tempGabungan.clear();
    }
    this->value = max;
    return playersTemp[0];
}

Player Combination::evaluateAgain(vector<Player> players, vector<Card> t, double m)
{
    vector<Player> temp = players;
    int tempMax = m;
    vector<Player> player;
    while(player.size() != 1){
        player.clear();
        double max = 0.0;
        for(auto &p : temp){
            vector<Card> tempGabungan;
            vector<Card> kartuplayer = p.getCards();
            tempGabungan.insert(tempGabungan.end(), t.begin(), t.end());
            tempGabungan.insert(tempGabungan.end(), kartuplayer.begin(), kartuplayer.end());

            pair<vector<vector<Card>>, vector<double>> combi = concatCombi(tempGabungan);

            vector<vector<Card>> com = combi.first;
            vector<double> val = combi.second;

            if(val[0] == tempMax){
                com.erase(com.begin());
                val.erase(val.begin());
            }

            cout << val.size() << " hehe" << endl;

            if(val[0] > max){
                max = val[0];
                while(player.size() != 0){
                    player.pop_back();
                }
                player.push_back(p);
            } else if(val[0] == max){
                player.push_back(p);
            } else {
                temp.erase(temp.begin());
            }
            tempGabungan.clear();
        }
        tempMax = max;

        cout << "PLAYERS: " << endl;
        cout << player.size() << endl;
    }
    this->value = tempMax;

    return player[0];
}

double Combination::getValue() const {
    return this->value;
}

vector<Card> Combination::winnerCard(Player winner, vector<Card> tableCard, double winnerValue)
{
    ::pair<vector<vector<Card>>, vector<double>> tempWinnerCard;
    vector<Card>tempGabungan;
    vector<Card> kartuplayer = winner.getCards();
    vector<Card> res;

    tempGabungan.insert(tempGabungan.end(), tableCard.begin(), tableCard.end());
    tempGabungan.insert(tempGabungan.end(), kartuplayer.begin(), kartuplayer.end());

    if(winnerValue >= 0 && winnerValue <=1.39){ //high card
        tempWinnerCard = highCard(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 1.39 && winnerValue <= 131.69){ //pair
        tempWinnerCard = Pair(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 131.69 && winnerValue <= 299.857){ //two pair
        tempWinnerCard = twoPair(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 299.857 && winnerValue <= 430.157){ //threes
        tempWinnerCard = threeOfAKind(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 430.158 && winnerValue <= 10669.2){ //straight
        tempWinnerCard = straight(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 10669.2 && winnerValue <= 50861.2 ){ //flush
        tempWinnerCard = flush(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 50861.2 && winnerValue <= 708937 ){ //full house
        tempWinnerCard = fullHouse(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 708937 && winnerValue <= 708950 ){ //four of a kind
        tempWinnerCard = fourOfAKind(tempGabungan);
        res = tempWinnerCard.first[0];
    }
    if(winnerValue > 708950 && winnerValue <= 709008 ){ //straight flush
        tempWinnerCard = straightFlush(tempGabungan);
        res = tempWinnerCard.first[0];
    }

    return res;
}

string Combination::displayHandInfo(vector<Card> card)
{
    if(hasStraightFlush(card)){
        return "Straight Flush";
    }
    if(hasFourOfAKind(card)){
        return "For Of A Kind";
    }
    if(hasFullHouse(card)){
        return "Full House";
    }
    if(hasFlush(card)){
        return "Flush";
    }
    if(hasStraight(card)){
        return "Straight";
    }
    if(hasThreeOfAKind(card)){
        return "Three Of A Kind";
    }
    if(hasTwoPair(card)){
        return "Two Pair";
    }
    if(hasPair(card)){
        return "Pair";
    }
    return "High Card";
}