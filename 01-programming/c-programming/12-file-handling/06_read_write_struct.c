#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

int main()
{
    FILE *fp;
    struct student s1, s2;

    printf("Enter name roll marks : ");
    scanf("%s %d %f", s1.name, &s1.roll, &s1.marks);

    fp = fopen("student.dat", "wb");
    fwrite(&s1, sizeof(s1), 1, fp);
    fclose(fp);

    fp = fopen("student.dat", "rb");
    fread(&s2, sizeof(s2), 1, fp);
    fclose(fp);

    printf("\nRead back from file :\n");
    printf("%s %d %.2f\n", s2.name, s2.roll, s2.marks);

    return 0;
}
