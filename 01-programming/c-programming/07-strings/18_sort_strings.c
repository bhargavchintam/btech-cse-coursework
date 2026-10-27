// sort an array of strings in alphabetical order
#include<stdio.h>
#include<string.h>

int main()
{
    char str[10][100], temp[100];
    int i, j, n;

    printf("Enter number of strings: ");
    scanf("%d", &n);

    printf("Enter %d strings:\n", n);
    for(i = 0; i < n; i++)
        scanf("%s", str[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(strcmp(str[j], str[j + 1]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }

    printf("Strings in sorted order:\n");
    for(i = 0; i < n; i++)
        printf("%s\n", str[i]);

    return 0;
}
