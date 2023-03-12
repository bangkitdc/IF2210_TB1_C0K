#ifndef _CARDEXCEPTION_HPP_
#define _CARDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class PlayerFullException : public BaseException{
    public : 
    PlayerFullException(){}
    const string what() const noexcept {
        return "Player sudah memiliki kartu";
    }
};

class PlayerKosongException : public BaseException{
    public :
    PlayerKosongException(){}
    const string what() const noexcept {
        return "Player tidak memiliki kartu";
    }
};

class TableKosongException : public BaseException {
    public :
    TableKosongException(){} 
    const string what() const noexcept {
        return "Tidak ada TableCard";
    }
};

class TablePenuhException : public BaseException {
    public : 
    TablePenuhException(){}
    const string what() const noexcept {
        return "Table Card sudah ada 5";
    }
};
#endif