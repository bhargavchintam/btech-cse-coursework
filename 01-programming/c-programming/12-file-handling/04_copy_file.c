// copy contents of one file to another character by character
#include<stdio.h>

int main()
{
    FILE *fp1, *fp2;
    int ch;

    fp1 = fopen("data.txt", "r");
    fp2 = fopen("copy.txt", "w");

    while((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch, fp2);
        //printf("%c", ch);
    }

    fclose(fp1);
    fclose(fp2);
    printf("File copied to copy.txt\n");

    return 0;
}
