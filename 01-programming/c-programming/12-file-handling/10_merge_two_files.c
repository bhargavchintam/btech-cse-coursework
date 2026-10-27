// merge two files into a third file
#include<stdio.h>

int main()
{
    FILE *fp1, *fp2, *fp3;
    int ch;

    fp1 = fopen("file1.txt", "w");
    fprintf(fp1, "Content of the first file\n");
    fclose(fp1);

    fp2 = fopen("file2.txt", "w");
    fprintf(fp2, "Content of the second file\n");
    fclose(fp2);

    fp1 = fopen("file1.txt", "r");
    fp2 = fopen("file2.txt", "r");
    fp3 = fopen("merge.txt", "w");

    while((ch = fgetc(fp1)) != EOF)
        fputc(ch, fp3);
    while((ch = fgetc(fp2)) != EOF)
        fputc(ch, fp3);

    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    printf("Both files merged into merge.txt\n");

    return 0;
}
