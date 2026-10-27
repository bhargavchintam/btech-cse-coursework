/* Bindu Bhargava
   26-11-17 */
// store n student records in a file then read them back
#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

int main()
{
    FILE *fp;
    struct student s;
    int i, n;

    printf("Enter number of students : ");
    scanf("%d", &n);

    fp = fopen("students.dat", "wb");
    for(i = 0; i < n; i++)
    {
        printf("Enter name roll marks : ");
        scanf("%s %d %f", s.name, &s.roll, &s.marks);
        fwrite(&s, sizeof(s), 1, fp);
    }
    fclose(fp);

    fp = fopen("students.dat", "rb");
    printf("\nRecords in file :\n");
    while(fread(&s, sizeof(s), 1, fp) == 1)
        printf("%s\t%d\t%.2f\n", s.name, s.roll, s.marks);
    fclose(fp);

    return 0;
}
