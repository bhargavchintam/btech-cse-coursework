#include<stdio.h>

int main()
{
    FILE *fp;
    long pos;
    int ch;

    fp = fopen("data.txt", "r");

    fseek(fp, 0, SEEK_END);
    pos = ftell(fp);
    printf("Size of file = %ld bytes\n", pos);

    fseek(fp, 0, SEEK_SET);
    ch = fgetc(fp);
    printf("First character = %c\n", ch);

    fseek(fp, 6, SEEK_SET);
    printf("Position after seek = %ld\n", ftell(fp));

    fclose(fp);
    return 0;
}
