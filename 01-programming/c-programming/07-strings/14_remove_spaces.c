// remove all spaces from a string
#include<stdio.h>

int main() {
    char str[100], res[100];
    int i, j = 0;

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] != ' ') {
            res[j] = str[i];
            j++;
        }
    }
    res[j] = '\0';

    printf("String without spaces = %s", res);
    return 0;
}
