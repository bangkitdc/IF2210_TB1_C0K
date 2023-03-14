#include "card.hpp"

Card::Card() : Card(0, "-") { }

Card::Card(int num, string warna) {
    card.first=num;
    card.second = warna;
}

Card::Card(const Card & other) {
    card.first = other.card.first;
    card.second = other.card.second;
}

Card::~Card() { }

int Card::getNum() const {
    return card.first;
}

void Card::setNum(int num) {
    card.first = num;
}

string Card::getWarna() const {
    return card.second;
}

void Card::setWarna(string warna) {
    card.second = warna;
}
void Card::displayCard() {
    cout << this->getNum() << " (" << this->getWarna() << ")";
}

bool Card::isValidCard() const {
    return (card.first != 0) & (card.second != "-");
}

double Card::getValue() const {
    double temp = getNum() * 0.1;

    if (getWarna() == "hijau") {
        return temp;
    } else if (getWarna() == "biru") {
        return temp + 0.03;
    } else if (getWarna() == "kuning") {
        return temp + 0.06;
    } else if (getWarna() == "merah") {
        return temp + 0.09;
    } else {
        return 0;
    }
}

double Card::getValueGeneric() {
    double temp;
    string warna=card.second;
    if(warna.compare("merah")==0){
        temp=0.4;
    }
    else if(warna.compare("kuning")==0){
        temp=0.3;
    }
    else if(warna.compare("biru")==0){
        temp=0.2;
    }
    else if(warna.compare("hijau")==0){
        temp=0.1;
    }
    return card.first+temp; 
}