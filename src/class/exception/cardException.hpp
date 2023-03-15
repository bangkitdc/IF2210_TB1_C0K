#ifndef _CARDEXCEPTION_HPP_
#define _CARDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class PlayerFullException : public BaseException{
    public : 
    PlayerFullException(){}
    const string what() const noexcept {
        return "Player sudah memiliki kartu maksimal!";
    }
};

class PlayerKosongException : public BaseException{
    public :
    PlayerKosongException(){}
    const string what() const noexcept {
        return "Player tidak memiliki kartu!";
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
        return "Table Card sudah maksimal!";
    }
};

class DeckKosongException : public BaseException {
    public : 
    DeckKosongException(){}
    const string what() const noexcept {
        return "Deck Card sudah habis!";
    }
};

class DeckPenuhException : public BaseException {
    public : 
    DeckPenuhException(){}
    const string what() const noexcept {
        return "Deck sudah habis!";
    }
};
class fileInvalidException : public BaseException {
    int line;
    public : 
    fileInvalidException(int a){
        this->line=a;
    }
        const string what() const noexcept {
        return "Pastikan input file sesuai, contoh : \n<1-13>m\n<1-13>k\n<1-13>b\n<1-13>h\ncek line " + to_string(line) + "\n";
    }
};
class fileInvalidUkuranException : public BaseException {
    public : 
    fileInvalidUkuranException(){\
    }
        const string what() const noexcept {
        return "Jumlah kartu kurang atau melebihi 52!";
    }
};

class fileInvalidDuplicateException : public BaseException {
    int line;
    public : 
    fileInvalidDuplicateException(int a){
        this->line=a;
    }
        const string what() const noexcept {
        return "Ada kartu yang terduplikasi!\ncek line " + to_string(line) + "\n";
    }
};

#endif