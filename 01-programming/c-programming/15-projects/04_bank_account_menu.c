// gcc 04_bank_account_menu.c -o bank
#include<stdio.h>

int main()
{
    float balance = 0, amount;
    int choice, i, count = 0;
    float history[100];

    while(1)
    {
        printf("\n1.Deposit\n2.Withdraw\n3.Balance\n4.Mini statement\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance += amount;
                history[count++] = amount;
                printf("Deposited. Balance = %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                if(amount > balance)
                    printf("Insufficient balance\n");
                else
                {
                    balance -= amount;
                    history[count++] = -amount;
                    printf("Withdrawn. Balance = %.2f\n", balance);
                }
                break;

            case 3:
                printf("Balance = %.2f\n", balance);
                break;

            case 4:
                printf("Mini statement:\n");
                for(i = 0; i < count; i++)
                {
                    if(history[i] < 0)
                        printf("Withdraw  %.2f\n", -history[i]);
                    else
                        printf("Deposit   %.2f\n", history[i]);
                }
                break;

            case 5:
                return 0;

            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
