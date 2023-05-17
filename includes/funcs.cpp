#include "funcs.h"
#include "classes.h"
#include "config.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
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
            std::cin.get();
            std::cin.get();
            stupidseg_end = true;
            break;
        case 2:
            std::cout << "Well, tough luck! You thought I would care enough to actually program you to be able to get out of the game?\n"
            "You're playing it anyway HAHAHAHAHAHAHAHAHAHAHAHAHAHA\n";
            std::cin.get();
            std::cin.get();
            stupidseg_end = true;
            break;
        default:
            std::cout << "Are you kidding me? take this seriously\n";
            std::cin.get();
            std::cin.get();
    }
}
}
//function that displays game rules
void rules()
{
    std::cout << "The rules are simple!\n";
    std::cin.get();
    std::cout << "This game is only played with a dice\n";
    std::cin.get();
    std::cout << "You can only start moving in the game once you got a six\n";
    std::cin.get();
    std::cout << "Your mission: get to the top of the board in one piece\n"
    "That's easier said than done is it not?\n";
    std::cin.get();
    std::cout << "I'm sure you'll do well\n";
    std::cin.get();
    std::cout << "That was the end of the rules. Now let's get to it!\n";
    std::cin.get();
}
//the main game's logic is coded here
void game_start(int player_count)
{
    Board game_board{g_board_number};
    Dice game_dice{g_dice_sides};
    Player player(red);
    Snake game_snakes[g_snake_number]
    {
        Snake({3,1}, {4,3}), 
        Snake({5,4}, {5,7}), 
        Snake({9,3}, {8,9})
    };
    Ladder game_ladders[g_ladder_number]
    {
        Ladder({6,0}, {6,3}),
        Ladder({2,3}, {1,4}),
        Ladder({2,5}, {3,7})
    };
    while(true)
    {
        clrscreen();
        player.show_coordinates();
        std::cout << "Throw Dice?\n";
        std::cout << "Press 'd' on keyboard to throw dice(Press 'e' to exit game)\n";
        char usr_action{};
        while(std::cin >> usr_action && (usr_action != 'd' && usr_action != 'e') || std::cin.fail())
        {
            std::cin.ignore();
            std::cin.clear();
            std::cout << "input invalid\n";
        }
        switch(usr_action)
        {
            case 'd':
            {
                int dice_number{game_dice.throw_dice(player)};
                std::cout << dice_number << '\n';
                player.move(dice_number);
                std::cout << "You moved by " << dice_number << '\n';
                std::cin.get();
                std::cin.get();
                bool is_on_snake{};
                bool is_on_ladder{};
                int snake_index{0};

                for( ;snake_index < g_snake_number; ++snake_index)
                {
                    is_on_snake = game_snakes[snake_index].get_end().x == player.get_coordinate().x 
                    && game_snakes[snake_index].get_end().y == player.get_coordinate().y;
                }


                if(is_on_snake)
                {
                    std::cout << "Oh, NO!!You got caught by a snake!\nYou lost a lot of progress!\n";
                    game_snakes[snake_index].move_player(player);
                    std::cin.get();
                    std::cin.get();
                }
                else
                {
                    int ladder_index{0};
                    for(;ladder_index < g_ladder_number; ++ladder_index)
                    {
                        is_on_ladder = game_ladders[ladder_index].get_start().x == player.get_coordinate().x &&
                        game_ladders[ladder_index].get_start().y == player.get_coordinate().y;
                    }
                    if(is_on_ladder)
                    {
                        std::cout << "You found a ladder! Congratulations!\n You have moved a bit more towards your goal!\n";
                        game_ladders[ladder_index].move(player);
                        std::cin.get();
                        std::cin.get();
                    }
                }
                break;
            }
            case 'e':
                return;
            default:
                std::cout << "key unsupported\n";
                std::cin.get();
                std::cin.get();
        }
    }
}