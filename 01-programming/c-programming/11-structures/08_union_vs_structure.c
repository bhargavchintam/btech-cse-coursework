// difference between structure and union
#include<stdio.h>

struct sdata {
    int i;
    float f;
    char ch;
};

union udata {
    int i;
    float f;
    char ch;
};

int main()
{
    struct sdata s;
    union udata u;

    printf("Size of structure = %lu\n", sizeof(s));
    printf("Size of union     = %lu\n", sizeof(u));

    s.i = 10;
    s.f = 2.5;
    s.ch = 'X';
    printf("\nStructure : %d %.1f %c\n", s.i, s.f, s.ch);

    u.i = 10;
    u.f = 2.5;
    u.ch = 'X';     // same memory, last write wins
    printf("Union     : %d %.1f %c\n", u.i, u.f, u.ch);

    return 0;
}
