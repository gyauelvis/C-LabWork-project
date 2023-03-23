#include <stdio.h>
#include <stdlib.h>

float balance = 5000;
float amountForTransaction = 0;
int amount;
int authenticate(int pin);

int requestAmount();
int deposit();
int transfer();
int withDraw(int amountForWithdrawal);

int main()
{
start:
    printf("WELCOME TO ABC BANK\nEnter your four digit pin\n");
    static int tries = 0;

    int pin = 0;
    scanf("%d", &pin);
menu:
    if (authenticate(pin) && tries < 4)
    {
        int menu_item;
        printf("Select an option\n1. Check Balance\n2. Withdrawal\n3. Deposit\n4. Transfer\n");
        scanf("%d", &menu_item);
        switch (menu_item)
        {
        case 1:
            printf("%g\n", balance);
            break;
        case 2:
            withDraw(requestAmount());
            if (amount > balance)
            {
                printf("Insufficient Funds for the Transaction\n");
            }
            break;
        case 3:
            deposit();
            break;
        case 4:
            transfer();
            if (amountForTransaction > balance)
            {
                printf("Insufficient Funds for the Transaction\n");
            }
        }
    }
    else if (authenticate(pin) != 1 && tries < 4)
    {
        ++tries;
        printf("Invalid pin after %d tries\n", tries);
        goto start;
    }
    else
    {
        printf("Maximum Number of trials reached\nAccount has been locked\nYou're a thief\n");
        goto end;
    }
    int response;
    printf("Would you like to perform another transaction?\n1. Yes\n2. No\n");
    scanf("%d", &response);
    if (response == 1)
    {
        goto menu;
    }
end:
    printf("Thank you for banking with us\n");
    return 0;
}

int authenticate(int pin)
{
    int count = 0;
    if (pin == 0)
    {
        count = 1; // special case for zero
    }
    else
    {
        while (pin != 0)
        {
            count++;
            pin /= 10;
        }
    }
    if (count == 4)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int requestAmount()
{
    printf("Enter the amount of money for the transaction\n");
    scanf("%f", &amountForTransaction);
    return amountForTransaction;
}
int deposit()
{
    printf("Enter the amount of money for the transaction\n");
    scanf("%f", &amountForTransaction);
    balance += amountForTransaction;
    return balance;
}

int withDraw(int amountForWithdrawal)
{
    amount = amountForWithdrawal;
    if (balance >= amountForWithdrawal)
    {
        balance -= amountForWithdrawal;
    }

    return balance;
}
int transfer()
{
    int accountNumber;
    printf("Receipient Account Number: ");
    scanf("%d", &accountNumber);
    printf("\nAmount: ");
    scanf("%f", &amountForTransaction);
    if (balance >= amountForTransaction)
    {
        balance = balance - amountForTransaction;
    }

    return balance;
}
