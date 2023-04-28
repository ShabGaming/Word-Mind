/*
The goal of this function is to take inputs filename, puzzle_solved, hint_coins, and hints_used and write them to a file.
It will be written to the respective file in the "profiles" folder. If the file doesn't exist, it will be created (New user).

The function will return 0 if the file was written successfully.

Function Made By:
Dongwoo Kang (3036029777)
*/

#include <fstream>
#include <string>
#include "edit_profile.h"
using namespace std;

int edit_profile(string filename, int puzzle_solved, int hint_coins, int hints_used) {
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
    
    return 0;
}
