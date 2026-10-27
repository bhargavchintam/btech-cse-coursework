#include<stdio.h>

// sum of series 1 + 1/2 + 1/3 + ... + 1/n
int main() {
    int i, n;
    float sum = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        sum = sum + 1.0 / i;
    }
    printf("Sum = %f\n", sum);
    return 0;
}
