#include<stdio.h>

// same task using while and do-while
int main() {
    int i, n;
    printf("Enter n: ");
    scanf("%d", &n);

    printf("Using while loop\n");
    i = 1;
    while(i <= n) {
        printf("%d ", i);
        i++;
    }
    printf("\n");

    printf("Using do-while loop\n");
    i = 1;
    do {
        printf("%d ", i);
        i++;
    } while(i <= n);
    printf("\n");

    return 0;
}
