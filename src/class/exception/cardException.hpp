#ifndef _CARDEXCEPTION_HPP_
#define _CARDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class playerFullException : public BaseException{
    public : 
    playerFullException(){}
    void displayMessage() const {
        cout << "Player sudah memiliki kartu" << endl;
    }
};

class playerKosongException : public BaseException{
    public :
    playerKosongException(){}
    void displayMessage() const {
        cout << "Player tidak memiliki kartu" << endl;
    }
};

class tableKosongException : public BaseException {
    public :
    tableKosongException(){} 
    void displayMessage() const{
        cout << "Tidak ada TableCard" << endl;
    }
};

class tablePenuhException : public BaseException {
    public : 
    tablePenuhException(){}
    void displayMessage() const{
        cout << "Table Card sudah ada 5" << endl;
    }
};
#endif