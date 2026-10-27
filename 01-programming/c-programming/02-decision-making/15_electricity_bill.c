#include<stdio.h>
// electricity bill using slab rates
int main() {
    int units;
    float bill;
    printf("Enter units consumed: ");
    scanf("%d", &units);
    if(units <= 100)
        bill = units * 1.5;
    else if(units <= 200)
        bill = 100 * 1.5 + (units - 100) * 2.5;
    else if(units <= 300)
        bill = 100 * 1.5 + 100 * 2.5 + (units - 200) * 4.0;
    else
        bill = 100 * 1.5 + 100 * 2.5 + 100 * 4.0 + (units - 300) * 6.0;
    printf("Total bill = %f\n", bill);
    return 0;
}
