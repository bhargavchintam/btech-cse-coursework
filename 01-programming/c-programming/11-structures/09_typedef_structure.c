/* Bindu Bhargava
   19-11-17 */
#include<stdio.h>

typedef struct {
    char name[30];
    int roll;
    float marks;
} Student;

int main()
{
    Student s;

    printf("Enter name roll marks : ");
    scanf("%s %d %f", s.name, &s.roll, &s.marks);

    printf("Name  : %s\n", s.name);
    printf("Roll  : %d\n", s.roll);
    printf("Marks : %.2f\n", s.marks);

    return 0;
}
