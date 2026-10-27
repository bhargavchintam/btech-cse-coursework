#include<stdio.h>
#include<string.h>

void reverse(char s[], int i, int j)
{
    char t;
    if (i >= j)
        return;
    t = s[i];
    s[i] = s[j];
    s[j] = t;
    reverse(s, i + 1, j - 1);
}

int main()
{
    char s[100];
    printf("Enter a string: ");
    scanf("%s", s);
    reverse(s, 0, strlen(s) - 1);
    printf("Reversed: %s\n", s);
    return 0;
}
