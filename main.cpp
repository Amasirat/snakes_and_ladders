#include "includes/config.h"
//all classes, user_defined data types and that sort is in here
#include "includes/classes.h"
//basic funcs to do tasks
#include "includes/funcs.h"
//standard input-output
#include <iostream>


int main()
{
    Player player{red};

    player.move(4);
    player.move(6);
    /*
    bool program_end = false;
    while(!program_end)
    {
        start_menu();
        int choice{num_input()};
        switch(choice)
        {
            case 1:
            {
                break;
            }
            case 2:
            {
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                break;
            }
            case 5:
            {
                program_end = true;
                break;
            }
            default:
                std::cin.clear();
                std::cin.ignore();
                std::cout << "Input not valid\n";
        }
    } */
    return 0;
}