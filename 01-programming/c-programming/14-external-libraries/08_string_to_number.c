// gcc 08_string_to_number.c -o strnum
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <number>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    double d = atof(argv[1]);
    long l = strtol(argv[1], NULL, 10);

    printf("atoi   = %d\n", n);
    printf("atof   = %.4f\n", d);
    printf("strtol = %ld\n", l);
    return 0;
}
