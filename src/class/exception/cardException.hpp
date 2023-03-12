#ifndef _CARDEXCEPTION_HPP_
#define _CARDEXCEPTION_HPP_

#include "exception.hpp"
#include <string>
using namespace std;

class PlayerFullException : public BaseException{
    public : 
<<<<<<< HEAD
    playerFullException(){}
    const string what() const {
        return "Player sudah memiliki kartu" ;
=======
    PlayerFullException(){}
    const string what() const noexcept {
        return "Player sudah memiliki kartu";
>>>>>>> main
    }
};

class PlayerKosongException : public BaseException{
    public :
<<<<<<< HEAD
    playerKosongException(){}
    const string what() const {
        return "Player tidak memiliki kartu" ;
=======
    PlayerKosongException(){}
    const string what() const noexcept {
        return "Player tidak memiliki kartu";
>>>>>>> main
    }
};

class TableKosongException : public BaseException {
    public :
<<<<<<< HEAD
    tableKosongException(){} 
    const string what() const{
        return "Tidak ada TableCard" ;
=======
    TableKosongException(){} 
    const string what() const noexcept {
        return "Tidak ada TableCard";
>>>>>>> main
    }
};

class TablePenuhException : public BaseException {
    public : 
<<<<<<< HEAD
    tablePenuhException(){}
    const string what() const{
        return "Table Card sudah ada 5" ;
=======
    TablePenuhException(){}
    const string what() const noexcept {
        return "Table Card sudah ada 5";
>>>>>>> main
    }
};
#endif