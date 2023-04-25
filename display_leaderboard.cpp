#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

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

void display_leaderboard() {
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
}
