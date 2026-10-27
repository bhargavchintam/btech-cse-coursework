// first non-repeating character in a string using hashing
#include<stdio.h>
#define ASCII 256

int main()
{
    char str[100];
    int count[ASCII] = {0};
    int i;
    printf("Enter a string: ");
    scanf("%s", str);
    // hash each character by its ascii code and count it
    for(i = 0; str[i] != '\0'; i++)
        count[(int)str[i]]++;
    for(i = 0; str[i] != '\0'; i++)
    {
        if(count[(int)str[i]] == 1)
        {
            printf("First non-repeating character = %c\n", str[i]);
            return 0;
        }
    }
    printf("No non-repeating character\n");
    return 0;
}
