#include<stdio.h>
int main()
{
    float cp, sp;
    printf("Enter cost price: ");
    scanf("%f", &cp);
    printf("Enter selling price: ");
    scanf("%f", &sp);
    if(sp > cp)
        printf("Profit = %f\n", sp - cp);
    else if(cp > sp)
        printf("Loss = %f\n", cp - sp);
    else
        printf("No profit no loss\n");
    return 0;
}
