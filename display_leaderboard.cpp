#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "display_leaderboard.h"

using namespace std;

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
    string folderName = "USERS/";
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
