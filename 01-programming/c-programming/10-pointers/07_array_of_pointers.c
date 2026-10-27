// array of pointers to strings
#include<stdio.h>

int main()
{
    char *names[4] = {"ram", "sita", "gita", "shyam"};
    int i;
    for(i = 0; i < 4; i++)
        printf("%s\n", names[i]);
    return 0;
}
