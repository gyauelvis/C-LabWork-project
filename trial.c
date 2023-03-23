#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function prototypes
void play_game(int difficulty);
int get_random_number(int min, int max);
void get_word(char *word, int length);
void get_clue(char *word, char *clue, int index);

int main() {
    int difficulty;

    printf("Welcome to the word guessing game!\n");
    printf("Choose your difficulty level (1=easy, 2=medium, 3=hard): ");
    scanf("%d", &difficulty);

    play_game(difficulty);

    return 0;
}

void play_game(int difficulty) {
    const int max_word_length = 20;
    char word[max_word_length + 1];
    char clue[81];
    int num_clues = 0;
    int points = 0;

    // Set the number of clues based on the difficulty level
    switch (difficulty) {
        case 1:
            num_clues = 5;
            break;
        case 2:
            num_clues = 4;
            break;
        case 3:
            num_clues = 3;
            break;
        default:
            printf("Invalid difficulty level.\n");
            return;
    }

    // Get a random word
    get_word(word, max_word_length);

    // Play the game
    for (int i = 0; i < num_clues; i++) {
        get_clue(word, clue, i);
        printf("Clue %d: %s\n", i+1, clue);
        printf("Enter your guess: ");
        char guess[max_word_length + 1];
        scanf("%s", guess);
        if (strcmp(word, guess) == 0) {
            // Correct guess
            printf("Correct!\n");
            points += (num_clues - i) * 10;
            break;
        } else {
            // Incorrect guess
            printf("Incorrect!\n");
        }
    }

    // Show the answer and the points
    printf("The word was: %s\n", word);
    printf("You scored %d points.\n", points);
}

int get_random_number(int min, int max) {
    static int initialized = 0;
    if (!initialized) {
        srand(time(NULL));
        initialized = 1;
    }
    return rand() % (max - min + 1) + min;
}

void get_word(char *word, int length) {
    const char *word_list[] = {
        "apple",
        "banana",
        "cherry",
        "orange",
        "pear",
        "grape",
        "pineapple",
        "watermelon",
        "strawberry",
        "kiwi"
    };
    int num_words = sizeof(word_list) / sizeof(word_list[0]);
    int index = get_random_number(0, num_words - 1);
    strncpy(word, word_list[index], length);
    word[length] = '\0';
}

void get_clue(char *word, char *clue, int index) {
    const char *clue_list[] = {
        "Starts with the letter '%c'",
        "Ends with the letter '%c'",
        "Has %d letters",
        "Contains the letter '%c'"
    };
    int num_clues = sizeof(clue_list) / sizeof(clue_list[0]);
    int i = get_random_number(0, num_clues - 1);
    switch (i) {
        case 0:
            sprintf(clue, clue_list[i], word[0]);
            break;
    }}
