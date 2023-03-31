#include <stdio.h>
int arr[2][3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18};
int main()
{
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 3; j++)
        {

            for (int k = 0; k < 3; k++)
            {
                printf("%d \t", arr[i][j][k]);
            }
            printf("\n");
        }
    }
}