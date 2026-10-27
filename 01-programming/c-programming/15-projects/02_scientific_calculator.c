// gcc 02_scientific_calculator.c -o scical -lm
#include<stdio.h>
#include<math.h>

int main()
{
    int choice;
    double a, b;

    while(1)
    {
        printf("\n1.Add\n2.Subtract\n3.Multiply\n4.Divide\n5.Square root\n");
        printf("6.Power\n7.Sin\n8.Cos\n9.Log\n10.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice == 10)
            break;

        switch(choice)
        {
            case 1:
                printf("Enter a and b: ");
                scanf("%lf %lf", &a, &b);
                printf("Sum = %.4lf\n", a + b);
                break;
            case 2:
                printf("Enter a and b: ");
                scanf("%lf %lf", &a, &b);
                printf("Difference = %.4lf\n", a - b);
                break;
            case 3:
                printf("Enter a and b: ");
                scanf("%lf %lf", &a, &b);
                printf("Product = %.4lf\n", a * b);
                break;
            case 4:
                printf("Enter a and b: ");
                scanf("%lf %lf", &a, &b);
                if(b != 0)
                    printf("Quotient = %.4lf\n", a / b);
                else
                    printf("Cannot divide by zero\n");
                break;
            case 5:
                printf("Enter a: ");
                scanf("%lf", &a);
                printf("sqrt = %.4lf\n", sqrt(a));
                break;
            case 6:
                printf("Enter a and b: ");
                scanf("%lf %lf", &a, &b);
                printf("%.2lf ^ %.2lf = %.4lf\n", a, b, pow(a, b));
                break;
            case 7:
                printf("Enter angle in radians: ");
                scanf("%lf", &a);
                printf("sin = %.4lf\n", sin(a));
                break;
            case 8:
                printf("Enter angle in radians: ");
                scanf("%lf", &a);
                printf("cos = %.4lf\n", cos(a));
                break;
            case 9:
                printf("Enter a: ");
                scanf("%lf", &a);
                printf("log = %.4lf\n", log(a));
                break;
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}
