#include<stdio.h>
#include<string.h>

int main()
{
    char a[100], b[100], c[200];
    int i, j, len;
    char temp;

    printf("Enter first string: ");
    scanf("%s", a);
    printf("Enter second string: ");
    scanf("%s", b);

    len = strlen(a);
    printf("Length of first string = %d\n", len);

    strcpy(c, a);
    printf("After strcpy c = %s\n", c);

    strcat(c, b);
    printf("After strcat c = %s\n", c);

    if(strcmp(a, b) == 0)
        printf("Both strings are equal\n");
    else
        printf("Both strings are not equal\n");

    for(i = 0, j = len - 1; i < j; i++, j--)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    printf("Reverse of first string = %s\n", a);   // strrev not available so reversed by hand

    return 0;
}
