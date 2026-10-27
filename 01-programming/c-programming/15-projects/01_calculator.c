// gcc 01_calculator.c -o calc
#include<stdio.h>

int main()
{
    int choice;
    float a, b;

    while(1)
    {
        printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Modulus\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 6)
        {
            printf("Exiting\n");
            break;
        }

        printf("Enter a and b: ");
        scanf("%f %f", &a, &b);

        switch(choice)
        {
            case 1:
                printf("Sum = %.2f\n", a + b);
                break;
            case 2:
                printf("Difference = %.2f\n", a - b);
                break;
            case 3:
                printf("Product = %.2f\n", a * b);
                break;
            case 4:
                if(b != 0)
                    printf("Quotient = %.2f\n", a / b);
                else
                    printf("Cannot divide by zero\n");
                break;
            case 5:
                printf("Remainder = %d\n", (int)a % (int)b);
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
