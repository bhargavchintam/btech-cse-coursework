// check whether two strings are anagram
#include<stdio.h>
#include<string.h>

int main()
{
    char a[100], b[100];
    int i, flag = 1;
    int count1[256] = {0}, count2[256] = {0};

    printf("Enter first string: ");
    scanf("%s", a);
    printf("Enter second string: ");
    scanf("%s", b);

    if(strlen(a) != strlen(b))
        flag = 0;
    else
    {
        for(i = 0; a[i] != '\0'; i++)
            count1[(int)a[i]]++;
        for(i = 0; b[i] != '\0'; i++)
            count2[(int)b[i]]++;

        for(i = 0; i < 256; i++)
        {
            if(count1[i] != count2[i])
            {
                flag = 0;
                break;
            }
        }
    }

    if(flag == 1)
        printf("The two strings are anagram\n");
    else
        printf("The two strings are not anagram\n");

    return 0;
}
