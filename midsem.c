#include <stdio.h>
#include <stdlib.h>

int main()
{
    int order = 0;
    int costOfoods[] = {5, 6, 7, 8};
    int i;
    int total = 0;
    char flavourValue[6][15] = {"Vanilla", "Chocolate", "Strawberry", "Mango"};
    printf("\nWelcome to Gyau's Ice Cream Shop\nWhat would you like to order");
    do
    {
        char flavour[15];
        int new_flavour;
        printf("\n1-Vanilla\n2-Chocolate\n3-Strawberry\n4-Mango\n5-Enquiries\n");
        scanf("%s", &flavour);
        new_flavour = atoi(flavour);
        i = new_flavour - 1;
        switch (new_flavour)
        {
        case 1:
            printf("You chose the %s flavour and the cost is GHS%d", flavourValue[i], costOfoods[i]);
            total += costOfoods[i];
            break;
        case 2:
            printf("You chose the %s flavour and the cost is GHS%d", flavourValue[i], costOfoods[i]);
            total += costOfoods[i];
            break;
        case 3:
            printf("You chose the %s flavour and the cost is GHS%d", flavourValue[i], costOfoods[i]);
            total += costOfoods[i];
            break;
        case 4:
            printf("You chose the %s flavour and the cost is GHS%d", flavourValue[i], costOfoods[i]);
            total += costOfoods[i];
            break;
        default:
            printf("Our waiters will be with you very soon\n");
            break;
        }
        printf("\nWould you like anything else?\n1-Yes\n2-No\n");
        scanf("%d", &i);
        if (i == 1)
        {
            order += 1;
        }
        else
        {
            order = 0;
            printf("Thank you and the cost of your order is GHS%d", total);
        }
    } while (order > 0);
    return 0;
}