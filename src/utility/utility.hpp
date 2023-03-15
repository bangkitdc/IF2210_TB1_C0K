#include "../class/cardValue/card.hpp"
#include <vector>
#include <string>
#include <iomanip>

#define RESET   "\033[0m"
#define BLACK   "\033[1m\033[30m"
#define RED     "\033[1m\033[31m"
#define GREEN   "\033[1m\033[32m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[34m"
#define MAGENTA "\033[1m\033[35m"
#define CYAN    "\033[1m\033[36m"
#define WHITE   "\033[1m\033[37m"

#include <iostream>
#include <Windows.h> //system
#include <stdio.h> //printf

using namespace std;
void LoadingBar(){
    system("COLOR B");
    system("cls");
    printf("\e[?25l");

    //Set ASCII to print special character.
    //Code page 437
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;

    cout << "\n\n\n\t\t\t\tLoading...";
    cout << "\n\n\n\t\t\t\t";

    for(int i = 0; i < 25; i++)
        cout << (char)bar1;

    cout <<"\r";
    cout <<"\t\t\t\t";
    for(int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(150);
    }

    cout<<"\n\t\t\t\t" << "Welcom to Poker KW!\n\t\t\t\t";
    system("Pause");
    system("CLS");
    system("COLOR 7");
}