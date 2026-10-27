// null pointer
#include<stdio.h>

int main()
{
    int *p = NULL;
    if(p == NULL)
        printf("p is a null pointer\n");
    else
        printf("value = %d\n", *p);
    return 0;
}
