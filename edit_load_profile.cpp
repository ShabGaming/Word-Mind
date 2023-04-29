#include "edit_load_profile.h"

/*
The goal of this function is to take inputs filename, puzzle_solved, hint_coins, and hints_used and write them to a file.
It will be written to the respective file in the "profiles" folder. If the file doesn't exist, it will be created (New user).

Function Made By:
Dongwoo Kang (3036029777)
*/

void edit_profile(string filename, int puzzle_solved, int hint_coins, int hints_used) {
    // Open the file for writing
    ofstream file("profiles/" + filename + ".txt", ios::app);
    
    // Check if the file was opened successfully
    if (!file.is_open()) {
        // If the file does not exist, create it
        file.open("profiles/" + filename + ".txt");
    }
    
    // Write the data to the file
    file << filename << "\n" << puzzle_solved << "\n" << hint_coins << "\n" << hints_used << "\n";
    
    // Close the file
    file.close();
}

// It is an int function which takes the input string as the file name then update the variables.
// The varibles include number of puzzles solved, hint coins and hint used.
// If the txt file / user doesn't exist, the function will return 1.
// Function Made By: Bosco Fung (3036059461)

int load_profile(string filename, int &puzzle_solved, int &hint_coins, int &hints_used)
{
    ifstream file("./profiles/" + filename + ".txt");
    if (file.is_open())
    {
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
    }
    else
    {
        return 1;
    }
}