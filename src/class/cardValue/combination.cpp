#include "combination.hpp"
// #include "testcombo.cpp"
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
    Card tempsort;
    vector<Card> res;
    int temp = 0;
    int w1, w2;
    bool same = false;

    //sorting
    for(int i=0; i<card.size(); i++){
        for(int j=0; j<card.size(); j++){
            if(card[i].getNum() > card[j].getNum()){
                tempsort = card[i];
                card[i] = card[j];
                card[j] = tempsort;
            }
        }
    }

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

vector<Card> Combination::threeOfAKind(vector<Card> cards){
    vector<Card> res;
    Card tempsort;
    int temp, index;
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

    sortingWarna(cards);

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
    else if(card.getWarna() == "merah"){
        return 3;
    }
}

void Combination::sortingWarna(vector<Card> card){
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