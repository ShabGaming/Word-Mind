#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "theme_word_extractor.h"
using namespace std;

string theme_word_extractor(string type)
{
    string filename;
    if (type == "animals")
    {
        filename = "themes/animals_theme.txt";
    }
    else if (type == "color")
    {
        filename = "themes/color_theme.txt";
    }
    else if (type == "countries")
    {
        filename = "themes/countries_theme.txt";
    }
    else if (type == "food")
    {
        filename = "themes/food_theme.txt";
    }
    else if (type == "languages")
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
