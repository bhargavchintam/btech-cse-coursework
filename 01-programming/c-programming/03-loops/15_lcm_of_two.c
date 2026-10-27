#include<stdio.h>

int main() {
    int a, b, i = 1, lcm;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    while((a * i) % b != 0) {
        i++;
    }
    lcm = a * i;
    printf("LCM = %d\n", lcm);
    return 0;
}
