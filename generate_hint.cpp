// Importing All The Necessary Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "generate_hint.h"
using namespace std;

/*
What Is This Function:
The goal of this function is to take two "5 character string inputs",
the first being the actual word (word to guess to win the game), second
being the word guessed by the player before using a hint. The Function
extracts a random character from the "actual word" and make sures it
is not already correctly guessed in the "guessed word". Then it returns
it according to its relative index position.
Sample Input: APPLE MAPLE
Sample Output: Axxxx
Sample Input: CABLE APPLE
Sample Output: xxBxx

Function Made By:
Muhammad Shahab Hasan (3035961992)
*/

string generate_hint(string actualWord, string guessedWord) {
    srand(time(NULL)); //Using current time for random number generator seed
    string *hint = new string(5, 'x'); // dynamically allocate memory for the hint string and fill with 'x'

    while (true){ //Remains True Always, only breaks when value is returned (hint is generated)
        int random_index = rand() % 5; //generate a random index between 0 and 4
        if (actualWord[random_index] != guessedWord[random_index]){
            // checks if the character at the index is different in the actual and guessed words, if different it stores it in the 'hint' at the relative index
            (*hint)[random_index] = actualWord[random_index]; // set the character at the random index in the hint string using the dereference operator
            return *hint; // return the dereferenced 'hint' string pointer
        }
    }

    delete hint; // free the allocated memory

}
