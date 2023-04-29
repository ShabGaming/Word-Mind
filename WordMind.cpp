// Load in all libraries and external functions
#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "edit_load_profile.h"
#include "generate_extract_word.h"
#include "generate_hint_validate.h"
#include "instructions_intro_leaderboard.h"
#include "display_word.h"

using namespace std;

// Define a struct to store user data effectively
struct UserData
{
    string name;
    int puzzlesSolved;
    int hintsPoints;
    int hintsUsed;
};

// This function is the main gameplay function. It takes in a struct of type UserData and returns an int depending on if the user wants to play again or not.
int gameplay(UserData &user)
{
    int choice, type;
    cout << endl << "Please select an option below to get started" << endl;
    cout << "1: Instructions" << endl << "2: Leaderboard" << endl << "3: Play" << endl << "4: Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    // Ask user if they want to see instructions, leaderboard, play or exit. If invalid input, ask again.
    if (choice < 1 || choice > 4){
        while (choice < 1 || choice > 4){
            if (choice < 1 || choice > 4){
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Please select an option below" << endl;
            cout << "1: Instructions" << endl << "2: Leaderboard" << endl << "3: Play" << endl << "4: Exit" << endl;
            cin >> choice;
        }
    } else if (choice == 1){
        instructions_intro(2);
        return 2;
    } else if (choice == 2){
        cout << endl << endl;
        displayLeaderboard();
        return 2;
    } else if (choice == 3){
        cout << "Lets get guessing!" << endl;
    } else if (choice == 4){
        cout << "Thanks for playing!" << endl;
        return 0;
    }

    system("clear"); // Clear screen

    // Ask user what difficulty (theme) they want to play on. If invalid input, ask again.
    cout << "Please choose your difficulty/theme: " << endl;
    cout << "1: Random English Word (Very Hard)\n"
            << "2: Languages (Hard)\n"
            << "3: Food (Hard)\n"
            << "4: Animals (Medium)\n"
            << "5: Countries (Easy)\n"
            << "6: Colors (Easy)\n";
    cout << "Enter your choice: ";
    cin >> type;
    if (type != 1 && type != 2 && type != 3 && type != 4 && type != 5 && type != 6){
        while (type < 1 || type > 6){
            if (type < 1 || type > 6){
                cout << "Invalid choice. Please try again." << endl;
            }
            cout << "Please choose your difficulty/theme: ";
            cout << "1: Random English Word (Very Hard)\n"
                    << "2: Languages (Hard)\n"
                    << "3: Food (Hard)\n"
                    << "4: Animals (Medium)\n"
                    << "5: Countries (Easy)\n"
                    << "6: Colors (Easy)\n";
            cout << "Enter your choice: ";
            cin >> type;
        }
    }

    // Generate word based on difficulty/theme and store in string. If invalid input, ask again.
    string guess_word;
    string input_word[6];
    if (type == 1){
        guess_word = generate_word();
    } else {
        guess_word = theme_word_extractor(type);
        if (guess_word == "Invalid input type" || guess_word == "Unable to open file"){
            cout << "Error with program, please make sure all files are downloaded properly" << endl;
            return 0;
        }
    }

    system("clear"); // Clear screen
    instructions_intro(1);

    bool win = false;
    for (int i = 0; i < 6; i++){
        bool valid = false;
        cout << endl << endl << "Enter your 5 letter guess: ";
        cin >> input_word[i];
        input_word[i] = convert_to_upper(input_word[i]);
        // Validate input using validate_word function, if invalid, ask again.
        if (validate_word(input_word[i]) == false) {
            cout << "Invalid input. Please input a 5 character english word." << endl;
            cout << "Enter your 5 letter guess: ";
            while (valid == false) {
                cin >> input_word[i];
                valid = validate_word(input_word[i]);
                if (valid == false){
                    cout << "Invalid input. Please input a 5 character english word." << endl;
                }
            }
        }

        // Check if word is already guessed, if yes, ask again, if no, continue loop.
        if (i > 0){
            for (int j = 0; j < i; j++){
                if (input_word[i] == input_word[j]){
                    cout << "Word already guessed. Please try again." << endl;
                    cout << "Enter your 5 letter guess: ";
                    cin >> input_word[i];
                    while (valid == false) {
                        cout << "Enter your 5 letter guess: ";
                        cin >> input_word[i];
                        valid = validate_word(input_word[i]);
                        if (valid == false){
                            cout << "Invalid input. Please input a 5 character english word." << endl;
                        }
                    }
                }
            }
        }

        // Check if user has won, if yes, break loop, if no, continue loop.
        if (input_word[i] == guess_word)
        {
            win = true;
            break;
        } else {
            win = false;
        }
        
        system("clear"); // Clear screen
        cout << "   WORD MIND   " << endl;
        cout << "---------------" << endl;
        for (int j = 0; j <= i; j++){
            display_word(input_word[j], guess_word);
        }
        cout << "---------------" << endl << endl;

        // If user has not guessed the word and it is not their last guess, ask if they want a hint.
        if (i != 5 && win == false){
            int hint_choice;
            // Ask user if they want a hint, if yes, generate hint and display, if no, continue loop.
            cout << "Would you like a hint? " << endl << "1: Yes" << endl << "2: No (Continue)" << endl << "Enter your choice: ";
            string temp;
            cin >> temp;
            hint_choice = stoi(temp); // Terminating program if user inputs a string instead of an integer.

            // If user has no hint points left, tell them they have no hint points left and continue loop.
            if (hint_choice == 1){
                if (user.hintsPoints == 0){
                    cout << "Sorry, you have no hint points left. You got this!" << endl;
                } else {
                    cout << "Here is your hint:" << generate_hint(guess_word, input_word[i]);
                    user.hintsPoints -= 1;
                    user.hintsUsed += 1;
                    edit_profile(user.name, user.puzzlesSolved, user.hintsPoints, user.hintsUsed);
                }
            } else if (hint_choice == 2){
                cout << "You got this, lets continue!" << endl << endl;
            }
        }
    }

    // Check if user has won or lost after 6 guesses, if won, congratulate, if lost, display correct word.
    if (win){
        cout << "Congratulations! You guessed the word!" << endl;
        edit_profile(user.name, user.puzzlesSolved + 1, user.hintsPoints, user.hintsUsed);
    } else {
        cout << "Sorry, you have lost. The word was " << guess_word << endl;
        edit_profile(user.name, user.puzzlesSolved, user.hintsPoints + 1, user.hintsUsed);
    }

    // Ask user if they want to play again, if yes, call function again, if no, return 0
    cout << "Would you like to play again? " << endl << "1: Yes" << endl << "2: No." << endl;
    cin >> choice;
    if (choice != 1 && choice != 2){
        while (choice != 1 && choice != 2){
            if (choice != 1 && choice != 2){
                cout << "Invalid choice. 1 for Yes, 2 for No. Please try again." << endl;
            }
            cout << "Enter your choice: ";
            cin >> choice;
        }
    }
    if (choice == 1){
        gameplay(user);
    } else if (choice == 2){
        cout << "Thanks for playing! See you soon again :)" << endl;
        return 0;
    }
    return 0;
}


// The main function, calls all other functions and runs the game.
int main(){
    UserData user;
    system("clear"); // Clear screen
    instructions_intro(1); // Display Introduction & Ask if new user or not
    cout << endl << "Are you a first time player?" << endl << "1: Yes" << endl << "2: No" << endl;
    int choice, run;
    cout << endl << "Enter your choice: ";
    cin >> choice;
    // Validate input, if invalid, ask again. Checks if user is new to game or not. If new, create new profile. If not, load profile. Stores relevant data in struct.
    if (choice != 1 && choice != 2){
        while (choice != 1 && choice != 2){
            if (choice != 1 && choice != 2){
                cout << "Invalid choice. 1 for Yes, 2 for No. Please try again." << endl;
            }
            cout << "Enter your choice: ";
            cin >> choice;
        }
    }
    if (choice == 1){
        cout << "Enter your username: ";
        cin >> user.name;
        user.name = convert_to_upper(user.name);
        edit_profile(user.name, 0, 3, 0); // Create new profile with default values
        cout << endl << "Welcome, " << user.name << "!" << endl;
        user.puzzlesSolved = 0;
        user.hintsPoints = 3;
        user.hintsUsed = 0;
    } else if (choice == 2){
        cout << "Please enter your username: ";
        cin >> user.name;
        user.name = convert_to_upper(user.name);
        int load = load_profile(user.name, user.puzzlesSolved, user.hintsPoints, user.hintsUsed); // Load profile and store data in struct
        if (load == 0){
            cout << endl << "Welcome back, " << user.name << "!" << endl;
        } else if (load == 1){
            cout << "Sorry, " << user.name << " does not exist. Please try again or create a new profile." << endl;
            choice = 3;
        }
    }

    // If gameplay returns 0, The user wants to end the program. It returns 1 if the user wants to play again.
    run = gameplay(user);
    if (run == 0){
        return 0;
    } else if (run == 1){
        system("clear"); // Clear screen
        gameplay(user);
    } else if (run == 2){
        gameplay(user);
    }
}
