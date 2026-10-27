/* Bindu Bhargava
   19-11-17 */
#include<stdio.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int *p;
    p = arr;
    printf("%d\n", *p);
    p++;
    printf("%d\n", *p);
    p = p + 2;
    printf("%d\n", *p);
    printf("%d\n", *(arr + 4));
    return 0;
}
