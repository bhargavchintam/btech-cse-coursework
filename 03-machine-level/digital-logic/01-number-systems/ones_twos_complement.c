// 1's and 2's complement of a binary number
#include<stdio.h>
#include<string.h>

int main()
{
    char b[33], one[33];
    int i, n, carry = 1;
    printf("Enter a binary number: ");
    scanf("%32s", b);
    n = strlen(b);
    for(i = 0; i < n; i++)
        one[i] = (b[i] == '0') ? '1' : '0';
    one[n] = '\0';
    printf("1's complement = %s\n", one);
    // add 1 for 2's complement
    for(i = n - 1; i >= 0; i--)
    {
        if(one[i] == '1' && carry == 1)
            one[i] = '0';
        else if(one[i] == '0' && carry == 1)
        {
            one[i] = '1';
            carry = 0;
        }
    }
    printf("2's complement = %s\n", one);
    return 0;
}
