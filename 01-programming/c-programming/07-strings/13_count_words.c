// count the number of words in a sentence
#include<stdio.h>

int main()
{
    char str[100];
    int i, words = 0, flag = 0;

    printf("Enter a sentence: ");
    fgets(str, 100, stdin);

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
            flag = 0;
        else if(flag == 0)
        {
            flag = 1;
            words++;
        }
    }

    printf("Number of words = %d\n", words);
    return 0;
}
