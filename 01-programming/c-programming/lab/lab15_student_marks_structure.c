/* Lab Program 15
   Read details of n students into a structure, compute the average and
   print the topper.
   gcc lab15_student_marks_structure.c -o lab15  */

#include<stdio.h>

struct student
{
    char name[30];
    int marks;
};

int main()
{
    struct student s[50];
    int i, n, top = 0;
    float sum = 0, avg;

    printf("Enter number of students : ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter name and marks of student %d : ", i + 1);
        scanf("%s %d", s[i].name, &s[i].marks);
        sum = sum + s[i].marks;
    }

    avg = sum / n;

    for(i = 1; i < n; i++)
    {
        if(s[i].marks > s[top].marks)
            top = i;
    }

    printf("Average marks = %f\n", avg);
    printf("Topper is %s with %d marks\n", s[top].name, s[top].marks);
    return 0;
}
