#include "combination.hpp"

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
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 3){ 
                return 1;
            }
        }
        ctr = 0;
    }

    return 0;
}

bool Combination::hasStraight(vector<Card> card)
{
    
    int ctr = 0;
    // Sort
    for(int i = 0; i < card.size() ; i++){
        for(int j = 0; j < card.size(); j++){
            if(card[i].getNum() < card[j].getNum()){
                Card temp = card[j];
                card[j] = card[i];
                card[i] = temp;

            }
        }
    }

    for(int i = 1; i < card.size(); i++){
        if(card[0].getNum() == card[i].getNum() - i){
            ctr++;
        }
    }
    
    if(ctr == 5){
        return 1;
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

bool Combination::hasFullHouse(vector<Card> card)
{
    int ctr = 0;
    int ctrFH = 0;
    for(int i = 0; i < card.size(); i++){
        for(int j = 0; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 2){
                ctrFH += ctr;
            }
            if(ctr == 3){
                ctrFH += ctr;
            }
        }
        ctr = 0;
    }

    if(ctrFH == 5){
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
    int ctr = 0;
    for(int i = 1; i < card.size(); i++){
        if(card[0].getNum() == card[i].getNum() - 1 
        && card[0].getWarna() == card[i].getWarna()){
            ctr++;
        }
        if(ctr == 5){
            return 1;
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