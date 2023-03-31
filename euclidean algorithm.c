#include <stdio.h>
#include <stdlib.h>

int main()
{
    int fNumber = 102;

    // Finding the number of digits in a number
    int count = 0;

    while (fNumber != 0)
    {
        fNumber %= 10;
        count++;
    }
    printf("%d", count);
}