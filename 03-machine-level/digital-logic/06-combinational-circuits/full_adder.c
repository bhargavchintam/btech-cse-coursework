// full adder truth table
#include<stdio.h>

int main()
{
    int a, b, cin, sum, cout;
    printf("A B Cin | Sum Cout\n");
    for(a = 0; a <= 1; a++)
        for(b = 0; b <= 1; b++)
            for(cin = 0; cin <= 1; cin++)
            {
                sum  = a ^ b ^ cin;
                cout = (a & b) | (b & cin) | (a & cin);
                printf("%d %d  %d  |  %d   %d\n", a, b, cin, sum, cout);
            }
    return 0;
}
