#include "combination.hpp"
#include <string>

Combination::Combination()
{
    
}

Combination::~Combination()
{

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
    int valid = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 2){
                valid++;
                break;
            }
        }
        ctr = 0;
    }
    if(valid > 2){
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

    //sorting
    for(int i=0; i<card.size(); i++){
        for(int j=1; j<card.size(); j++){
            if(card[i].getNum() < card[j].getNum()){
                tempsort = card[i];
                card[i] = card[j];
                card[j] = tempsort;
            }
        }
    }

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

    //sorting
    for(int i=0; i<card.size(); i++){
        for(int j=0; j<card.size(); j++){
            if(card[i].getNum() < card[j].getNum()){
                tempsort = card[i];
                card[i] = card[j];
                card[j] = tempsort;
            }
        }
    }

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

    if (hasThreeOfAKind(card)){
        if (hasPair(card)){
            c3 = threeOfAKind(card);
            c2 = pair(card);
            temp3 = c3[0].getNum();
            cout << temp3 << endl;
            temp2 = c2[0].getNum();
            cout << temp2 << endl;
            if (temp2 == temp3){
                cout << "debug 1" << endl;
                if (hasTwoPair(card)){
                    cout << "debug 2" << endl;
                    c1 = twoPair(card);
                    temp1 = c1[0].getNum();
                    cout << temp1 << endl;
                    if(temp1 != temp3){
                        return 1;
                    }
                } else {
                    return 0;
                }
            } else {
                return 1;
            }
        } 
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

    //sorting
    for(int i=0; i<card.size(); i++){
        for(int j=0; j<card.size(); j++){
            if(card[i].getNum() < card[j].getNum()){
                tempsort = card[i];
                card[i] = card[j];
                card[j] = tempsort;
            }
        }
    }

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
    vector<Card> temp;
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                if(ctr > 1){
                    if(temp[0].getNum() < card[i].getNum()){
                        if(temp[2].getNum() < temp[0].getNum()){
                            temp[2] = temp[0];
                            temp[3] = temp[1];
                        }
                        temp[0] = card[i];
                        temp[1] = card[i];
                        break;
                    }
                    break;
                }
                temp.push_back(card[i]);
                temp.push_back(card[j]);
                ctr++;
                break;
            }
        }
    }
    return temp;
}

vector<Card> Combination::fourOfAKind(vector<Card> card)
{
    int ctr = 0;
    vector<Card> temp;
    for(int i = 0; i < card.size(); i++){
        for(int j = i+1; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                temp.push_back(card[j]);
                cout << card[j].getNum() << " <-" << endl;
                if(card[i].getNum() > temp[0].getNum()){
                    cout << card[j].getNum() << " ->" << endl;
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

double Combination::getValue() const
{
    return 0.0;
}

vector<Card> Combination::threeOfAKind(vector<Card> cards){
    vector<Card> res;
    Card tempsort;
    int temp, index;
    int ctr = 0;

    //sorting
    for(int i=0; i<cards.size(); i++){
        for(int j=1; j<cards.size(); j++){
            if(cards[i].getNum() < cards[j].getNum()){
                tempsort = cards[i];
                cards[i] = cards[j];
                cards[j] = tempsort;
            }
        }
    }

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

    //sorting
    for(int i=0; i<cards.size(); i++){
        for(int j=0; j<cards.size(); j++){
            if(cards[i].getNum() < cards[j].getNum()){
                tempsort = cards[i];
                cards[i] = cards[j];
                cards[j] = tempsort;
            }
        }
    }

    //sorting warna
    for(int i=0; i<cards.size(); i++){
        for(int j = i+1; j<cards.size();j++){
            if (cards[i].getNum() == cards[j].getNum()){
                string warna1 = cards[i].getWarna();
                string warna2 = cards[j].getWarna();
                if (warna1 == "hijau"){
                    w1 = 1;
                } else if (warna1 == "biru"){
                    w1 = 2;
                } else if (warna1 == "kuning"){
                    w1 = 3;
                } else if (warna1 == "merah"){
                    w1 = 4;
                }

                if (warna2 == "hijau"){
                    w2 = 1;
                } else if (warna2 == "biru"){
                    w2 = 2;
                } else if (warna2 == "kuning"){
                    w2 = 3;
                } else if (warna2 == "merah"){
                    w2 = 4;
                }

                if(w2 > w1){
                    tempsort = cards[i];
                    cards[i] = cards[j];
                    cards[j] = tempsort;
                }

            }
        }
    }

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

    //sorting
    for(int i=0; i<cards.size(); i++){
        for(int j=0; j<cards.size(); j++){
            if(cards[i].getNum() < cards[j].getNum()){
                tempsort = cards[i];
                cards[i] = cards[j];
                cards[j] = tempsort;
            }
        }
    }

    //sorting warna
    for(int i=0; i<cards.size(); i++){
        for(int j = i+1; j<cards.size();j++){
            if (cards[i].getNum() == cards[j].getNum()){
                string warna1 = cards[i].getWarna();
                string warna2 = cards[j].getWarna();
                if (warna1 == "hijau"){
                    w1 = 1;
                } else if (warna1 == "biru"){
                    w1 = 2;
                } else if (warna1 == "kuning"){
                    w1 = 3;
                } else if (warna1 == "merah"){
                    w1 = 4;
                }

                if (warna2 == "hijau"){
                    w2 = 1;
                } else if (warna2 == "biru"){
                    w2 = 2;
                } else if (warna2 == "kuning"){
                    w2 = 3;
                } else if (warna2 == "merah"){
                    w2 = 4;
                }

                if(w2 > w1){
                    tempsort = cards[i];
                    cards[i] = cards[j];
                    cards[j] = tempsort;
                }

            }
        }
    }

    for (int i=0; i<cards.size(); i++){
        cout << res[i].getNum() << " " << res[i].getWarna() << endl;
    }

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

    if(hasThreeOfAKind(cards)) {
        if (hasTwoPair(cards)){
            three = threeOfAKind(cards);
            two = twoPair(cards);
            temp3 = three[0].getNum();
            temp2 = two[0].getNum();
            if(temp2 == temp3){
                return res;
            } else{
                for(int i=0; i<3; i++){
                    res.push_back(three[i]);
                }
                for(int i=0; i<2; i++){
                    res.push_back(two[i]);
                }
                return res;
            }
        }
    }

    return res;
}
