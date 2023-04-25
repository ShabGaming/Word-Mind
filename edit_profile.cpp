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
