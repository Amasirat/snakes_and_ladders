#include "funcs.h"
#include "classes.h"
#include "config.h"
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
    std::cout << "5.Exit\n";
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
//the main game's logic is coded here
//void Game_start(int player_count)
//{
 //   Board game_board{g_board_number};
 //   Dice game_dice{g_dice_sides}; 
//    Player player1(red);

//}