/* Bindu Bhargava   05-09-18 */
#include<stdio.h>

int count = 0;

void hanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        count++;
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    hanoi(n - 1, from, aux, to);
    count++;
    printf("Move disk %d from %c to %c\n", n, from, to);
    hanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    printf("Total moves = %d\n", count);
    return 0;
}
