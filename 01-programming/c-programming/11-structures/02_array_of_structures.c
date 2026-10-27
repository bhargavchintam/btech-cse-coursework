#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

int main()
{
    struct student s[50];
    int i, n;

    printf("Enter number of students : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter name roll marks : ");
        scanf("%s %d %f", s[i].name, &s[i].roll, &s[i].marks);
    }

    printf("\n");
    for(i = 0; i < n; i++)
    {
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].marks);
    }

    return 0;
}
