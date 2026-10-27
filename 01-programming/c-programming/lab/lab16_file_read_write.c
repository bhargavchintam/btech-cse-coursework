/* Lab Program 16
   Write n numbers to a file, read them back and print their sum.
   gcc lab16_file_read_write.c -o lab16  */

#include<stdio.h>

int main() {
    FILE *fp;
    int i, n, num, sum = 0;

    printf("How many numbers : ");
    scanf("%d", &n);

    fp = fopen("numbers.txt", "w");
    printf("Enter %d numbers\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }
    fclose(fp);

    fp = fopen("numbers.txt", "r");
    while(fscanf(fp, "%d", &num) != EOF)
        sum = sum + num;
    fclose(fp);

    printf("Sum of the numbers = %d\n", sum);
    return 0;
}
