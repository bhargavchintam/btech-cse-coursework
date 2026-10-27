// traverse array using pointer without index
#include<stdio.h>

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int *p;
    for(p = arr; p < arr + 5; p++)
        printf("%d ", *p);
    printf("\n");
    return 0;
}
