/* Bindu Bhargava
   19-11-17 */
#include<stdio.h>

int main() {
    char a[100], b[100];
    int i = 0, j = 0;

    printf("Enter first string: ");
    scanf("%s", a);
    printf("Enter second string: ");
    scanf("%s", b);

    while(a[i] != '\0')
        i++;

    while(b[j] != '\0') {
        a[i] = b[j];
        i++;
        j++;
    }
    a[i] = '\0';

    printf("After concatenation = %s\n", a);
    return 0;
}
