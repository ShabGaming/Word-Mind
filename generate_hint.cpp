#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "generate_hint.h"
using namespace std;

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
