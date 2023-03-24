#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int num_clues;
int difficulty;

int play_game(int difficulty);
char *get_word(int difficulty);
void print_clues(char *word, int numberOfClues, char **clueList);
int verifyAnswer(char *user_answer, char *correct_answer);

char *clue_list[] = {
    "Starts with the letter",
    "Ends with the letter"};

int main()
{

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
    char *word = get_word(difficulty);
    print_clues(word, num_clues, clue_list);
    return 0;
}

char *get_word(int difficulty)
{
    char *easy_words[] = {"cat", "dog", "sun", "bag", "car", "cup", "pen", "book", "desk", "door"};
    char *medium_words[] = {"puzzle", "octopus", "quartz", "jazz", "memento", "oxygen", "pajama", "pixel", "subway", "zebra"};
    char *hard_words[] = {"juxtaposition", "obsequious", "sycophant", "ubiquitous", "vexillology", "xenophobia", "yachtsman", "zymurgy", "xylophone", "haphazardly"};
    int num_words = 10;
    srand(time(NULL));
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

void print_clues(char *word, int numberOfClues, char **clueList)
{

    int lenght = strlen(word) - 1;
    char answer[100];
    int j = 0;
    int i = 0;
    printf("Clues:\n");
    while (numberOfClues > 0)
    {
        printf("%s '%c'\n Enter the word: ", clueList[i], word[j]);
        scanf("%s", answer);
        int verification = verifyAnswer(answer, word);
        if (verification == 1)
        {
            printf("Right Guess\n");
            play_game(difficulty);
            break;
        }
        i++;
        j += lenght;
        numberOfClues--;
    }
}

int verifyAnswer(char *user_answer, char *correct_answer)
{
    if (strcmp(correct_answer, user_answer) == 0)
    {
        printf("Correct answer\n");
        return 1;
    }
    else
    {
        printf("Wrong answer\n");
        return 0;
    }
}
