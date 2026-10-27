// check whether a file opened properly
#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("nofile.txt", "r");

    if(fp == NULL)
    {
        printf("Error : could not open the file\n");
        exit(1);
    }

    printf("File opened successfully\n");
    fclose(fp);

    return 0;
}
