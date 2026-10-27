/* Lab Program 13
   Find the length, reverse and palindrome status of a string without
   using string.h.
   gcc lab13_string_operations.c -o lab13  */

#include<stdio.h>

int main()
{
    char str[100], rev[100];
    int i, len = 0, flag = 1;

    printf("Enter a string : ");
    scanf("%s", str);

    while(str[len] != '\0')
        len++;

    for(i = 0; i < len; i++)
        rev[i] = str[len - 1 - i];
    rev[len] = '\0';        // dont forget the \0

    for(i = 0; i < len; i++)
    {
        if(str[i] != rev[i])
        {
            flag = 0;
            break;
        }
    }

    printf("Length = %d\n", len);
    printf("Reverse = %s\n", rev);
    if(flag)
        printf("It is a palindrome\n");
    else
        printf("It is not a palindrome\n");
    return 0;
}
