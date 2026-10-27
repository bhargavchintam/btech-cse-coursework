// frequency of each character in a string
#include<stdio.h>
#include<string.h>

int main()
{
    char str[100];
    int i, j, count, len;

    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);
    for(i = 0; i < len; i++)
    {
        count = 1;
        if(str[i] != ' ')
        {
            for(j = i + 1; j < len; j++)
            {
                if(str[i] == str[j])
                {
                    count++;
                    str[j] = ' ';    // mark as counted
                }
            }
            printf("%c occurs %d times\n", str[i], count);
        }
    }

    return 0;
}
