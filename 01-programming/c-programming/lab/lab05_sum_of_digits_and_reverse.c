/* Lab Program 5
   Find the sum of digits and the reverse of a given number.
   gcc lab05_sum_of_digits_and_reverse.c -o lab05  */

#include<stdio.h>

int main() {
    int n, sum = 0, rev = 0, r, temp;
    printf("Enter a number : ");
    scanf("%d", &n);

    temp = n;
    while(temp > 0) {
        r = temp % 10;
        sum = sum + r;
        rev = rev * 10 + r;
        temp = temp / 10;
    }

    printf("Sum of digits = %d\n", sum);
    printf("Reverse = %d\n", rev);
    return 0;
}
