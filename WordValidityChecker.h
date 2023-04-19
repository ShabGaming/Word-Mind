//This is a function that takes a string input and ensure the word is good for the game.
//It will screen out numbers and words that are too long, too short or does not exists.
//It will return true if the word is valid and false if the word is invalid
// coded by Bosco Fung UID:3036059461
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool validate_word(string word){
    if (word.length() < 5){
        cout << "Insufficient Letters" << endl;
        return false;
    }
    else if (word.length() > 5){
        cout << "Too many letters" << endl;
        return false;
    }
    for(int i=0;i<word.length();i++){
        if(word[i]>='a' && word[i]<='z'){
            continue;
        }
        else{
            cout << "Invalid" << endl;
            return false;
        }
    }
    ifstream fin("words_alpha.txt");
    bool found = false;
    string temp;
    while (fin >> temp){
        if (temp == word){
            found = true;
            break;
        }
        else{
            continue;
        }
    }
    if (found == false){
        cout << "Invalid" << endl;
        return false;
    }
    else if (found == true){
        return true;
    }
    fin.close();
}
