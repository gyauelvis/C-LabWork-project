#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void play_game(int difficulty);
char *get_word(int difficulty);
// void print_clues(int num_clues, char* word);
// int take_guess(char* word);
void play_again();

int main()
{
    int difficulty;
    printf("Welcome to the Word Guessing Game!\n");
    printf("Please choose a difficulty level\n1 - Easy\n 2 - Medium\n 3 - Hard\n");
    scanf("%d", &difficulty);
    play_game(difficulty);
    return 0;
}

void play_game(int difficulty)
{
    char *word = get_word(difficulty);
    int num_clues = 0;
    if (difficulty == 1)
    {
        num_clues = 5;
    }
    else if (difficulty == 2)
    {
        num_clues = 4;
    }
    else if (difficulty == 3)
    {
        num_clues = 3;
    }
    else
    {
        printf("Invalid difficulty level. Please try again.\n");
        main();
        return;
    }
    printf("You have %d clues to guess the word.\n", num_clues);
    print_clues(num_clues, word);
    int points = 10 / num_clues;
    int guess = take_guess(word);
    while (guess != 1 && num_clues > 0)
    {
        printf("Sorry, that's incorrect.\n");
        num_clues--;
        if (num_clues > 0)
        {
            printf("You have %d clues left.\n", num_clues);
            print_clues(num_clues, word);
            points = 10 / num_clues;
            guess = take_guess(word);
        }
    }
    if (guess == 1)
    {
        printf("Congratulations! You guessed the word.\n");
        printf("You earned %d points.\n", points);
        play_again();
    }
    else
    {
        printf("Sorry, you ran out of clues.\n");
        printf("The word was %s.\n", word);
        play_again();
    }
}

char *get_word(int difficulty)
{
    char *easy_words[] = {"cat", "dog", "sun", "bag", "car", "cup", "pen", "book", "desk", "door"};
    char *medium_words[] = {"puzzle", "octopus", "quartz", "jazz", "memento", "oxygen", "pajama", "pixel", "subway", "zebra"};
    char *hard_words[] = {"juxtaposition", "obsequious", "sycophant", "ubiquitous", "vexillology", "xenophobia", "yachtsman", "zymurgy", "xylophone", "haphazardly"};
    int num_words = 10;
    int index = rand() % num_words;
    char *word;
    if (difficulty == 1)
    {
        word = easy_words[index];
    }
    else if (difficulty == 2)
    {
        word = medium_words[index];
    }
    else
    {
        word = hard_words[index];
    }
    return word;
}

void play_again()
{
    printf("");
}


// void print_clues(int num_clues, char* word) {
//     int length = strlen(word);
//     int num_letters = length / num_clues;
//     printf("Clue: ");
//     for (int i = 0; i < length; i++) {
//         if (i % num_letters == 0) {
//             printf("%c ", word[i]);
//         } else {
//             printf("_ ");
//         }
//     }
// }