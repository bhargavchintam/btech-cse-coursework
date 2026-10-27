// program to store and print student details using structure
#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

int main()
{
    struct student s;

    printf("Enter name : ");
    scanf("%s", s.name);
    printf("Enter roll : ");
    scanf("%d", &s.roll);
    printf("Enter marks : ");
    scanf("%f", &s.marks);

    printf("Name  : %s\n", s.name);
    printf("Roll  : %d\n", s.roll);
    printf("Marks : %.2f\n", s.marks);

    return 0;
}
