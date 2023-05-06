#include "funcs.h"
#include <iostream>

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
void settings()
{

}
//general function to get input from user, it does not accept the number 0 or smaller
int num_input()
{
    int input{};
    while(std::cin >> input && (input <= 0 || std::cin.fail()))
    {
        std::cin.ignore();
        std::cin.clear();
        std::cout << "Input invalid\n";
    }
    return input;
}