#include "display_word.h"


/*
This is a void function, its goal is to take a 5 character string input and display it in a formatted way. The functions takes 2 string inputs, the first one being the "guessed word" and the second one being "actual word". The function then compares the two strings and displays the guessed word in a formatted way. The function does not return anything. The format is as follows:
Sample Input:   APPLE MAPLE
Sample Output: (A) P [P][L][E]
Basically if the letter in the guessed word exists in the actual word, it is displayed in round breackets. If the letter exists in the actual word and is in the correct position, it is displayed in square brackets. If the letter does not exist in the actual word, it is displayed as is. The format for the string is 15 empty characters long, which are replaced depending on the conditions. Priority is given to the letters in the correct position, then the letters in the wrong position and then the letters that do not exist in the actual word. We also implemented a vector to store the indexes of the characters that are in the wrong position. We then check if the characters in the wrong position exist in the actual word or not. If they do, we replace them with round brackets. As the terminal does not show white spaces at the beginning of the string, we use a boolean variable to check if the first character is a space or not. If it is a space, we add a space before the formatted word.

Function Made By:
Muhammad Shahab Hasan (3035961992)
Bosco Fung (3036059461)
*/

void display_word(string guessedWord, string actualWord)
{
    bool firstCharSpace = false; // boolean variable to check if the first character is a space or not
    string formattedWord = "               "; // initialize formatted word with 15 spaces
    string tempActualWord = actualWord; // make a copy of actual word to check if the character exists in the actual word or not
    // make a copy of guessed word with a one space between the first and last character and 2 spaces between the rest
    for (int i = 0; i < guessedWord.length(); i++)
    {
        int index = 1 + i * 3;                 // calculate the index of the character in the formatted word
        formattedWord[index] = guessedWord[i]; // set the character in the formatted word
    }

    int i = 1;
    int j = 0;
    vector <int> indexes;
    while (j < 5){
        if (formattedWord[i] == actualWord[j]){
            formattedWord[i - 1] = '[';
            formattedWord[i + 1] = ']';
            if (i == 1){
                firstCharSpace = true;
            }
            tempActualWord.erase(tempActualWord.find(formattedWord[i]), 1);
        } else {
            indexes.push_back(i);
        }
        j++;
        i += 3;
    }

    for (int j = 0; j < indexes.size(); j++){
        if (tempActualWord.find(formattedWord[indexes[j]]) != string::npos){
            tempActualWord.erase(tempActualWord.find(formattedWord[indexes[j]]), 1);
            formattedWord[indexes[j] - 1] = '(';
            formattedWord[indexes[j] + 1] = ')';
            if (indexes[j] == 1){
                firstCharSpace = true;
            }
        }
    }

    if (firstCharSpace){
        cout << " " << formattedWord << endl;
    } else {
        cout << formattedWord << endl;
    }
}