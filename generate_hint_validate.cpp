#include "generate_hint_validate.h"

/*
This function takes a 5 letter word and converts it all to Upper case.
Sample Input: apple
Sample Output: APPLE

Function Made By: Muhammad Shahab Hasan (3035961992)
*/

string convert_to_upper(string word)
{
    for (int i = 0; i < word.length(); i++)
    {
        word[i] = toupper(word[i]); // converts each character to upper case
    }
    return word;
}

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

// This is a function that takes a string input and ensure the word is good for the game.
// It will screen out numbers and words that are too long, too short or does not exists.
// A valid word is 5 characters long, and exists in the dictionary.
// It will return true if the word is valid and false if the word is invalid.
//  Function Made By: Bosco Fung (3036059461)

bool validate_word(string word){
    if (word.length() != 5){ // Check if the word is 5 characters long
        return false;
    }
    for (int i = 0; i < word.length(); i++){ // Check if the word contains any numbers
        if (isdigit(word[i])){
            return false;
        }
    }
    ifstream dictionary("themes/words_alpha.txt"); // Open the dictionary file
    if (dictionary.fail()){ // Check if the file is opened successfully
        cout << "Unable to open file" << endl;
        return false;
    }
    string line;
    while (getline(dictionary, line)){ // Read the file line by line
        // Capatalize the word and the line to ensure the comparison is case insensitive
        word = convert_to_upper(word);
        line = convert_to_upper(line);
        if (line == word){ // Check if the word exists in the dictionary
            return true;
        }
    }
    return false;
}
