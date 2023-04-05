#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unordered_set>
#include "generate_word.h"
using namespace std;

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
