#include "card.hpp"

Card::Card() : Card(0, "-") { }

Card::Card(int num, string warna) {
    this->num = num;
    this->warna = warna;
}

Card::Card(const Card & other) {
    this->num = other.num;
    this->warna = other.warna;
}

Card::~Card() { }

int Card::getNum() const {
    return this->num;
}

void Card::setNum(int num) {
    this->num = num;
}

string Card::getWarna() const {
    return this->warna;
}

void Card::setWarna(string warna) {
    this->warna = warna;
}
void Card::displayCard() {
    cout << this->getNum() << " (" << this->getWarna() << ")" << endl;
}

bool Card::isValidCard() const {
    return (this->num != 0) & (this->warna != "-");
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