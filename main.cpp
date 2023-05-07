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
                clrscreen();
                settings_menu();
                int choice{num_input()};
                switch(choice)
                {
                    case 1:
                        int board_number{num_input()};
                        if(board_number > 25)
                            std::cout << "number too massive for game board\n";
                        else
                            g_board_number = board_number;
                        break;
                  //  case 2:
                  //  {
                 //       clrscreen();
                 //       difficulty_menu();
                  //      break;
                  //  }
                }
                break;
            }
            case 6:
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