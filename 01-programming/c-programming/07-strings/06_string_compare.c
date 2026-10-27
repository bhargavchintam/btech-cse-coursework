// compare two strings without strcmp
#include<stdio.h>

int main()
{
    char a[100], b[100];
    int i = 0;

    printf("Enter first string : ");
    scanf("%s", a);
    printf("Enter second string : ");
    scanf("%s", b);

    while(a[i] == b[i] && a[i] != '\0')
        i++;

    if(a[i] == b[i])
        printf("Both strings are equal\n");
    else if(a[i] > b[i])
        printf("First string is greater\n");
    else
        printf("Second string is greater\n");

    return 0;
}
