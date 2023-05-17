#include "includes/config.h"
//all classes, user_defined data types and that sort is in here
#include "includes/classes.h"
//basic funcs to do tasks
#include "includes/funcs.h"
//standard input-output
#include <iostream>


int main()
{
    bool program_end = false;
    while(!program_end)
    {
        std::cout << "____________________________SNAKE__AND__LADDERS_______________________________\n\n";
        start_menu();
        int choice{num_input()};
        switch(choice)
        {
            case 1:
            {
                clrscreen();
                introductory();
                game_start(choice);
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
    }
    return 0;
}