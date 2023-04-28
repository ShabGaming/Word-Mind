#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "display_leaderboard.h"

using namespace std;

/*
The goal of this function is to output the leaderboard of the game.,
The leaderboard is displayed from the files in the "porfiles" folder.
We also use a custom struct to store the user data, allowing easy manuplation.
The leaderboard is sorted based on the number of puzzles solved.

Function Made By:
Muhammad Shahab Hasan (3035961992) & Dongwoo Kang (3036029777)
*/

struct UserData {
    string name;
    int puzzlesSolved;
    int hintsTaken;
    int hintsUsed;
};

bool compareUserData(const UserData& a, const UserData& b) {
    return a.puzzlesSolved > b.puzzlesSolved;
}

void displayLeaderboard() {
    string folderName = "profiles/";
    vector<UserData> users;
    int count = 0;

    // Read user data from files
    while(true) {
        string fileName = folderName + to_string(count) + ".txt";
        ifstream file(fileName);
        if(!file) {
            break;
        }
        UserData user;
        getline(file, user.name);
        file >> user.puzzlesSolved >> user.hintsTaken >> user.hintsUsed;
        users.push_back(user);
        count++;
        file.close();
    }

    // Sort users based on puzzles solved
    sort(users.begin(), users.end(), compareUserData);

    // Display leaderboard
    cout << "Leaderboard:" << endl;
    for(int i = 0; i < users.size(); i++) {
        cout << "#" << i+1 << " " << users[i].name << " \"" << users[i].puzzlesSolved << "\"" << endl;
    }
}
