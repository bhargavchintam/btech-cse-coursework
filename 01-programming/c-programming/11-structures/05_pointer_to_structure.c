#include<stdio.h>

struct student {
    char name[30];
    int roll;
    float marks;
};

int main() {
    struct student s;
    struct student *p = &s;

    printf("Enter name roll marks : ");
    scanf("%s %d %f", p->name, &p->roll, &p->marks);

    printf("Name  : %s\n", p->name);
    printf("Roll  : %d\n", p->roll);
    printf("Marks : %.2f\n", p->marks);

    return 0;
}
