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
        InventoryHolder();                      /* Default Constructor */
        InventoryHolder(string);                /* Constructor */
        virtual ~InventoryHolder();             /* Virtual Destructor */
        virtual vector<Card> getCards()=0;      /* Virtual Getter */
        virtual void setCards(vector<Card>)=0;  /* Virtual Setter */
};

#endif