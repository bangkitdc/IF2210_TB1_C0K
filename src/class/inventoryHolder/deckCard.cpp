#include "deckCard.hpp"
#include <random>
#include <algorithm>
#include <fstream>

DeckCard::DeckCard() : InventoryHolder ("DeckCard"){
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"merah"));
    }    
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"kuning"));
    }    
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"biru"));
    }    
    for(int i=1;i<=13;i++){
            cards.push_back(Card(i,"hijau"));
    }    
}

void DeckCard::readFromFile(string filename){
    fstream f;
    vector<Card> temp;
    f.open(filename+".txt",ios::in);    
    while(!f.eof()){
        string line;
        string cardColor;
        int cardNum;

        f>>line;
        switch (line[0])
        {
        case '1':
            if(line[1]=='0'){
                cardNum=10;
                break;
            }
            else if(line[1]=='1'){
                cardNum=11;
                break;
            }
            else if(line[1]=='2'){
                cardNum=12;
                break;
            }
            else if(line[1]=='3'){
                cardNum=13;
                break;
            }else{
                cardNum= 1;
                break;
            }
        case '2':
            cardNum = 2;
            break;
        case '3':
            cardNum = 3;
            break;
        case '4':
            cardNum = 4;
            break;
        case '5':
            cardNum = 5;
            break;
        case '6':
            cardNum = 6;
            break;
        case '7':
            cardNum = 7;
            break;
        case '8':
            cardNum = 8;
            break;
        case '9':
            cardNum = 9;
            break;
        default:
            throw "Input tidak valid";
            break;
        }
        
        switch (line[1])
        {
        case 'm':
            cardColor = "merah";
            break;
        case 'k':
            cardColor = "kuning";
            break;
        case 'b':
            cardColor = "biru";
            break;
        case 'h':
            cardColor = "hijau";
            break;
        default:
            switch (line[2])
            {
            case 'm':
                cardColor = "merah";
                break;
            case 'k':
                cardColor = "kuning";
                break;
            case 'b':
                cardColor = "biru";
                break;
            case 'h':
                cardColor = "hijau";
                break;
            default : 
                throw "Input tidak valid";
                break;
            
            break;
            }   
        }
        temp.push_back(Card(cardNum,cardColor));
    }
    f.close();
    if (temp.size()!= 52){
        throw "Input kartu kurang";
    }
    cards=temp;
}

DeckCard::~DeckCard(){}
        
void DeckCard::addCard(Card a){
    cards.push_back(a);
}

void DeckCard::displayDeckCard(){
    cout << "======================Deck Card======================" << endl;
    for (auto elem : DeckCard::cards) {
        elem.displayCard();
    }
}

void DeckCard::shuffleCard(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(cards.begin(), cards.end(), g);
}

vector<Card> DeckCard::getCards(){
    return cards;
}
DeckCard& DeckCard::operator-(const Card & a){
    for(int i=0;i<cards.size();i++){
        if (cards[i].getNum()==a.getNum() && cards[i].getWarna().compare(a.getWarna())==0 ){
            cards.erase(cards.begin()+i);
        }
    }
    return *this;
}

void DeckCard::deleteCard(Card a){
    for(int i=0;i<cards.size();i++){
        if (cards[i].getNum()==a.getNum() && cards[i].getWarna().compare(a.getWarna())==0 ){
            cards.erase(cards.begin()+i);
        }
    }
}

Card DeckCard::getCard(){
    // shuffleCard();
    if(cards.size()==0){
        throw DeckKosongException();
    }
    Card temp=cards[cards.size()-1];
    cards.pop_back();
    return temp;   
}

DeckCard& DeckCard::operator+(const Card &a){
    cards.push_back(a);
    return *this;
}

DeckCard& DeckCard::operator=(const DeckCard &a){
    this->cards=a.cards;
    return *this;
}
void DeckCard::setCards(vector<Card> a){
    cards=a;
}
