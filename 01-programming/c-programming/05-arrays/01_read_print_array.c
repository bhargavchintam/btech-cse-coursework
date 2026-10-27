/* Bindu Bhargava
   21-11-17 */
// program to read and print an array
#include<stdio.h>
int main()
{
    int a[50], n, i;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements\n", n);
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("The array is\n");
    for(i=0;i<n;i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
