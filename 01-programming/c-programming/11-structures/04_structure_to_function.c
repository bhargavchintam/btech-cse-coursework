// passing a structure to function by value
#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

void display(struct student s)
{
    printf("Name  : %s\n", s.name);
    printf("Roll  : %d\n", s.roll);
    printf("Marks : %.2f\n", s.marks);
}

int main()
{
    struct student s;

    printf("Enter name roll marks : ");
    scanf("%s %d %f", s.name, &s.roll, &s.marks);

    display(s);

    return 0;
}
