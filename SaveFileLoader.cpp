#include <iostream>
#include <fstream>
#include <string>

int update_profile(std::string filename, int& puzzle_solved, int& hint_coins, int& hints_used) {
    std::ifstream file(filename + ".txt");
    if (file.is_open()) {
        std::string line;
        getline(file, line); 
        getline(file, line);
        puzzle_solved = std::stoi(line);
        getline(file, line); 
        hint_coins = std::stoi(line);
        getline(file, line);
        hints_used = std::stoi(line);
        file.close();
        return 0;
    } else {
        return 1;
    }
}
