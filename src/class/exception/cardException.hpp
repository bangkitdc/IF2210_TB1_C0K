#ifndef _CARDEXCEPTION_HPP_
#define _CARDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class playerFullException : public BaseException{
    public : 
    playerFullException(){}
    const string what() const {
        return "Player sudah memiliki kartu" ;
    }
};

class playerKosongException : public BaseException{
    public :
    playerKosongException(){}
    const string what() const {
        return "Player tidak memiliki kartu" ;
    }
};

class tableKosongException : public BaseException {
    public :
    tableKosongException(){} 
    const string what() const{
        return "Tidak ada TableCard" ;
    }
};

class tablePenuhException : public BaseException {
    public : 
    tablePenuhException(){}
    const string what() const{
        return "Table Card sudah ada 5" ;
    }
};
#endif