// pascals triangle
#include<stdio.h>

int main() {
    int i, j, n, c;
    printf("Enter the number of rows : ");
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        c = 1;
        for(j=0; j<=i; j++) {
            printf("%d ", c);
            c = c * (i - j) / (j + 1);
        }
        printf("\n");
    }
    return 0;
}
