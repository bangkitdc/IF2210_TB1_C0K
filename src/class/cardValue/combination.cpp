#include "combination.hpp"

double Combination::Pair()
{
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 2){
                return card[i].getValue() + card[j].getValue() + 1.39; // 1.39 : max value of single / high card
            }
        }
        ctr = 0;
    }

    return 0;
}

double Combination::TwoPair()
{
    float value = 0;

    int ctr = 0;
    int valid = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 2){
                valid++;
                value += card[i].getValue() + card[j].getValue();
                break;
            }
        }
        ctr = 0;
    }
    if(valid == 2){
        return value + 2.75; // 2.75 : max value of pair
    }

    return 0;
}

double Combination::ThreeOfAKind()
{
    double temp = 0.0;
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
            if(card[i].getNum() == card[j].getNum()){
                temp += card[j].getValue();
                ctr++;
            }
            if(ctr == 3){ 
                return temp + 5.18; // 5.18 : max value of two pair
            }
        }
        ctr = 0;
        temp = 0.0;
    }

    return 0;
}

double Combination::Straight()
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

    double value = card[0].getValue();
    for(int i = 1; i < card.size(); i++){
        if(card[0].getNum() == card[i].getNum() - i){
            value += card[i].getValue();
            ctr++;
        }
    }
    
    if(ctr == 5){
        return value + 4.08; // 4.08 : max value of three of a kind
    }

    return 0;
}

double Combination::Flush()
{
    double value = card[0].getValue();
    int ctr = 0;
    for(int i = 1; i < card.size(); i++){
        if(card[0].getWarna() == card[i].getWarna()){
            ctr++;
            value += card[i].getValue();
        }
        if(ctr == 5){
            return value + 5.92; // 5.92 : max value of straight
        }
    }

    return 0;
}

double Combination::FullHouse()
{
    double value = 0.0;
    double temp = 0.0;
    int ctr = 0;
    int ctrFH = 0;
    for(int i = 0; i < card.size(); i++){
        for(int j = 0; j < card.size(); j++){
            if(card[i].getNum() == card[j].getNum()){
                temp += card[j].getValue(); 
                ctr++;
            }
            if(ctr == 2){
                value += temp;
                ctrFH += ctr;
            }
            if(ctr == 3){
                value += temp;
                ctrFH += ctr;
            }
        }
        temp = 0.0;
        ctr = 0;
    }

    if(ctrFH == 5){
        return value + 5.85; // 5.85 : max value of flush
    }

    return 0;
}

double Combination::FourOfAKind()
{
    double temp = 0.0;
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
            if(card[i].getNum() == card[j].getNum()){
                temp += card[j].getValue();
                ctr++;
            }
            if(ctr == 4){ 
                return temp + 6.63; // 6.63 : max value of full house
            }
        }
        ctr = 0;
        temp = 0.0;
    }

    return 0;
}

double Combination::StraightFlush()
{
    double value = card[0].getValue();
    int ctr = 0;
    for(int i = 1; i < card.size(); i++){
        if(card[0].getNum() == card[i].getNum() - 1 
        && card[0].getWarna() == card[i].getWarna()){
            value += card[i].getValue();
            ctr++;
        }
        if(ctr == 5){
            return value + 5.38; // 5.38 : max value of four of a kind
        }
    }

    return 0;
}