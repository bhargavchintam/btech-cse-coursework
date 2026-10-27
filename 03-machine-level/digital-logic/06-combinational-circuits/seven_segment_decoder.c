// which segments a..g glow for a BCD digit (common cathode)
#include<stdio.h>

int main()
{
    // seg patterns a b c d e f g for 0..9
    int seg[10][7] = {
        {1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1},
        {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0},
        {1,1,1,1,1,1,1}, {1,1,1,1,0,1,1}
    };
    int n, i;
    char name[7] = {'a','b','c','d','e','f','g'};
    printf("Enter a BCD digit (0-9): ");
    scanf("%d", &n);
    if(n < 0 || n > 9){ printf("not a BCD digit\n"); return 0; }
    printf("Segments ON: ");
    for(i = 0; i < 7; i++)
        if(seg[n][i])
            printf("%c ", name[i]);
    printf("\n");
    return 0;
}
