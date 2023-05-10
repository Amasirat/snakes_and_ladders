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
void introductory()
{
std::cout << "There is a " << g_board_number << " x " << g_board_number << " board right in front of you\n";
std::cin.get();
std::cin.get();
std::cout << ".\n";
std::cin.get();
std::cout << "..\n";
std::cin.get();
std::cout << "...\n";
std::cout << "You're wondering why you can't see it?\n";
std::cin.get();
std::cout << "That's because it was hidden from you by some all powerful being"
"(basically because I still can't do graphical interfaces)\n";
std::cin.get();
std::cout << "but fret not, You shall be guided by the legendary writings of the terminal font\n";
std::cin.get();
std::cout << "But that will also mean, you won't be able to see ladders or snakes while playing\n";
std::cin.get();
std::cout << "You will have to rely on your powerful luck to guide you! You'll throw a dice and move by that much up the word horizontally (just like any other gsnake and ladders game)\n";
std::cin.get();
bool stupidseg_end = false;//short for has the stupid segment ended yet?
while(!stupidseg_end)
{
    std::cout << "Are you ready to play?\n";
    std::cout << "1.Yes\t\t2.No\n";
    int choice{num_input()};
    switch(choice)
    {
        case 1:
            std::cout << "Wise choice! Let's proceed\n";
            stupidseg_end = true;
            break;
        case 2:
            std::cout << "Well, tough luck! You thought I would care enough to actually program you to be able to get out of the game?\n"
            "You're playing it anyway HAHAHAHAHAHAHAHAHAHAHAHAHAHA\n";
            stupidseg_end = true;
            break;
        default:
            std::cout << "Are you kidding me? take this seriously\n";
    }
}

}
//the main game's logic is coded here
void game_start(int player_count)
{
    Board game_board{g_board_number};
    Dice game_dice{g_dice_sides}; 
    Player player1(red);
}