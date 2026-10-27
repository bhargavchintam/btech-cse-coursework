// nested structure - date inside employee
#include<stdio.h>

struct date {
    int dd, mm, yy;
};

struct employee {
    char name[30];
    int id;
    struct date doj;
};

int main()
{
    struct employee e;

    printf("Enter employee name : ");
    scanf("%s", e.name);
    printf("Enter id : ");
    scanf("%d", &e.id);
    printf("Enter date of joining (dd mm yy) : ");
    scanf("%d %d %d", &e.doj.dd, &e.doj.mm, &e.doj.yy);

    printf("Name : %s\n", e.name);
    printf("Id   : %d\n", e.id);
    printf("DOJ  : %d-%d-%d\n", e.doj.dd, e.doj.mm, e.doj.yy);

    return 0;
}
