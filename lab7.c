#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numberOfStudents;
    int sum = 0;
    float mean = 0;
    printf("Number of Students: ");
    scanf("%d", &numberOfStudents);
    float marks[numberOfStudents];
    for (int i = 0; i < numberOfStudents; i++)
    {
        printf("Student %d: \t", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }
    mean = sum / numberOfStudents;
    printf("Mean: \t%f\n", mean);

    float temp = 0;

    for (int i = 0; i < numberOfStudents; i++)
    {
        for (int j = i + 1; j < numberOfStudents; j++)
        {
            if (marks[i] > marks[j])
            {
                temp = marks[i];
                marks[i] = marks[j];
                marks[j] = temp;
            }
        }
        printf("Student %d:\t%f\n", i + 1, marks[i]);
    }
}

// int main()
// {
//     // int numberOfStudents;
//     // int sum = 0;
//     // int mean;
//     // printf("Number of students in the class: ");
//     // scanf("%d", &numberOfStudents);
//     // int marks[numberOfStudents];
//     // for (int i = 0; i < numberOfStudents; i++)
//     // {
//     //     printf("Student %d\t: ", i + 1);
//     //     scanf("%d", &marks[i]);
//     //     sum += marks[i];
//     // }
//     // for (int i = 0; i < numberOfStudents; i++)
//     // {
//     //     printf("\nStudent %d\t: ", i + 1);
//     //     printf("%d", marks[i]);
//     // }
//     // printf("\nSum: %d\n", sum);
//     // mean = sum / numberOfStudents;
//     // printf("The mean value is: %d", mean);

//     // int temp = 0;

//     // for (int i = 0; i < numberOfStudents; i++)
//     // {
//     //     for (int j = i + 1; j < numberOfStudents; j++)
//     //     {
//     //         if (marks[i] > marks[j])
//     //         {
//     //             temp = marks[i];
//     //             marks[i] = marks[j];
//     //             marks[j] = temp;
//     //         }
//     //     }
//     // }
//     // for (int i = 0; i < numberOfStudents; i++)
//     // {
//     //     printf("\nStudent %d\t: ", i + 1);
//     //     printf("%d", marks[i]);
//     // }

//     float studentsResults[7][2] = {3,
//                                    57.45,
//                                    2,
//                                    69.29,
//                                    2,
//                                    71.32,
//                                    4,
//                                    65.05,
//                                    3,
//                                    75.67,
//                                    3,
//                                    48.65,
//                                    1,
//                                    88.21};
//     printf("Credit Hours\tScore\n");
//     for (int i = 0; i < 7; i++)
//     {
//         for (int j = 0; j < 2; j++)
//         {
//             printf("%.2f\t", studentsResults[i][j]);
//         }
//         printf("\n");
//     }

//     return 0;
// }