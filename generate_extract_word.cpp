#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_set>
#include <ctime>
#include <cctype>
#include "generate_extract_word.h"
using namespace std;

/*
What Is This Function:
The goal of this function is to generate a random valid
5 character word. The final output word is all capital.
The validity of the randomly generated word is checked
by checking if it exists in the english dictionary file
called "words_alpha.txt".

Why read the .txt file into a hashtable (dictionary)
and not just check the words by comparing each 
word in the .txt file with the generated word?
Well, comparing the generated word with each 
line in the .txt file using I/O methods took 
anywhere from 10-30 seconds to return a value
while using a hashtable only takes within a
second or two. Using a hashtable is not only
quicker but less memory intensive. Dynamic
memory management is also used to further
optimize the function and avoid memory leaks.

Function Made By:
Muhammad Shahab Hasan (3035961992)
*/

string generate_word() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int i, j;
    srand(time(nullptr));
    string word = "";

    unordered_set<string>* dictionary = new unordered_set<string>;
    ifstream file("themes/words_alpha.txt");

    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            dictionary->insert(line);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
        return "";
    }

    bool found_word = false;
    do {
        word = "";
        for (i = 0; i < 5; i++) {
            j = rand() % 26;
            word += alphabet[j];
        }

        found_word = dictionary->find(word) != dictionary->end();

    } while (!found_word);

    delete dictionary;
    transform(word.begin(), word.end(), word.begin(), ::toupper);
    return word;
}

/*
The goal of this function is to take a string input and return a random word from the corresponding file.
The input can be "animals", "color", "countries", "food", or "languages".
The function returns "Invalid input type" if the input is not one of the five options.
The function returns "Unable to open file" if the file cannot be opened.

Function Made By:
Dongwoo Kang (3036029777)
*/

string theme_word_extractor(int type)
{
    string filename;
    if (type == 4)
    {
        filename = "themes/animals_theme.txt";
    }
    else if (type == 6)
    {
        filename = "themes/color_theme.txt";
    }
    else if (type == 5)
    {
        filename = "themes/countries_theme.txt";
    }
    else if (type == 3)
    {
        filename = "themes/food_theme.txt";
    }
    else if (type == 2)
    {
        filename = "themes/languages_theme.txt";
    }
    else
    {
        return "Invalid input type";
    }

    ifstream file(filename);
    if (!file)
    {
        return "Unable to open file";
    }

    string selected_word;
    string word;
    int count = 0;
    srand(time(nullptr));
    while (file >> word)
    {
        count++;
        if (rand() % count == 0)
        {
            selected_word = word;
        }
    }

    for (int i = 0; i < selected_word.length(); i++)
    {
        selected_word[i] = toupper(selected_word[i]);
    }
    return selected_word;
}