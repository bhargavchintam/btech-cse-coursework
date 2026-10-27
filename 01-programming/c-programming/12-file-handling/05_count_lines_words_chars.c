// count number of lines words and characters in a file
#include<stdio.h>

int main()
{
    FILE *fp;
    int ch;
    int lines = 0, words = 0, chars = 0;

    fp = fopen("data.txt", "r");

    while((ch = fgetc(fp)) != EOF)
    {
        chars++;
        if(ch == '\n')
            lines++;
        if(ch == ' ' || ch == '\n' || ch == '\t')
            words++;
    }

    fclose(fp);

    printf("Lines      = %d\n", lines);
    printf("Words      = %d\n", words);
    printf("Characters = %d\n", chars);

    return 0;
}
