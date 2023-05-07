#include "funcs.h"
#include <iostream>
//general clearing of terminal screen
void clrscreen()
{
    #ifdef WINDOWS
        system("cls");
    #else   
        system("clear");
    #endif
}
//game's main start menu
void start_menu()
{
    std::cout << "____________________________SNAKE__AND__LADDERS_______________________________\n\n";

    std::cout << "1.1 Player Game\n";
    std::cout << "2.2 Player Game\n";
    std::cout << "3.3 Player Game\n";
    std::cout << "4.4 Player Game\n";
    std::cout << "5.Settings\n";
    std::cout << "6.Exit\n";
}
//settings menu
void settings_menu()
{
    std::cout << "1.Board number(default: 10)\n";
    std::cout << "2.Difficulty(default: normal)\n";
    std::cout << "3.Back\n";
}
void difficulty_menu()
{
    std::cout << "1.Baby mode\n";
    std::cout << "2.Easy\n";
    std::cout << "3.Normal\n";
    std::cout << "4.Expert\n";
    std::cout << "5.Hardcore\n";
}
//general function to get input from user, it does not accept the number 0 or smaller
int num_input()
{
    int input{};
    while(std::cin >> input && (input <= 0 || std::cin.fail()))
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Input invalid\n";
    }
    return input;
}