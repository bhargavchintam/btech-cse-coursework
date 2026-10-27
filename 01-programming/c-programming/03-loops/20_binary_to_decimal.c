#include<stdio.h>

int main() {
    int n, dec = 0, rem, base = 1;
    printf("Enter a binary number: ");
    scanf("%d", &n);
    while(n > 0) {
        rem = n % 10;
        dec = dec + rem * base;
        base = base * 2;
        n = n / 10;
    }
    printf("Decimal = %d\n", dec);
    return 0;
}
