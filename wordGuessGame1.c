#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int num_clues;

int play_game(int difficulty);
char *get_word(int difficulty);

int main()
{
    int difficulty;
    printf("Welcome to the Word Guessing Game!\n");
    printf("Please choose a difficulty level\n1 - Easy\n2 - Medium\n3 - Hard\n");

    while (1)
    {
        scanf("%d", &difficulty);
        if (difficulty >= 1 && difficulty <= 3)
        {
            break;
        }
        else
        {
            printf("Invalid difficulty level. Please try again.\n");
        }
    }

    play_game(difficulty);
    return 0;
}

int play_game(int difficulty)
{
    const char *difficultyLevel;
    if (difficulty == 1)
    {
        num_clues = 5;
        difficultyLevel = "Easy";
    }
    else if (difficulty == 2)
    {
        num_clues = 4;
        difficultyLevel = "Medium";
    }
    else if (difficulty == 3)
    {
        num_clues = 3;
        difficultyLevel = "Hard";
    }

    printf("You have selected the %s level and you have %d clues to guess the correct word.\n", difficultyLevel, num_clues);
    return 0;
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
