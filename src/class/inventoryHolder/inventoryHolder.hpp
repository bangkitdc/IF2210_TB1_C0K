#ifndef _INVENTORYHOLDER_HPP_
#define _INVENTORYHOLDER_HPP_

#include <iostream>
#include <string>
#include <vector>
#include "../cardValue/card.hpp"
using namespace std;

class InventoryHolder {
    protected:
        string type;
    public:
        InventoryHolder();
        InventoryHolder(string);
        virtual ~InventoryHolder();
        virtual vector<Card> getCards()=0;
        virtual void setCards(vector<Card>)=0;
};

#endif