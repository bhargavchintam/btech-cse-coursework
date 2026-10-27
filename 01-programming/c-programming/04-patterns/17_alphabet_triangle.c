// alphabet triangle
#include<stdio.h>

int main() {
    int i, j, n;
    printf("Enter the number of rows : ");
    scanf("%d", &n);
    for(i=1; i<=n; i++) {
        for(j=0; j<i; j++)
            printf("%c ", 'A' + j);
        printf("\n");
    }
    return 0;
}
