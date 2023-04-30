# COMP2113 Group Project | Group 96
Github Repositary For COMP2113 Group Project: "Implementing a text-based mini-game of our own choice"

**Group Members:**
- Muhammad Shahab Hasan (BASc Applied AI)
  - shahab@connect.hku.hk
  - 3035961992

- Bosco Fung (BASc Applied AI)
  - bfung777@connect.hku.hk
  - 3036059461
  
- Dongwoo Kang (BEng DS&E)
  - u3602977@connect.hku.hk
  - 3036029777
  
Please go through the information down below to learn more about the project and how to get started!
-----

![2DMdDuNW](https://user-images.githubusercontent.com/69019319/235075809-9c57ecdb-e11f-4b82-8692-71761137bd17.gif)

## Introduction To The Game
The "Word Mind" game is a terminal-based word-guessing game inspired by the popular game "Wordle". The objective of the game is to guess a randomly generated five-letter word in six attempts or fewer. The game offers two modes of play: generic words, which are randomly generated, and themed words, which are based on specific topics or categories; Color, Countries, Food or Langauges.

### Gameplay & Rules
To play the game, the player must guess a five letters and submit their guess. The game then reveals which of the chosen letters are in the target word and whether they are in the correct position.
```
( ) Represents the letter is in the word but not in the correct position
[ ] Represents the letter is in the word and in the correct position
```
The player can use this information to refine their guess for the next attempt. The game ends when the player correctly guesses the target word or exhausts all six attempts. The game also features a hint system, which allows the player to receive a clue for the target word. First time player receives three hint points, and they earn an additional hint point every time they fail to guess the target word. The player can use a hint point to reveal one letter of the target word, which can help narrow down the possibilities for their next guess.

*For a demonstration take a look at this demo video:*

## Features
- [x] **:space_invader: Generation of random game sets or events:**
Our group project involves the implementation of a program that generates random English words from the entire English dictionary. Additionally, we have incorporated a functionality that selects a random theme word from the relevant theme word .txt files.
- [x] **:open_file_folder: Data structures for storing game status:**
Our group has made the decision to utilize .txt files to store player profiles, including their name, number of puzzles solved, available hint points, and other stats. Furthermore, we have incorporated custom structs in certain functions to enhance the program's functionality and readability. We have also impelemnted the usage of Hashtables to optimize the speed of program execution for the "word generation" function.
- [x] **:floppy_disk: Dynamic memory management:**
Our group has skillfully incorporated Dynamic Memory Management in several functions, as well as the main function, to optimize the program's memory usage and prevent memory leaks. This technique has been employed to store guess words, the word to guess, and other relevant data in multiple functions.
- [x] **:card_index_dividers: File input/output:**
Our group has successfully integrated file input/output functionality in our game, allowing the program to edit and load their profiles and associated data, such as guess words and hint coins. Additionally, we have incorporated file input in the "random theme word" selection function, enabling the program to access and utilize external data sources.
- [x] **:technologist: Program codes in multiple files:**
Our group has adopted a modular approach in our project, dividing it into multiple smaller functions. This approach has allowed us to write more efficient and readable code for the game. By organizing the program's functionality in a modular fashion, we have increased its readabilty, functionality and scalability.
- [x] **:bookmark_tabs: Proper indentation and naming styles:**
We have maintained proper indentation and utilized meaningful variable names throughout our project. This ensures that the code is easily readable and understandable for anyone reviewing it.
- [x] **:memo: In-code documentation:**
We added easy to understand readable comments throughout the project to improve code clarity and understandability.

## Quickstart Guide
Ready to play? Getting started is simple. One you have downloaded / cloned the repository write the following commands:
```
make WordMind
./WordMind
```
To delete the files you may use `make clean`

Thats it! Don't forget to enjoy :smile:

Thanks for playing!!!
