// copy a string into another without strcpy
#include<stdio.h>

int main()
{
    char str[100], copy[100];
    int i = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while(str[i] != '\0')
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';    // dont forget the \0

    printf("Copied string = %s\n", copy);
    return 0;
}
