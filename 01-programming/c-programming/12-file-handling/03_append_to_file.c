#include<stdio.h>

int main()
{
    FILE *fp;
    fp = fopen("data.txt", "a");

    fprintf(fp, "This line is appended at the end\n");

    fclose(fp);
    printf("Text appended\n");

    return 0;
}
