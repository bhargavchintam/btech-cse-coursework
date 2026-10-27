#include<stdio.h>

/* Bindu Bhargava
   19-11-17 */
int main() {
    int i, n, a = 0, b = 1, c;
    printf("Enter number of terms: ");
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
    return 0;
}
