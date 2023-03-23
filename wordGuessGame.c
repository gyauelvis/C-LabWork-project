#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char easyWords[10][15] = {
    "Monday", "December", "KNUST"};
char mediumWords[10][15] = {
    "Vanilla", "Newton", "Fish"};
char hardWords[10][15] = {
    "Human", "Lecturer", "Elvis"};

char mondayClues[100][150] = {
    "A day of the week that both workers and students hate", "Kojo and Adwoa", "I am the second day of the week"};
char decemberClues[100][150] = {
    "A month in a year", "Christmas is celebrated during this month", "I am the last day of the month"};
char KNUSTclues[100][150] = {
    "University in Ghana", "Named after popular person", "I am in Ashanti Region"};

int main()
{
    int difficultyLevel;
    char answer[15];
    int i = 1;

    // Ensures that Everytime the code runs a new random value is made depending on the time
    srand(time(NULL)); // seed the random number generator with the current time
    int randomNumber = rand() % 3;

    printf("WORD GUESS GAME\n");
    while (i > 0)
    {
        printf("Difficulty Level:\n1-Easy\n2-Medium\n3-Hard\n");
        scanf("%d", &difficultyLevel);
        if (difficultyLevel == 1 || difficultyLevel == 2 || difficultyLevel == 3)
        {
            break;
        }
        else
        {
            printf("Invalid Level\n");
        }
    }
    if (difficultyLevel == 1 && randomNumber == 0)
    {

        int k = 0;
        while (i < 4)
        {
            printf("%s\n", mondayClues[k]);
            printf("Enter the Word: ");
            scanf("%c", answer);
            if (strcmp(answer, easyWords[randomNumber]) == 0)
            {
                printf("Correct\n");
                break;
            }
            else
            {
                printf("Incorrect\n");
            }
            i++;
            k++;
        }
    }
    else if (difficultyLevel == 1 && randomNumber == 1)
    {
        int k = 0;
        while (i < 4)
        {
            printf("%s\n", decemberClues[k]);
            printf("Enter the Word: ");
            scanf("%c", answer);
            if (strcmp(answer, easyWords[randomNumber]) == 0)
            {
                printf("Correct\n");
                break;
            }
            else
            {
                printf("Incorrect\n");
            }
            i++;
            k++;
        }
    }
    else if (difficultyLevel == 1 && randomNumber == 2)
    {
        int k = 0;
        while (i < 4)
        {
            printf("%s\n", KNUSTclues[k]);
            printf("Enter the Word: ");
            scanf("%c", answer);
            if (strcmp(answer, easyWords[randomNumber]) == 0)
            {
                printf("Correct\n");
                break;
            }
            else
            {
                printf("Incorrect\n");
            };
            i++;
            k++;
        }
    }
    else if (difficultyLevel == 2)
    {
        while (i > 0 && i < 4)
        {
            printf("Enter the Word\n");
            scanf("%s", answer);
            
            if (strcmp(answer, mediumWords[randomNumber]) == 0)
            {
                printf("Correct\n");
                break;
            }
            else
            {
                printf("Incorrect\n");
            }
            i++;
        }
    }
    else if (difficultyLevel == 3)
    {
        while (i > 0 && i < 4)
        {
            printf("Enter the Word\n");
            scanf("%s", answer);
            if (strcmp(answer, hardWords[randomNumber]) == 0)
            {
                printf("Correct\n");
                break;
            }
            else
            {
                printf("Incorrect\n");
            }
            i++;
        }
    }
    return 0;
}
