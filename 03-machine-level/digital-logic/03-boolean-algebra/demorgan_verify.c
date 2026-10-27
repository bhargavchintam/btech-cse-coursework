// verify DeMorgan's theorems for all input combinations
#include<stdio.h>

int main()
{
    int a, b, ok = 1;
    printf("a b | (ab)'  a'+b' | (a+b)'  a'b'\n");
    for(a = 0; a <= 1; a++)
        for(b = 0; b <= 1; b++)
        {
            int l1 = !(a & b), r1 = (!a) | (!b);
            int l2 = !(a | b), r2 = (!a) & (!b);
            printf("%d %d |   %d      %d   |   %d      %d\n", a, b, l1, r1, l2, r2);
            if(l1 != r1 || l2 != r2)
                ok = 0;
        }
    printf(ok ? "both theorems verified\n" : "mismatch found\n");
    return 0;
}
