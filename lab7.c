#include <stdio.h>
#include <stdlib.h>

char grade(float result);

int main()
{
    // int numberOfStudents;
    // int sum = 0;
    // int mul = 1;
    // printf("Number of Students in the class:\t");
    // scanf("%d", &numberOfStudents);
    // float marks[numberOfStudents];
    // printf("\nStart Entering their marks\n");
    // for (int i = 0; i < numberOfStudents; i++)
    // {
    //     printf("Student %d: \t", i + 1);
    //     scanf("%f", &marks[i]);
    //     sum += marks[i];
    //     mul *= marks[i];
    // }
    // float temp = 0;
    // for (int i = 0; i < numberOfStudents; i++)
    // {
    //     for (int j = i + 1; j < numberOfStudents; j++)
    //     {
    //         if (marks[i] > marks[j])
    //         {
    //             temp = marks[i];
    //             marks[i] = marks[j];
    //             marks[j] = temp;
    //         }
    //     }
    //     printf("%f\n", marks[i]);
    // }
    float weightedsum = 0, totalcredits = 0;

    float studentResults[7][2] = {
        {3,
         57.45},
        {2,
         69.29},
        {2,
         71.32},
        {4,
         65.05},
        {3,
         75.67},
        {3,
         48.65},
        {1,
         88.21}};

    printf("\nCREDIT\t|SCORE\t|GRADE\t|\n");
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%.2f\t|", studentResults[i][j]);
            if (j % 2 == 1)
            {
                printf("%c \t|", grade(studentResults[i][j]));
                printf("\n\t|\t|\t|");
            }
        }
        printf("\n");
    }
    for (int i = 0; i < 7; i++)
    {

        weightedsum += studentResults[i][0] * studentResults[i][1];
        totalcredits += studentResults[i][0];
    }
    printf("Weighted Sum: %.2f\n", weightedsum);
    printf("Total Credit Hours: %.2f\n", totalcredits);
    float cwa = weightedsum / totalcredits;
    printf("CWA = %.2f\n", cwa);
    return 0;
}

char grade(float result)
{
    if (result <= 100 && result >= 70)
    {
        return 'A';
    }
    else if (result >= 60 && result < 70)
    {
        return 'B';
    }
    else if (result >= 55 && result < 60)
    {
        return 'C';
    }
    else if (result >= 50 && result < 55)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}
