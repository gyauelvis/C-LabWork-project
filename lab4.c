#include <stdio.h>
int main()
{
    int i;
    int q;
    int j;
    int anythingElse;
    char flavourValue[6][11] = {
        "Vanilla",
        "Strawberry",
        "Chocolate",
        "Mango"};
    char sizeValue[5][8] = {"small", "large"};
    int costOfSmallFlavour[] = {
        5,
        5,
        6,
        7};
    int costOfLargeFlavour[] = {
        8,
        8,
        9,
        10};
    char toppingValue[8][20] = {
        "Sprinkles", "Whipped cream", "Chopped Nuts", "Coconut Shavings"};
    int costOfTopping[] = {
        2, 3, 4, 5};
    int order = 0,
        time = 0;
    float cost = 0;
    printf("WELCOME TO FIIFI'S ICE CREAM SHOP\nWhat would you like to order?\n");
    do
    {
        int flavour = 0, topping = 0, size = 0;
        printf("1-Vanilla \n2-Strawberry\n3-Chocolate\n4-Mango\n5-Enquiries\n");
        scanf("%d", &flavour);
        printf("1-small\n2-large\n");
        scanf("%d", &size);
        i = flavour - 1;
        q = size - 1;
        if (flavour == 1 || flavour == 2 || flavour == 3 || flavour == 4)
        {
            if (size == 1 || size == 2)
            {
                printf("You chose the %s %s flavour\n", sizeValue[q], flavourValue[i]);
                if (size == 1)
                {
                    cost += costOfSmallFlavour[i];
                    time = time + 2;
                }
                else if (size == 2)
                {
                    cost += costOfLargeFlavour[i];
                    time = time + 2;
                }
            }
            else
            {
                printf("Invalid Entry\n");
            }
        }
        else if (flavour == 5)
        {
            printf("A customer service agent will be with you soon\n");
        }
        else
        {
            printf("Invalid flavour entry\n");
        };
        int toppings = 0;
        do
        {
            printf("1-Sprinkles \n 2-Whipped cream\n 3-Chopped Nuts \n 4-Coconut Shavings \n 5-No\n");
            scanf("%d", &topping);

            if (topping == 1 || topping == 2 || topping == 3 || topping == 4)
            {
                j = topping - 1;
                printf("You chose the %s topping", toppingValue[j]);
                cost += costOfTopping[j];
                time = time + 3;
                toppings++;
            }
            else if (topping == 5)
            {
                toppings = 0;
            }
            else
            {
                printf("Invalid Toppings Entry\n");
            };
            printf("Would you like anything else \? \n 1-Yes 2-No \n");
            scanf("%d", &anythingElse);
            if (anythingElse == 1)
            {
                order++;
            }
            else
            {
                order = 0;
                printf("Total Cost: %f", cost);
                printf("Waiting Time: %d", time);
            };
            printf("Kindly Wait for your order");
        } while (toppings > 0);
    } while (order > 0);

    return 0;
}
