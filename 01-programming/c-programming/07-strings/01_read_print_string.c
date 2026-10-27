// scanf stops at a space but fgets reads the whole line
#include<stdio.h>

int main()
{
    char str[100], word[100];

    printf("Enter a sentence: ");
    fgets(str, 100, stdin);
    printf("fgets read: %s", str);

    printf("Enter a sentence again: ");
    scanf("%s", word);
    printf("scanf read only: %s\n", word);

    return 0;
}
