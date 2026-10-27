// count vowels consonants digits and spaces
#include<stdio.h>

int main()
{
    char str[100];
    int i, vowels = 0, cons = 0, digits = 0, spaces = 0;
    char ch;

    printf("Enter a sentence: ");
    fgets(str, 100, stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        if(ch >= 'A' && ch <= 'Z')
            ch = ch + 32;

        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            vowels++;
        else if(ch >= 'a' && ch <= 'z')
            cons++;
        else if(ch >= '0' && ch <= '9')
            digits++;
        else if(ch == ' ')
            spaces++;
    }

    printf("Vowels = %d\n", vowels);
    printf("Consonants = %d\n", cons);
    printf("Digits = %d\n", digits);
    printf("Spaces = %d\n", spaces);

    return 0;
}
