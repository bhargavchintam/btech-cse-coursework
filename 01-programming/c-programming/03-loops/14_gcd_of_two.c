#include<stdio.h>

// gcd using euclid method
int main() {
    int a, b, temp;
    printf("enter a and b\n");
    scanf("%d %d", &a, &b);
    while(b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD = %d\n", a);
    return 0;
}
