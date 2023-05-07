#ifndef FUNCS_H
#define FUNCS_H
void clrscreen();
//game's main start menu
void start_menu();
//settings menu
void settings_menu();
//menu for selecting difficulty, changes algorithm of choosing snake and ladder amount
void difficulty_menu();
//general function to get input from user, it does not accept the number 0 or smaller
int num_input();
#endif