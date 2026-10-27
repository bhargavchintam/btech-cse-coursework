// sort an array of strings alphabetically using strcmp
#include<stdio.h>
#include<string.h>

int main() {
    char s[10][20] = {"banana", "apple", "cherry", "mango", "date", "fig"};
    char temp[20];
    int n = 6, i, j;

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - 1 - i; j++) {
            if(strcmp(s[j], s[j + 1]) > 0) {
                strcpy(temp, s[j]);
                strcpy(s[j], s[j + 1]);
                strcpy(s[j + 1], temp);
            }
        }
    }

    printf("Sorted:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", s[i]);
    return 0;
}
