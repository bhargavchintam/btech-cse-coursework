// jk flip-flop simulation for a sequence of j,k inputs
#include<stdio.h>

int main()
{
    int n, i, j, k, q = 0;
    printf("Initial Q = 0\n");
    printf("How many clock pulses: ");
    scanf("%d", &n);
    printf("J K | Q\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &j, &k);
        if(j == 0 && k == 1) q = 0;
        else if(j == 1 && k == 0) q = 1;
        else if(j == 1 && k == 1) q = !q;   // toggle
        printf("%d %d | %d\n", j, k, q);
    }
    return 0;
}
