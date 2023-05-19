#ifndef FUNCS_H
#define FUNCS_H
#include <vector>
void clrscreen();
//game's main start menu
void start_menu();
//general function to get input from user, it does not accept the number 0 or smaller
int num_input();
//introductory start to the game
void introductory();
//function that displays game rules
void rules();
//the main game's logic is coded here
void game_start();
#endif