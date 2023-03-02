#include "combination.hpp"

bool Combination::hasPair()
{
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
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

bool Combination::hasTwoPair()
{
    int ctr = 0;
    int valid = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
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
    if(valid == 2){
        return 1;
    }

    return 0;
}

bool Combination::hasThreeOfAKind()
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

bool Combination::hasStraight()
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

bool Combination::hasFlush()
{
    int ctr = 0;
    for(int i = 1; i < card.size(); i++){
        if(card[0].getWarna() == card[i].getWarna()){
            ctr++;
        }
        if(ctr == 5){
            return 1;
        }
    }

    return 0;
}

bool Combination::hasFullHouse()
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

bool Combination::hasFourOfAKind()
{
    int ctr = 0;
    for (int i = 0; i < card.size(); i++){
        for (int j = 0; j < card.size(); i++){
            if(card[i].getNum() == card[j].getNum()){
                ctr++;
            }
            if(ctr == 4){ 
                return 1;
            }
        }
        ctr = 0;
    }

    return 0;
}

bool Combination::hasStraightFlush()
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