#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    std::vector<std::string> words = {"apple", "banana", "cherry", "date", "elderberry", "fig", "grape", "honeydew", "kiwi", "lemon", "mango", "nectarine", "orange", "peach", "quince", "raspberry", "strawberry", "tangerine", "watermelon"};
    std::srand(std::time(nullptr)); // seed the random number generator
    std::string word = words[std::rand() % words.size()]; // pick a random word from the list

    std::string guessedLetters = "";
    int incorrectGuesses = 0;

    std::cout << "Welcome to Hangman!" << std::endl;

    while (true) {
        std::string hiddenWord = "";
        for (char c : word) {
            if (guessedLetters.find(c) == std::string::npos) {
                hiddenWord += "_ ";
            } else {
                hiddenWord += c;
                hiddenWord += " ";
            }
        }

        std::cout << "Guess the word: " << hiddenWord << std::endl;

        if (hiddenWord.find("_") == std::string::npos) {
            std::cout << "Congratulations, you won!" << std::endl;
            break;
        }

        std::string guess;
        std::cout << "Guess a letter: ";
        std::cin >> guess;

        if (guessedLetters.find(guess) != std::string::npos) {
            std::cout << "You already guessed that letter. Try again." << std::endl;
            continue;
        }

        guessedLetters += guess;

        if (word.find(guess) == std::string::npos) {
            std::cout << "Incorrect guess." << std::endl;
            incorrectGuesses++;
        }

        if (incorrectGuesses == 6) {
            std::cout << "Sorry, you lost. The word was: " << word << std::endl;
            break;
        }
    }

    return 0;
}
