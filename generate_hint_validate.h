// generate_hint_validate.h
#ifndef generate_hint_validate_H
#define generate_hint_validate_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;

string generate_hint(string actualWord, string guessedWord);
bool validate_word(string word);
string convert_to_upper(string word);

#endif
