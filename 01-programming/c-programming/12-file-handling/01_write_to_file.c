// write some lines into a file
#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "w");

    fprintf(fp, "Hello World\n");
    fprintf(fp, "This is a file handling program\n");
    fprintf(fp, "Learning C\n");

    fclose(fp);
    printf("Data written to data.txt\n");

    return 0;
}
