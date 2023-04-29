#include "instructions_intro_leaderboard.h"

/*
The goal of this function is to take an integer input 1 or 2,
if the input is 1 the function displays the introduction message
else it displays the game rules/instructions.

The introduction message is displayed from the file "intro.txt" which is located in the "themes" folder.
The rules/instructions are displayed from the file "instructions.txt" which is located in the "themes" folder.

Function Made By:
Muhammad Shahab Hasan (3035961992)
*/

void instructions_intro(int input){
    if (input == 1){
        string line;
        ifstream file("themes/intro.txt");
        if (file.is_open()){
            while (getline(file, line)){
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    } else if (input == 2){
        string line;
        ifstream file("themes/instructions.txt");
        if (file.is_open()){
            while (getline(file, line)){
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    } else if (input == 2){
        string line;
        ifstream file("themes/instructions.txt");
        if (file.is_open()){
            while (getline(file, line)){
                cout << line << endl;
            }
            file.close();
        } else {
            cout << "Unable to open file" << endl;
        }
    } else {
        cout << "Invalid input" << endl;
    }
}

/*
The goal of this function is to output the leaderboard of the game.,
The leaderboard is displayed from the files in the "porfiles" folder.
We also use a custom struct to store the user data, allowing easy manuplation.
The leaderboard is sorted based on the number of puzzles solved.

Function Made By:
Muhammad Shahab Hasan (3035961992) & Dongwoo Kang (3036029777)
*/

struct UserData
{
    string name;
    int puzzlesSolved;
    int hintsPoints;
    int hintsUsed;
};

bool compareUserData(const UserData &a, const UserData &b)
{
    return a.puzzlesSolved > b.puzzlesSolved;
}

void displayLeaderboard()
{
    string folderName = "profiles/";
    vector<UserData> users;

    // Open directory
    DIR *dir;
    struct dirent *entry;
    if ((dir = opendir(folderName.c_str())) != NULL)
    {
        // Iterate over files in directory
        while ((entry = readdir(dir)) != NULL)
        {
            // Check if file is a .txt file
            if (entry->d_type == DT_REG && string(entry->d_name).find(".txt") != string::npos)
            {
                // Open file and read user data
                string fileName = folderName + entry->d_name;
                ifstream file(fileName);
                UserData user;
                getline(file, user.name);
                file >> user.puzzlesSolved >> user.hintsPoints >> user.hintsUsed;
                users.push_back(user);
                file.close();
            }
        }
        closedir(dir);
    }
    else
    {
        // Error opening directory
        cout << "Error: Could not open directory " << folderName << endl;
        return;
    }

    // Sort users based on puzzles solved
    sort(users.begin(), users.end(), compareUserData);

    // Display leaderboard
    cout << "Leaderboard:" << endl;
    for (int i = 0; i < users.size(); i++)
    {
        cout << "#" << i + 1 << " " << users[i].name << " \"" << users[i].puzzlesSolved << "\"" << endl;
    }
}
