// It is an int function which takes the input string as the file name then update the variables.
// The varibles include number of puzzles solved, hint coins and hint used.
// If the txt file / user doesn't exist, the function will return 1.
// Function Made By: Bosco Fung (3036059461)

#include <iostream>
#include <fstream>
#include <string>
#include "load_profile.h"
using namespace std;

int load_profile(string filename, int& puzzle_solved, int& hint_coins, int& hints_used) {
    ifstream file("./profiles/" + filename + ".txt");
    if (file.is_open()) {
        string line;
        getline(file, line); 
        getline(file, line);
        puzzle_solved = stoi(line);
        getline(file, line); 
        hint_coins = stoi(line);
        getline(file, line);
        hints_used = stoi(line);
        file.close();
        return 0;
    } else {
        return 1;
    }
}
