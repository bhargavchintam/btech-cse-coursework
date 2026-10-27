#include<stdio.h>
// swap two numbers without using temp
int main() {
    int a, b;
    printf("Enter a and b : ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("a = %d b = %d\n", a, b);
    return 0;
}
