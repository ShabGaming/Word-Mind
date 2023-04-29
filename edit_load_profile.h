// edit_load_profile.h
#ifndef edit_load_profile_H
#define edit_load_profile_H

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

void edit_profile(string filename, int puzzle_solved, int hint_coins, int hints_used);
int load_profile(string filename, int &puzzle_solved, int &hint_coins, int &hints_used);

#endif
