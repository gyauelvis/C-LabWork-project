#include <stdio.h>
#include <stdlib.h>

int main()
{
    int userInput;
    int playAgain;
    int trial = 0;
    int attempts = 0;
    printf("\nRANDOM NUMBER GUESS\n");
    do
    {
        int answer = rand() % 10;
        printf("Enter a random number from 1 to 10\n");
        scanf("%d", &userInput);
        do
        {
            if (userInput == answer)
            {
                printf("That was a correct guess");
                trial = 0;
            }
            else if (userInput >= answer)
            {
                printf("\nWrong Guess, A bit Higher Decrease your Number \n");
                scanf("%d", &userInput);
                trial += 1;
            }
            else
            {
                printf("\n2Wrong Guess, A bit Lower Increase your Number \n");
                scanf("%d", &userInput);
                trial += 1;
            }
        } while (trial > 0 && trial < 3);
        printf("The answer was %d\n", answer);
        printf("\nPlay Again \n1-Yes\n2-No\n");
        scanf("%d", &playAgain);
        if (playAgain == 1)
        {
            attempts += 1;
        }
        else
        {
            attempts = 0;
        }
    } while (attempts > 0);
    return 0;
}