// all permutations of a string, swap based
#include<stdio.h>
#include<string.h>

void swap(char *a, char *b)
{
    char t = *a;
    *a = *b;
    *b = t;
}

void permute(char s[], int l, int r)
{
    int i;
    if (l == r) {
        printf("%s\n", s);
        return;
    }
    for (i = l; i <= r; i++) {
        swap(&s[l], &s[i]);
        permute(s, l + 1, r);
        swap(&s[l], &s[i]);
    }
}

int main()
{
    char s[20];
    printf("Enter a string: ");
    scanf("%s", s);
    permute(s, 0, strlen(s) - 1);
    return 0;
}
