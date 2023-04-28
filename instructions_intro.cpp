/*
The goal of this function is to take an integer input 1 or 2,
if the input is 1 the function displays the introduction message
else it displays the game rules/instructions.

The introduction message is displayed from the file "intro.txt" which is located in the "themes" folder.
The rules/instructions are displayed from the file "instructions.txt" which is located in the "themes" folder.

Function Made By:
Muhammad Shahab Hasan (3035961992)
*/

#include <iostream>
#include <fstream>
#include <string>
#include "instructions_intro.h"
using namespace std;

int instructions_intro (int input){
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
            return 0;
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
            return 0;
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
            return 0;
        }
    } else {
        cout << "Invalid input" << endl;
        return 0;
    }
}